/*Задание 5. Часть 1.
* Дана строка длиной не более 100 символов. 
Удалить в ней все гласные буквы.
*/

#include <iostream>
#include <string>
using namespace std;


int main()
{
     setlocale (LC_ALL, "Russian");
     string s;
     cout << "Напишите что-нибудь на английской раскладке:" << "\n";
     getline(cin, s);
     cout << "\n";

     int num = s.length();
     if (num > 100)
     {
         cout << "Длина строки больше 100! Введите меньше."<<"\n";
         return 1;
     }

     s.erase(
         remove_if
         (
             s.begin(), s.end(),
             [](unsigned char p)
             {
                 return string("AaEeOoUuiIYy").find(p) != string::npos;   //string::npos -это константа, представляющая собой непозицию
             }
         ), s.end() );

     cout << "Без гласных: " << "\n";
     cout << s << "\n";

     return 0;
}


