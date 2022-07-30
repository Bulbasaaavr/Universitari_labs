/*Вариант 3. Часть 3.
* Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m <=100). Найти столбец
* содержащий наименьший элемент матрицы и заменить все отрицательные элементы
* этого столбца числом 0.
*/

#include<fstream>
#include <iostream>
#define N 100
#define M 100
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int matrix[N][M];
	int n, m, m1, stolb = 0;
	ifstream in("inc/input.txt");
	in >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			in >> matrix[i][j];
		}
	}
	// поиск мин. элемента
	int min = matrix[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (min > matrix[i][j])
			{
				min = matrix[i][j];
				stolb = j+1;
				m1 = j;
			}
		}
	}

	//Вывод
	ofstream out("inc/output.txt");
	for (int i = 0; i < n; i++) {
		if (matrix[i][m1] < 0) {
			matrix[i][m1] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			out << matrix[i][j] << " ";
		}
	}
	out << "Столбец с мин. значением = " << stolb<< "\n";
	return 0;
}
