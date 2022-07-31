/* Вариант 3.
1.	Реализуйте алгоритм бинарного поиска, о котором шла речь на лекции. Решите задачу выполнения M (0<M<10000) 
поисковых запросов над массивом из N (0<N<100000) элементов, используя проход по массиву циклом и бинарный поиск. 
Сравните время работы этих двух подходов.
2.	Найдите корень уравнения x - 10 = 0 на отрезке [0; +беск] с точностью до 10^-4 с помощью бисекции.
*/

#include <iostream>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int N = 100000;
const int Max = INT_MAX;


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

int Binary_Poisk(int mas[], int previous, int next, int key)
{
	if (key < mas[previous]) //Если ключ меньше первого элемента массива
		return 0;
	if (key == mas[previous]) // Ключ совпал с первым элементом
		return mas[previous];
	if (key > mas[next]) //Если ключ больше последнего элемента массива
		return 0;
	if (key == mas[next]) // Ключ совпал с последним элементом
		return mas[next];
	while (previous + 1 < next)
	{
		int c = (previous + next) / 2; // индекс середины
		if (key > mas[c])	// проверка какую часть нужно отбросить с поиска
			previous = c;
		else
			next = c;
	}
	if (key == mas[next])
		return next;
	else
		return 0;
}

double Function(double x) // f(x)=10  !f(c)-10!<eps - более точное условие вместо abs(x - next) < eps) 
{
	return x-10.0017;
}

double Bisection(double previous, double next)
{
	next = Max;
	double eps = 1e-4;
	while (1)
	{
		double x = (previous + next) / 2;
		if ((abs(x - previous) < eps) && (abs(x - next) < eps)) // разница с || ??? Более точный результат?
			return x;
		else if (Function(x) * Function(previous) > 0)
			previous = x;
		else
			next = x;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(NULL)); // Генератор случайных чисел(обнуление). 

	int mas[N];
	int a = 0;
	int b = N - 1;
	int key = 0;
	int previous = 0;
	int next = 1;
	int num = 0;

	for (int i = 0; i < N; i++)
	{
		mas[i] = i;
	}

	cout << "Введите ключ:  " << mas[0] << " <=  key < " << mas[N - 1] << endl;
	cin >> key;
	cout << endl;

	Timer t1;

	cout << Binary_Poisk(mas, a, b, key) << endl;
	cout << "Time_Binary: " << t1.elapsed() << endl;
	
	/*
	Timer t2;
	cout << Poisk(mas, num, key) << endl;
	cout << "Time_Poisk: " << t2.elapsed() << endl;
	*/

	cout << "x = " << Bisection(previous, next) << endl;
	
	return 0;
}