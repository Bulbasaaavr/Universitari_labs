#pragma once
#include <iostream>
using namespace std;

namespace mt
{
	// MY_DEBUG 
	//#define MY_DEBUG 

	template<typename T, int N, int M>
	struct MasWrapper
	{
		T mas[N][M];
	};

	template<typename T, int N, int M>
	class Matrix
	{
	public:
		Matrix()
		{
#ifdef MY_DEBUG
			cout << "Constructor" << endl;
#endif
			m_n = N;
			m_m = M;
			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					m_mat[i][j] = 0;
		}

		Matrix(const T mas[N][M])
		{
#ifdef MY_DEBUG
			cout << "Constructor" << endl;
#endif
			m_n = N;
			m_m = M;
			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					m_mat[i][j] = mas[i][j];
		}

		// 
		Matrix(const MasWrapper<T, N, M>& mas)
		{
#ifdef MY_DEBUG
			cout << "Constructor" << endl;
#endif
			m_n = N;
			m_m = M;
			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					m_mat[i][j] = mas.mas[i][j];
		}

		//  
		Matrix(const Matrix<T, N, M>& mat)
		{
#ifdef MY_DEBUG
			cout << "Copy constructor" << endl;
#endif

			m_n = mat.m_n;
			m_m = mat.m_m;

			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					m_mat[i][j] = mat.m_mat[i][j];
		}

		int getN() const { return m_n; }
		int getM() const { return m_m; }
		T get(int i, int j) const { return m_mat[i][j]; }
		void set(int i, int j, T data) { m_mat[i][j] = data; }

		template<typename T, int N, int M>
		Matrix<T, N, M>& operator=(const Matrix<T, N, M>& mat)
		{
#ifdef MY_DEBUG
			cout << "Operator =" << endl;
#endif

			m_n = mat.getN();
			m_m = mat.getM();

			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					m_mat[i][j] = mat.get(i, j);

			return *this;
		}

		//  
		template<typename T, int N, int M>
		Matrix<T, N, M> operator+(const Matrix<T, N, M>& mat)
		{
#ifdef MY_DEBUG
			cout << "operator+" << endl;
#endif
			Matrix<T, N, M> tmp;
			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
			return tmp;
		}
 
		template<typename T, int N, int M>
		Matrix<T, N, M> operator*(const Matrix<T, N, M>& mat)
		{
#ifdef MY_DEBUG
			cout << "operator*" << endl;
#endif
			Matrix<T, N, M> tmp;

			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < mat.getM(); j++)
				{
					T sum = 0;
					for (int k = 0; k < m_m; k++)
						sum += m_mat[i][k] * mat.get(k, j);
					tmp.set(i, j, sum);
				}

			return tmp;
		}

		
		T det()
		{
			if (m_n == 2 && m_m == 2)
			{
				cout << " Матрица 2x2" << endl;
				int det = m_mat[0][0] * m_mat[1][1] - m_mat[0][1] * m_mat[1][0];
				return det;
			}

			if (m_n == 3 && m_m == 3)
			{
				cout << " Матрица 3x3" << endl;
				int det = m_mat[0][0] * m_mat[1][1] * m_mat[2][2] + m_mat[0][1] * m_mat[1][2] * m_mat[2][0]
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

		//  
		Matrix<T, N, M> inv()
		{
			Matrix<T, N, M> tmp;

			// 
			double d = det();
			if (d == 0)
				throw std::exception("Zero determinant!");

			cout << "After throw exception in inv function!" << endl;

			if ((m_n == 2 && m_m == 2) || (m_n == 3 && m_m == 3))
			{
				if (d == 0)
				{
					cout << "Определитель равен нулю" << endl;

				}
				else
				{
					if (m_n == 2)
					{
						tmp.m_mat[0][0] = m_mat[1][1] / d;
						tmp.m_mat[0][1] = -m_mat[0][1] / d;
						tmp.m_mat[1][0] = -m_mat[1][0] / d;
						tmp.m_mat[1][1] = m_mat[0][0] / d;
						return tmp;
					}
					if (m_n == 3)
					{
						tmp.m_mat[0][0] = (m_mat[1][1] * m_mat[2][2] - m_mat[2][1] * m_mat[1][2]) / d;
						tmp.m_mat[1][0] = -(m_mat[1][0] * m_mat[2][2] - m_mat[2][0] * m_mat[1][2]) / d;
						tmp.m_mat[2][0] = (m_mat[1][0] * m_mat[2][1] - m_mat[2][0] * m_mat[1][1]) / d;
						tmp.m_mat[0][1] = -(m_mat[0][1] * m_mat[2][2] - m_mat[2][1] * m_mat[0][2]) / d;
						tmp.m_mat[1][1] = (m_mat[0][0] * m_mat[2][2] - m_mat[2][0] * m_mat[0][2]) / d;
						tmp.m_mat[2][1] = -(m_mat[0][0] * m_mat[2][1] - m_mat[2][0] * m_mat[0][1]) / d;
						tmp.m_mat[0][2] = (m_mat[0][1] * m_mat[1][2] - m_mat[1][1] * m_mat[0][2]) / d;
						tmp.m_mat[1][2] = -(m_mat[0][0] * m_mat[1][2] - m_mat[1][0] * m_mat[0][2]) / d;
						tmp.m_mat[2][2] = (m_mat[0][0] * m_mat[1][1] - m_mat[1][0] * m_mat[0][1]) / d;
						return tmp;
					}
				}
			}
			else
			{
				cout << "Ошибка" << endl;
			}
			return tmp;
		}


		Matrix<T, M, N> transp()
		{
			
			Matrix<int, M, N> tmp;
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < N; j++)
				{
					tmp.m_mat[i][j] = m_mat[j][i];
				}
			}
			return tmp;
		}
	 
		~Matrix()
		{
#ifdef MY_DEBUG
			cout << "Destructor" << endl;
#endif
		}

		// friend -      private / 
		template<typename T, int N, int M>
		friend istream& operator>>(istream& os, Matrix<T, N, M>& mat);

		template<typename T, int N, int M>
		friend ostream& operator<<(ostream& os, const Matrix<T, N, M>& mat);

	public:
		int m_n, m_m;
		T m_mat[N][M];
	};
 
	template<typename T, int N, int M>
	istream& operator>>(istream& in, Matrix<T, N, M>& mat)
	{
		for (int i = 0; i < mat.m_n; i++)
			for (int j = 0; j < mat.m_m; j++)
				in >> mat.m_mat[i][j];
		return in;
	}
  
	template<typename T, int N, int M>
	ostream& operator<<(ostream& out, const Matrix<T, N, M>& mat)
	{
		out << "Matrix " << mat.m_n << "x" << mat.m_m << std::endl;
		for (int i = 0; i < mat.m_n; i++) {
			for (int j = 0; j < mat.m_m; j++)
				out << mat.m_mat[i][j] << " ";
			out << endl;
		}
		return out;
	}

	using Vec2i = Matrix<int, 2, 1>;	   
	using Vec2d = Matrix<double, 2, 1>;
	using Mat22i = Matrix<int, 2, 2>;
	using Mat22d = Matrix<double, 2, 2>;
	using Mat33i = Matrix<int, 3, 3>;
	using Mat33d = Matrix<double, 3, 3>;
}

