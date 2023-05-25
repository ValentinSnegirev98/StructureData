/*
Постановка задачи: 
•	Реализовать алгоритм дешифрования с помощью маршрутной перестановки, используя известный ключ. 
•	Реализовать чтение шифротекста из указанного файла.
*/

#include <iostream>
#include <string>
#include <Windows.h>
#pragma warning(disable:4996)
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char s[80];
    int key1[] = { 4, 6, 5, 3, 1, 2 }; // key1 - ключ по строкам. 
                                       // По условию, он известен.
    int key2[] = { 3, 2, 6, 1, 5, 4 }; // key2 - ключ по столбцам. 
                                       // По условию, его нужно подобрать самостоятельно.
    int size = sizeof(key1)/sizeof(int);
    char** text = new char* [size];
	
    unsigned int k = 0;

    // Чтение зашифрованного текста из файла
    FILE* f = fopen("C:\\Users\\Валентин С\\Documents\\decode.txt", "r");
    while (!feof(f))
    {
        fgets(s, strlen(s), f);
    }

    // Вывод зашифрованного текста
    cout << "Зашифрованный текст: ";
    cout << s;

    // Инициализация динамического массива
    for (unsigned int i = 0; i < size; i++)
    {
        text[i] = new char[size];
        for (unsigned int j = 0; j < size; j++)
        {
            text[i][j] = NULL;
        }
    }

    // Представление зашифрованного текста в виде таблицы.
    // Перестановка производится с помощью простой перестановки. Сначала по строкам 
    // в соответствие с ключом key1, потом по столбцам - key2
    for (unsigned int i = 0; i < size; i++)
    {
        for (unsigned int j = 0; j < size; j++)
        {
            if (k <= strlen(s))
            {
            text[key2[i] - 1][key1[j] - 1] = s[k++];
            }
        }
    }

    //Вывод расшифрованного текста
    cout << endl << "Расшифрованный текст: ";
    for (unsigned int i = 0; i < size; i++)
    {
        for (unsigned int j = 0; j < size; j++)
        {
            cout << text[j][i];
        }
    }
    return 0;
}

