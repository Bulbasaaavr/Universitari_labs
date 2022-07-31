#include <iostream>
#include <stdlib.h>
#include <cassert>
#include "Header.h"
using namespace std;

using mt::Mat22i;
using mt::Mat33i;
using mt::Mat33d;
using mt::Mat22d;
using mt::Vec2d;


int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "=== Test 0 ===" << endl;
	{
		Mat22d A({ {
			 {1,2},
			 {3,4}
		} });

		try
		{
			cout << A.inv() << endl;
			cout << "After inv in main" << endl;
		}
		catch (const std::bad_alloc& e)
		{
			cerr << "BAD ALLOC!!! " << e.what() << endl;
		}
		catch (const exception& e)
		{
			cerr << e.what() << endl;
		}
	}

	cout << "=== Test 1 ===" << endl;
	{
		Mat22d A({ {
			 {1,2},
			 {3,4}
		} });

		Vec2d X({ {
			{1},
			{1}
		} });

		auto B = A * X;

		assert(B.get(0, 0) == 3);
		assert(B.get(1, 0) == 7);
	}

	cout << "Done!" << endl;

	cout << "=== Test 2 ===" << endl;

	{
		Mat22d A({ {
			 {1,1},
			 {1,1}
		} });

		Vec2d X({ {
			{1},
			{1}
		} });

		auto B = A * X;

		assert(B.get(0, 0) == 2);
		assert(B.get(1, 0) == 2);
	}

	cout << "Done!" << endl;

	cout << "=== Test 3 ===" << endl;

	{
		Mat33i D({ {
			 {1,1,2},
			 {1,1,3},
			 {1,1,5},
		} });

		cout << D << endl;
	cout << D.det() << endl;
		assert(D.det() == 0);
	}

	cout << "=== Test 3.1 ===" << endl;

	{
		Mat22d S({ {
			 {1,2},
			 {1,3}
		} });

		cout << S << endl;
		cout << S.inv() << endl;
	}

	cout << "=== Test 3.2 ===" << endl;

	{
		mt::Matrix<int,2,3> T({{
			 {1,2,3},
			 {1,3,5}
		}});

		cout << T << endl;
		cout << T.transp() << endl;
	}

	return 0;
}

