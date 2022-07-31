/* Вариант 3.
Создайте односвязный список из 10000 целых чисел и реализуйте в нем операцию вставки элемента х в позицию k.                        
Выполните M = 1000 запросов на вставку. Реализуйте такую же операцию для массива. Сравните производительность.
*/ 

#include <iostream>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int N = 5;
const int M = 5;


class Timer
{
private:

	using clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, ratio<1> >;

	chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

struct T_list
{
	T_list* next;  //создание указателя для след элемента
	int number;
	T_list* q;
};

//функция добавления
void ADD(T_list* head, int number)
{
	T_list* p = new T_list; //новый элемент списка
	p->number = number;

	p->next = head->next;
	head->next = p;
}

//проверка списка
void PRINT(T_list* head)
{
	T_list* p = head->next;
	while (p != nullptr)
	{
		cout << p->number << " ";
		p = p->next;
	}
}

void CLEAR(T_list* head)
{
	T_list* tmp;
	T_list* p = head->next;
	while (p != nullptr)
	{
		tmp = p;
		p = p->next;
		delete tmp;
	}
}

void ADD_KEYS(T_list* head, int position, int k)
{
	
	T_list* tmp = head;
	T_list* q = new T_list;
	q->number = k;

	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
		if (tmp->number == position)
		{
			q->next = tmp->next;
			tmp->next = q;
		}	
	}

	/*	while (tmp->number != position)
	{
		tmp = tmp->next;
	}
	
	q->next = tmp->next;
	tmp->next = q; */
}

int main() 
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL)); // Генератор случайных чисел(обнуление). 

	//создание начала списка
	T_list* head = new T_list;  
	head->next = nullptr;
	
	int position=0;
	int x;
	int k=0;

	//заполнение списка рандомными числами
	for (int i = 0; i < M; i++)
	{
		x = rand()%10 +1;
		ADD(head, x);
	}

	PRINT(head);

	cout <<endl <<  "Введите  позицию  и key " << endl;
	cin >> position >> k;

	ADD_KEYS(head, position, k);

	cout << "========" << endl;

	PRINT(head);

	CLEAR(head);

	delete head;
	return 0;
}