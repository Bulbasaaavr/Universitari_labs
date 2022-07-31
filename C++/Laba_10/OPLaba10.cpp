/* Задание 1.3
* Даны 2 матрицы размером N*N. Посчитать их произведение
*/
#include <iostream>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

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

void Proizved(unsigned int n, int** a, int** b, int** c)
{
	for (int i = 0; i < n; i++)
	{
		c[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < n; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}

	cout << "Третья матрица: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << c[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(NULL)); // Генератор случайных чисел. 
	unsigned int n = 0;
	
	cout << "Введите число N: ";
	cin >> n; 
	cout << endl;

	if (n == 0) 
	{
		cout << "Такой матрицы нэт!" << endl;
		return 1;
	}
	int** a = new int* [n]; //Массив указателей
	int** b = new int* [n];
	int** c = new int* [n];
	
	cout << "Первая матрица: " << endl;
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n]; // Создание элементов

	}
 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 10; 
			cout << a[i][j] << " "; 
		}
	cout << endl;
	}

	cout << endl;
	cout << "Вторая матрица: " << endl;
	for (int i = 0; i < n; i++)
	{
		b[i] = new int[n]; 
	}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				b[i][j] = rand() % 10; 
				cout << b[i][j] << " "; 
			}
			cout << endl;
		}
	cout << endl;

	Timer t;

	Proizved(n, a, b, c);

	cout << "Time: " << t.elapsed() << endl;

	// Удаление массивов
	for (int i = 0; i < n; i++)
	{
		delete[]a[i];
		delete[]b[i];
	}
	delete[] a;
	delete[] b;

	return 0;
}