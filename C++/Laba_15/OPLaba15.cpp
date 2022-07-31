#include <iostream>
#include <stdlib.h>
using namespace std;

class Matrix
{
//Использование вне класса
public:
	//Конструктор
	Matrix(int n, int m)
	{
		cout << "CONSTR" << endl;
		m_n = n;
		m_m = m;
		m_mat = new int* [m_n];
		for (int i = 0; i < m_n; i++)
			m_mat[i] = new int[m_m];
	}

	//Оператор =
	Matrix& operator = (const Matrix& mat)
	{
		cout << "PRISV" << endl;
		m_n = mat.m_n;
		m_m = mat.m_m;
		m_mat = new int* [m_n];
		for (int i = 0; i < m_n; i++)
			m_mat[i] = new int[m_m];

		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
			{
				m_mat[i][j] = mat.m_mat[i][j];
			}
		}
		return *this;
	}

	//Оператор сложения
	Matrix operator + (const Matrix& mat)
	{
		cout << "PLUS" << endl;
		Matrix tmp(m_n, m_m);
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
		return tmp;
	}

	//Оператор вычитания
	Matrix operator - (const Matrix& mat)
	{
		cout << "MINUS" << endl;
		Matrix tmp(m_n, m_m);
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				tmp.m_mat[i][j] = m_mat[i][j] - mat.m_mat[i][j];
		return tmp;
	}

	//Оператор умножения
	Matrix operator * (const Matrix& mat)
	{
		cout << "PROI" << endl;
		Matrix tmp(m_n, m_m);
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
			{
				tmp.m_mat[i][j] = 0;
				for (int d = 0; d < m_m; d++)
				{
					tmp.m_mat[i][j] += m_mat[i][d] * mat.m_mat[d][j];
				}
			}
	return tmp;
	}

	// Нахождение определителя матрицы
	int Det()
	{
		if (m_n == 2 && m_m == 2)
		{
			cout << " Матрица 2x2" <<endl;
			int det = m_mat[0][0] * m_mat[1][1] - m_mat[0][1] * m_mat[1][0];
			return det;
		}

		if (m_n == 3 && m_m == 3)
		{
			cout << " Матрица 3x3" << endl;
			int det= m_mat[0][0] * m_mat[1][1] * m_mat[2][2] + m_mat[0][1] * m_mat[1][2] * m_mat[2][0]
				+ m_mat[1][0] * m_mat[2][1] * m_mat[0][2] - (m_mat[2][0] * m_mat[1][1] * m_mat[0][2] +
					m_mat[2][1] * m_mat[1][2] * m_mat[0][0] + m_mat[1][0] * m_mat[0][1] * m_mat[2][2]);
			return det;
		}
		else
			{
				cout << "Ошибка" << endl;
				return 2;
			}
	}

	// Нахождение обратной матрицы
	Matrix inversion()
	{
		int Det1 = Det();
		Matrix tmp(m_n, m_m);
		if ((m_n == 2 && m_m == 2) || (m_n == 3 && m_m == 3))
		{
			if (Det1 == 0)
			{
				cout << "Определитель равен нулю" << endl;

			}
			else
			{
				if (m_n == 2)
				{
					tmp.m_mat[0][0] = m_mat[1][1] / Det1;
					tmp.m_mat[0][1] = -m_mat[0][1] / Det1;
					tmp.m_mat[1][0] = -m_mat[1][0] / Det1;
					tmp.m_mat[1][1] = m_mat[0][0] / Det1;
					return tmp;
				}
				if (m_n == 3)
				{
					tmp.m_mat[0][0] = (m_mat[1][1] * m_mat[2][2] - m_mat[2][1] * m_mat[1][2]) / Det1;
					tmp.m_mat[1][0] = -(m_mat[1][0] * m_mat[2][2] - m_mat[2][0] * m_mat[1][2]) / Det1;
					tmp.m_mat[2][0] = (m_mat[1][0] * m_mat[2][1] - m_mat[2][0] * m_mat[1][1]) / Det1;
					tmp.m_mat[0][1] = -(m_mat[0][1] * m_mat[2][2] - m_mat[2][1] * m_mat[0][2]) / Det1;
					tmp.m_mat[1][1] = (m_mat[0][0] * m_mat[2][2] - m_mat[2][0] * m_mat[0][2]) / Det1;
					tmp.m_mat[2][1] = -(m_mat[0][0] * m_mat[2][1] - m_mat[2][0] * m_mat[0][1]) / Det1;
					tmp.m_mat[0][2] = (m_mat[0][1] * m_mat[1][2] - m_mat[1][1] * m_mat[0][2]) / Det1;
					tmp.m_mat[1][2] = -(m_mat[0][0] * m_mat[1][2] - m_mat[1][0] * m_mat[0][2]) / Det1;
					tmp.m_mat[2][2] = (m_mat[0][0] * m_mat[1][1] - m_mat[1][0] * m_mat[0][1]) / Det1;
					return tmp;
				}
			}
		}
		else
		{
			cout << "Ошибка" << endl;

		}
	}

	// Транспонирование матрицы 
	void transpon()
	{
		swap(m_n, m_m);
		Matrix tmp(m_n, m_m);
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
			{
				tmp.m_mat[i][j] = m_mat[j][i];
			}
		}
		m_mat = (int**)malloc(m_n * sizeof(int*));
		for (int i = 0; i < m_n; i++)
		{
			m_mat[i] = (int*)malloc(m_m * sizeof(int));
		}
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
			{
				m_mat[i][j] = tmp.m_mat[i][j];
			}
		}
	}

	//Деструктор
	~Matrix()
	{
		cout << "DESTR" << endl;
		for (int i = 0; i < m_n; i++)
			delete[] m_mat[i];
		delete m_mat;
	}

	//Друган для перегрузки оператора ввода
	friend istream& operator>>(istream& os, Matrix& mat);
	//Друган для перегрузки оператора вывода
	friend ostream& operator<<(ostream& os,const Matrix& mat);

//Использование внутри класса
private:
	int m_n, m_m;
	int** m_mat;
};

//Перегрузка оператора ввода
istream& operator>>(istream& in, Matrix& mat)
{
	for(int i=0; i<mat.m_n; i++)
		for (int j = 0; j < mat.m_m; j++)
			in >> mat.m_mat[i][j];
	return in;
}

//Перегрузка оператора вывода
ostream& operator<<(ostream& out, const Matrix& mat)
{
	out <<"Matrix " << mat.m_n <<"x"<<mat.m_m << endl;
	for (int i = 0; i < mat.m_n; i++){
		for (int j = 0; j < mat.m_m; j++)
			out << mat.m_mat[i][j]<< " ";
		out << endl;
	}
	return out;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int n, m = 0;
	int det = 0;

	cout << "Введите размер матрицы A: " << endl;
	cin >> n >> m;

	Matrix A(n,m);
	cin >> A;
	cout << A << endl;

	cout << "Введите размер матрицы B: " << endl;
	cin >> n >> m;
	
	Matrix B(n, m);
	cin >> B;
	cout << B << endl;

	Matrix C(n, m);
	C = A + B;
	cout << C << endl;

	Matrix D(n, m);
	D = A * B;
	cout << D << endl;

	det = A.Det();
	cout << "Определитель = " << det << endl;

	A.transpon();
	cout << A << endl;

	B.transpon();
	cout << B << endl;

	return 0;
}