/* Вариант 3. Часть 2
* Ввести последовательность натуральных чисел {Aj}j=1...n (n<=10000).
* Упорядочить последовательность по неубыванию первой цифры числа, числа с одинаковыми первыми цифрами дополнительно
упорядочить по неубыванию наибольшей цифры числа, числа с одинаковыми первыми цифрами и одинаковыми наибольшими цифрами
дополнительно упорядочить по неубыванию самого числа.
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
	int n, mas[N], firnum[N], maxnum[N], kol;
	cout << " Введите количество чисел: " << "\n";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << " Введите числа: " << "\n";
		cin >> mas[i];
		kol = mas[i];
		while (kol > 10)
		{
			firnum[i] = kol / 10;
			kol /= 10;
		}
		maxnum[i] = -1;
		kol = mas[i];
		while (kol > 0)
		{
			if (kol % 10 > maxnum[i])
			{
				maxnum[i] = kol % 10;
				
			}
			kol /= 10;
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((firnum[i] > firnum[j]) ||
				((firnum[i] == firnum[j]) && (maxnum[i] > maxnum[j])) ||
				((firnum[i] == firnum[j]) && (maxnum[i] == maxnum[j]) && (mas[i] > mas[j])))
			{
				swap(mas[i], mas[j]);
				swap(firnum[i], firnum[j]);
				swap(maxnum[i], maxnum[j]);
			}
		}
	}
		for (int i = 0; i < n; i++) 
		{
			cout << mas[i] << " ";
		}
	return 0;
}