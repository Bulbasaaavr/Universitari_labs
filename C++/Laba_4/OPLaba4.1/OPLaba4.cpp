/* Вариант 3. Часть 1
* Дана последовательность натуральных чисел {aj}j=1...n (n<=10000).
* Если в последовательности есть хотя бы одно число, сумма цифр которого равна 14, , упорядочить 
последовательность по невозрастанию последней цифры числа. 
*/ 

#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#define N 1000
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int mas[N], n, i, j;
	int sum, x;
	cout << " Введите количество чисел: " << "\n";
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cout << " Введите число: " << "\n";
		cin >> mas[i];
	}

	for (int i = 0; i < n; i++)
	{
		sum = 0;
		x = mas[i];
		while (x > 0)
		{
			sum += (mas[i] % 10);
			x /= 10;
		}
		if (sum == 14) 
		{
			for (i = 0; i < n ; i++)
			{
				for (j = i + 1; j < n; j++)
					if (mas[i] < mas[j])
					{
						swap(mas[i], mas[j]);
						
					}
			}
			
			for (i = 0; i < n; i++) {
				cout << mas[i] << " ";
			}
			return 2;
		}

		else {
			cout << "Нет чисел, сумма которых равна 14" << "\n";
			return 1;
		}
	}
	return 0;
}

