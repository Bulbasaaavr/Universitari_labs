/* Вариант 3.
1. Ввести натуральные числа A, B и C. Если A больше B и B больше C, то вывести A-B-C,
если B больше A и B кратно C, то вывести B/C+B-A, в остальных случаях вывести A+B+C.
2. Ввести цифру N, при помощи оператора switch вывести название цифры.
Предусмотреть обработку ошибочного ввода N.*/

#include <iostream>
using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");
	int  A, B, C, Rez1, Rez2, Rez3, Num;

	cout << "Часть 1."<< "\n";
	cout << "Через пробел введите переменные A, B, C:" << "\n";
	cin >> A >> B >> C;

	if (A <= 0 || B <= 0 || C <= 0) 
	{
		cout << "Ошибка!"<< "\n";
		return 4;
	}

	else if (A > B && B > C) 
	{
		Rez1 = A - B - C;
		cout << "(1 усл.) Результат " << Rez1 << "\n";
		return 1;
	}
	else if (B > A && B % C == 0 ) 
		{
			Rez2 = B / C + B - A;
			cout << "(2 усл.) Результат " << Rez2 << "\n";
			return 2;
		}
	else 
		{
			Rez3 = A + B + C;
			cout << "(3 усл.) Результат " << Rez3 << "\n";
			return 3;
		}
	/*
	cout << "Часть 2." << "\n";
	cout << "Введите число:" << "\n";
	cin >> Num;

	switch (Num) 
		{
		case 0:
		{
			cout << "Ноль " << "\n";
			break;
		}
		case 1:
		{
			cout << "Один " << "\n";
			break;
		}
		case 2:
		{
			cout << "Два " << "\n";
			break;
		}
		case 3:
		{
			cout << "Три " << "\n";
			break;
		}
		case 4:
		{
			cout << "Четыре " << "\n";
			break;
		}
		case 5:
		{
			cout << "Пять " << "\n";
			break;
		}
		case 6:
		{
			cout << "Шесть " << "\n";
			break;
		}
		case 7:
		{
			cout << "Семь " << "\n";
			break;
		}
		case 8:
		{
			cout << "Восемь " << "\n";
			break;
		}
		case 9:
		{
			cout << "Девять " << "\n";
			break;
		}
		default:
		{
			cout << "Число не соответствует условию! " << "\n";
			break;
		} 
	}
	*/
	return 0;
}