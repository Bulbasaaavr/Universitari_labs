/* Вариант 3.
Дана последовательность целых чисел {Aj}. Найти произведение чисел,
лежащих на отрезке [-2,20], наименьшее из таких чисел и номер этого
числа в последовательности.
*/

#include <iostream>
using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	int x;
	int n, nomm=0, p = 1;
	int min = INT_MAX;
	cout << "Введите количество чисел: " << "\n";
	cin >> n;

	if (n <= 0)
	{
		cout << "Ошибка!";
		return 1;
	}
	for (int i = 0; i < n; i++) {
		cout << "Введите число: " << "\n";
		cin >> x;
		if (x < -2 || x>20)  
		{
			continue;
		}
		p = p*x;

		if (x < min) {
			min = x;
			nomm = i+1;
		}
	}
	if (min == INT_MAX){
		cout << "Ошибка!";
	}
	else {
		cout << "Произведение равно " << p << "\n";
		cout << "Наименьшее число: " << min << "\n";
		cout << "Номер числа: " << nomm;
	}
	return 0;
}

