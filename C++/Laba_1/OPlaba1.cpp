/*
Вариант 3.
Написать программу, которая, используя минимальное количество оперативной памяти, рассчитает
периметр прямоугольника со сторонами A и B (0<A<20 и 0<B<20). A и B считать с клавиатуры.
*/

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    unsigned short int A, B;        // unsigned short int - 2 байта 
    unsigned int P;                 // unsigned int - 4 байта

    cout << "Введите число A:" << "\n";
    cin >> A;

    cout << "Введите число B:" << "\n";
    cin >> B;
    
    if (0 < A && A < 20 && 0 < B && B < 20) {
        P = (A + B) * 2;
        cout << "Периметр равен " << P << "\n";
    }

    else {
        cout << "Введённые числа не соответствуют условию!" << "\n";
        return 1;
    }

    return 0;  
}


/*
Для чисел с плавающей точкой:
unsigned short float A, B;
unsigned float P;
*/