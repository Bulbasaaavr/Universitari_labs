#include<fstream>
#include <iostream>
using namespace std;

struct Elements
{
    int data;           //Данные
    char data1;
    //Указатели на соседние вершины
    Elements* parent;
    Elements* left;
    Elements* right;
};

//Создание вершины
Elements* MAKE(int data, Elements* p)
{
    Elements* q = new Elements;     //Выделение памяти под вершину
    q->data = data;             
    q->left = nullptr;
    q->right = nullptr;
    q->parent = p;
    return q;
}

//Добавление элемента
void ADD(int data, Elements*& root)
{
    //если корневого элемента нет
    if (root == nullptr) {
        root = MAKE(data, nullptr);
        return;
    }

    Elements* v = root; //временный указатель на корневую вершину (в крайнем случае используется)
    while ((data < v->data && v->left != nullptr) || (data > v->data && v->right != nullptr))
        if (data < v->data)
            v = v->left;
        else
            v = v->right;
    //совпадение ключей
    if (data == v->data)        
        return;
    //создание вершины
    Elements* u = MAKE(data, v); 
    if (data < v->data)  //проверка на левый/правый потомка
        v->left = u;
    else
        v->right = u;
}

//Вывод дерева
void OUTPUT(Elements* v, int tabs=0)
{
	    if (v == nullptr)
        {
		    return;
        }
    tabs++;
	OUTPUT(v->left, tabs);
    for (int i = 0; i < tabs; i++)
    {
        cout << " ";
    }
	cout << v->data << endl;
	OUTPUT(v->right, tabs);
    tabs--;
    return;
}

//Поиск (1 часть)
void SEARCH1(int data, Elements* v, int number)
{
	ofstream out("output.txt");
	if (v == nullptr)
	{
        cout << "Нет в дереве:" << endl;
        cout << "n - " << data;
        out << "n - " << data;
	}
	else if (v->data == data)
	{
        cout << "Есть в дереве:" << endl;
        cout << data << " - " << number;
        out << data << " - " << number;
	}
	else if (data > v->data)
        SEARCH1(data, v->right, number + 1);
	else
        SEARCH1(data, v->left, number + 1);
}

//Поиск(2 часть)
Elements* SEARCH(int data, Elements* v)     
{
    if (v == nullptr)
        return v;
    if (v->data == data)
        return v;
    if (data < v->data)
        return SEARCH(data, v->left);
    else
        return SEARCH(data, v->right);
}

//Удаление
void DELETE(int data, Elements*& root)
{
    //Проверка на существование такого элемента  
    Elements* u = SEARCH(data, root);
    if (u == nullptr)
        return;

    //Удаление корня
    if (u->left == nullptr && u->right == nullptr && u == root)
    {
        delete root;
        root = nullptr;
        return;
    }
    //Если оба потомка присутствуют    
    if (u->left != nullptr && u->right != nullptr)
    {
        Elements* t = u->right;
        while (t->left != nullptr)
            t = t->left;
        u->data = t->data;
        u = t;
    }
    Elements* t;
    if (u->left == nullptr)
        t = u->right;
    else
        t = u->left;
    if (u->parent->left == u)
        u->parent->left = t;
    else
        u->parent->right = t;
    if (t != nullptr)
        t->parent = u->parent;
    delete u;
}

//Очистка  
void CLEAR(Elements*& v)
{
    if (v == nullptr)
        return;
    CLEAR(v->left);
 
    CLEAR(v->right);

    delete v;
    v = nullptr;
}

int main()
{
	setlocale(LC_ALL, "Russian");

    Elements* root = nullptr;   //корневой указатель
	ifstream in("input.txt");
	if (!in.is_open())
		cout << "Ошибка" << endl;
	else
	{
		cout << "Файл открыт" << endl;
		char a;     //символ
		int b;      //число
		while (!in.eof())
		{
			in >> a;
			in >> b;
			if (a == '+')
			{
				ADD(b, root);
				cout << "Добавлена " << b<<endl;
                cout << endl;
			}
			else if (a == '-')
			{
				DELETE(b, root);
				cout << "Убрана " << b << endl;
                cout << endl;
			}
			else if (a == '?')
			{
				SEARCH1(b, root, 1);
				cout << '\n';
                cout << endl;
			}
            else if (a == 'E')
            {
                break;
            }
		}
	}
	in.close();
    cout << "===============" << endl;
    OUTPUT(root);
	CLEAR(root);
    return 0;
}



