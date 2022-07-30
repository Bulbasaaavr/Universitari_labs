/* Задание 1.
* Вывести на экран таблицу значений функции y(x) для x, 
изменяющегося от a = 0 до b = 1,6 с шагом h = 0,1. (Суммы считать другим циклом)
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    float x, y, h;
        for (h = 0; h < 1.7; h +=0.1)
        {
            y = 0;
            n = 1;
            while (n < 21)
            {
                x = h;
                y = y + ((pow(x, n - 1)) / (sin(n * x)));
                n += 1;
            }
            cout << "x = " << x << "\t"; 
            cout << "y = " << y << "\n";
    }
    return 0;
}
