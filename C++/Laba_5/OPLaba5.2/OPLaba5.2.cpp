/*Задание 5. Часть 2. 5 Вариант.
* Дан файл, содержащий русский текст, размер текста не превышает 10 К байт.
Найти в тексте N (N ≤ 100) самых длинных слов, не содержащих одинаковых букв. Записать найденные
слова в текстовый файл в порядке возрастания длины. Все найденные слова должны быть разными.
Число N вводить из файла.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <ctype.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251); // для работы с русским текстом

    int y=0;
    string mas, t[1000], c[100];
    ifstream in("input.txt");
    while (!in.eof()) // пока не достигнут конец файла
    {
        in >> mas;
        //delete знаки
        for (int i = 0; i < mas.length(); i++) {
            if (ispunct(((unsigned char)mas[i])) != 0) {
                mas.erase(i);
            }
        }

    //проврка на одинаковые символы
        int ravno = 0;
        for (int i = 0; i < mas.length() - 1; i++) {
            for (int j = i + 1; j < mas.length(); j++) {
                if (mas[i] == mas[j]) {
                    ravno++;
                }
            }
        }
     if(ravno==0)
     {
       t[y] = mas;
        y++;
     } 
    }
    in.close();
    int Word = y, kek = y;
    for (int j = 0; j < Word; j++) {
        for (int i = j + 1; i < Word; i++) {
            if (t[j].length() < t[i].length()) {
                swap(t[j], t[i]);
            }
            if (t[j].length() == t[i].length()) {
                int count = 0;
                for (int n = 0; n < t[j].length(); n++) {
                    for (int m = 0; m < t[i].length(); m++) {
                        if (toupper(t[j][n]) == toupper(t[i][m])) {
                            count++;
                            if (count == t[j].length()) {
                                t[i].clear();
                                kek = kek - 1;
                            }
                        }
                    }
                }
            }
        }

    }
    ofstream out("output.txt");
    for (int i = 0; i < kek; i++) {
        c[i] = t[i];
        out << c[i] << " ";
    }
    out.close();
    return 0;
}
