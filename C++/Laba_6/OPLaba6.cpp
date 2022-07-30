/*Вариант 3. 
* альтернатива: найти определитель 3 порядка матрицы
*/

#include<fstream>
#include <iostream>
#define N 100
#define M 100
using namespace std;

void Read(int& n, int m, int matrix[N][M])
{
	ifstream in("input.txt");
	in >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			in >> matrix[i][j];
		}
	}

}


int MySort(int n, int m, int det,  int matrix[N][M])
{
	det = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			det = matrix[0][0] * matrix[1][1] * matrix[2][2]
				+ matrix[2][0] * matrix[0][1] * matrix[1][2]
				+ matrix[1][0] * matrix[2][1] * matrix[0][2]
				- matrix[2][0] * matrix[1][1] * matrix[0][2]
				- matrix[0][0] * matrix[2][1] * matrix[1][2]
				- matrix[1][0] * matrix[0][1] * matrix[2][2];
				}
			}
	return det;
		}

void Vivod(int n, int m, int det, int matrix[N][M])
{
	ofstream out("output.txt");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			out << matrix[i][j] << " ";
		}
	}
	out << "Определитель равен " << det;
}


int main()
{
	setlocale(LC_ALL, "Rus");
	int n=0,  m=0, matrix[N][M];
	int det = 0;
	Read(n, m, matrix);
	int detA = MySort(n, m,  det, matrix);
	Vivod(n, m, detA, matrix);

	return 0;
}

