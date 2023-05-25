/*
Постановка задачи: 
•	Реализовать представление больших чисел с помощью арифметики многократной точности. 
•	Реализовать перевод длинного целого двоичного числа в десятичную систему счисления.
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
// Числовая структура
struct BigInt
{
    char digits;
    int BASE = 2;
}p[500];

// Функция ввода
int enter(char* str)
{
    int j = 0;
    for (int i = strlen(str) - 1; i != -1; i--)
    {
        if (p[j].digits == 0 || p[j].digits == 1)
        {
            p[i].digits = *(str + j) - '0';
            j++;
        }
        else return -1;
    }
    return strlen(str);
}

// Функция перевода из 2-ичной СС в 10-ичную
void per10(int amount)
{
    double value = NULL;
    int base = p->BASE;
    for (int i = 0; i < amount; i++)
    {
        if (p[i].digits >= 0)
        {
            value += p[i].digits * pow(base, i);
        }
        else break;
    }
    cout << value;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    char *str=new char[10000];
    cout << "Введите число: ";
    cin >> str;
    int size = enter(str);
    if (size >= 0)
    {
      cout << "Перевод 2-ичного числа в 10-ичную систему счисления: "; per10(size);
    }
    else cout << "Введённое число не является двоичным! Перезапустите процесс, и повторите попытку! ";
    return 0;
}
