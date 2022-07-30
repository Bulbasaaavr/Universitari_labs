/*Часть 2.
*Дано n вещественных чисел, заканчивающихся 0. Вычислить разность между максимальным и минимальным из них. (Используя do while).
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");
	float x, raz, min = FLT_MAX, max = FLT_MIN;
	cout << "Введите числа: " << "\n";
	do {
		cin >> x;

		//(int)x == x  &&   abs(x)%10 == 0
		if (fmod(x, 10) == 0) {
			if (x < min)
			{
				min = x;
			}
			else
			{
				max = x;
			}
		}
	else {
			continue;
		}
	}
	while (x != 0);
		raz = max - min;
		cout << "Разность равна " << raz << "\n";
	return 0;
}




