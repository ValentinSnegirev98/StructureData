/*
Постановка задачи: 
•	Реализовать представление разреженной матрицы размером NxN или разреженного вектора размером N в виде массива (по форме Кнута);
•	Реализовать операцию считывания ненулевых элементов матрицы из файла;
•	Реализовать операцию получения значения элемента по номеру строки и номеру столбца;
•	Реализовать вывод полной матрицы на экран;
•	Реализовать операцию: каждый элемент строки матрицы разделить на соответствующий диагональный элемент. Если диагональный элемент равен нулю, то найти сумму элементов этой строки.
*/

#include <iostream>
#include <fstream>
#include<stdio.h>
#pragma warning (disable:4996)
using namespace std;

//Структура хранения массивов по форме Кнута//
struct SparseArr
{
    double value[50]; // массив ненулевых значений
    double row[50]; // массив индексов ненулевых строк
    double column[50]; // массив индексов ненулевых столбцов
};

//Функция инициализации//
void init(double*mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        mas[i] = NULL;
    }
}

//Функция чтения из файла//
int read(SparseArr* Arr, int size)
{
    int noZero = 0, count = 0;
    double** sparseArr = new double* [size];
    init(Arr->value, size);
    init(Arr->row, size);
    init(Arr->column, size);
    ifstream f("C:\\Users\\Валентин С\\Documents\\arr.txt");
    for (int i = 0; i < size; i++)
    {
        sparseArr[i] = new double[size];
        for (int j = 0; j < size; j++)
        {
            sparseArr[i][j] = NULL;
        }
    }
    if (f.is_open())
    {
        while (!f.eof())
        {
            for (int i = 0; i < size; i++)
            {
                        for (int j = 0; j < size; j++)
                {
                    if (f >> sparseArr[i][j])
                    {
                        count++;
                    }
                }
            }
        }
    }
    else
    {
        cout << "Файл не открыт!";
        return -1;
    }
    size = sqrt(count);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (sparseArr[i][j] != 0)
            {
                Arr->row[noZero] = i;
                Arr->column[noZero] = j;
                Arr->value[noZero] = sparseArr[i][j];
                noZero++;
            }
        }
    }
    delete[]sparseArr;
    return noZero;
}

// Функция поиска элементу по номеру строки и номеру столбца
double searchValue(int keyRow, int keyCol, SparseArr *Arr)
{
    for (int i = 0; i < 25; i++)
    {
        if (Arr->row[i] == keyRow && Arr->column[i] == keyCol)
        {
            return Arr->value[i];
        }
    }
    return 0;
}
//Функция вывода//
void print(SparseArr *Arr, int size)
{
    cout << "Вывод ненулевых элементов: ";
    for (int i = 0; i < size; i++)
    {
        cout << Arr->value [i] << " ";
    }
    cout << "\nВывод ненулевых строк:     ";
    for (int i = 0; i < size; i++)
    {
        cout << Arr->row[i] << " ";
    }
    cout << "\nВывод ненулевых столбцов:  ";
    for (int i = 0; i < size; i++)
    {
        cout << Arr->column[i] << " ";
    }
}

// Деление каждого элемента строки на соответствующий диагональный элемент. 
// Если диагональный элемент равен нулю, то находим сумму элементов этой строки. 
int dopOperation(SparseArr *Arr)
{
    double sum = 0;
    int k = 0;
    while (k < 25)
    {
        if (Arr->column[k] == Arr->row[k])
        {
            if (Arr->value[k] != 0)
            {
                cout << "\nDIAG = " << Arr->value[k] << endl;
                for (int i = 0; i < 25; i++)
                {
                    if (Arr->row[i] == Arr->row[k])
                    {
                        cout << "\nЗначение: " << Arr->value[i] << endl;
                        cout << "Номер строки: " << Arr->row[i] << endl;
                        cout << "Номер столбца: " << Arr->column[i] << endl;
                        cout << "Результат: " << Arr->value[i] / Arr->value[k] << endl;
                    }
                }
            }
            if(Arr->value[k] == 0)
            {
                for (int i = 0; i < 25; i++)
                {
                    if (Arr->row[i] != Arr->row[k])
                    {
                        cout << "\nЗначение: " << Arr->value[i] << endl;
                        cout << "Номер строки: " << Arr->row[i] << endl;
                        cout << "Номер столбца: " << Arr->column[i] << endl;
                        sum += Arr->value[i];
                    }
                }
                cout << "Summa: " << sum << endl;
            }
        }
        ++k;
    }
    return 0;
}
//Функция main//
int main()
{
    setlocale(LC_ALL, "Rus");
    int size = 8, search_r = 0, search_c = 0, row = 0;
    SparseArr* Arr = new SparseArr;
    int noZero = read(Arr, size);
    print(Arr, noZero);
    cout << endl;
    cout << "\n...Осуществляется поиск элемента по индексам строк и столбца...";
    cout << "\nВведите индекс строки: "; cin >> search_r; 
    cout << "\nВведите индекс столбца: "; cin >> search_c;
    cout << "\nИскомый элемент: " << searchValue(search_r, search_c, Arr) << endl;
    cout << "\n...Дополнительное задание...";
    dopOperation(Arr);
    return 0;
}
