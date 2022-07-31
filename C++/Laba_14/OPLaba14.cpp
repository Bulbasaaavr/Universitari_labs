/*Вариант 3.
Подобрать структуру для хранения данных, над которой преимущественно будут осуществляться операции поиска. 
Минимально - добавление и удаление.
*/

#include<fstream>
#include <iostream>
#include <vector>

using namespace std;

void ADD(vector<int>& data, int b) // c# ref в функциях
{
    int add = 0;
    cout << "Куда добавить: 1. Начало 2.Конец" << endl;
    cin >> add;
    if(add == 2)
    { 
        data.insert(data.end(), b);
    }
    else
    {
        data.insert(data.begin(), b);
    }
  
}

void OUTPUT(vector<int>data)
{
    cout << "===============" << endl;
    for (int i = 0; i < data.size(); i++)
        cout << data[i] << " ";
    cout << endl;
    cout << "===============" << endl;
}

void FIND(vector<int>data)
{
    int f1 = 0;
    cout << "Какое число найти?" << endl;
    cin >> f1;
    if (find(data.begin(), data.end(), f1) != data.end())
    {
        cout << "Число есть!" << endl;
    }
    else
        cout << "Числа нет!" << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(0);

    vector<int> data;
    int num1;      //число
    int kolb;    //кол-во чисел
    int input;
    int c=0, b = 0;
    
    cout << "Сколько элементов в векторе?" << endl;
    cin >> kolb;

    for (int i = 0; i < kolb; i++)
    {
        num1 = rand() % 10 + 1;
        data.push_back(num1);
    }

    OUTPUT(data);

    while (c != 3)
    { 
        cout << endl;
        cout << "Выберите действие:" << endl;
        cout << "1. Поиск элемента" << endl;
        cout << "2. Добавление элемента" << endl;
        cout << "3. Выход" << endl;
        cin >> input;
    
    switch (input)
    {
    case 1:
        FIND(data);
        break;
   case 2:
        cout << "Введите число: " << endl;
        cin >> b;
        ADD(data, b);
        OUTPUT(data);
        break;
    case 3:
        c = 3;
        cout << "Покеда" << endl;
        break;
    default:
        cout << "Введите число ещё раз!" << endl;
        break;
        }
    }
    cin.get();
    return 0;
}