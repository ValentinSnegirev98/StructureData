/*
Постановка задачи: 
•	Написать программу, обеспечивающую хранение и обработку информации. Для хранения данных использовать список на основе массива. Обеспечить выполнение основных операций при работе со списками:
1)	Добавление в список;
2)	Удаление из списка;
3)	Определение длины списка;
4)	Поиск элемента по значению;
5)	Изменение элемента списка;
6)	Вывод списка на экран.
Примечание: Диалог с пользователем программы должен осуществляться с помощью меню. 
•	Реализовать ведение списка забронированных и списка купленных билетов в кинозале кинотеатра. Билет содержит следующие сведения: номер ряда номер места. Забронированный билет – номер ряда, номер места, фамилию бронирующего. Обеспечить выполнение дополнительных операций:
1)	Покупка билета с учётом брони или сразу.
2)	Определение количества свободных мест в указанном ряду.
*/

#include <iostream>
#include <windows.h>
#include <string.h>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

int freeplace = 100;

// Список купленных билетов
struct list_buy
{
	int row;
	int place;
	list_buy operator = (list_buy a)
	{
		this->place = a.place;
		this->row = a.row;
		return *this;
	}
};
struct list_mass
{
	list_buy mass[100];
	int last;
};

// Список забронированных билетов
struct list_bron
{
	int row;
	int place;
	char second_name[20];
	char second_name1[20];
};
struct list_massbron
{
	list_bron mass[100];
	int last;
};
/*---------------------/ ФУНКЦИИ ДЛЯ ПОКУПКИ /--------------------*/
/*---------------------/ ФУНКЦИИ ДЛЯ ПРОВЕРКИ /--------------------*/
int finde(list_mass a, int row, int place)
{
	if (a.last != 0)
	{
		int i = 0;
		while (i != a.last + 1)
		{
			if (a.mass[i].place == place && a.mass[i].row == row)
			{
				return i;
			}
			i++;
		}
		return -1;
	}
	return -1;
}

// Поиск брони
int finde_bron(list_massbron* b, int row, int place)
{
	if (b->last != 0)
	{
		int i = 0;
		while (i != b->last + 1)
		{
			if (b->mass[i].place == place && b->mass[i].row == row)
			{
				return i;
			}
			i++;
		}
		return -1;
	}
	return -1;
}
/*------------------------ОСНОВНЫЕ ОПЕРАЦИИ СО СПИСКОМ------------------------------*/
// Добавление в список 
void add(list_mass& a, list_massbron* b)
{
	int row;
	int place;
	cout << "Укажите ряд: ";
	cin >> row;
	cout << "Укажите место: ";
	cin >> place;
	int result_search = finde(a, row, place);
	int result_search1 = finde_bron(b, row, place);
	if (result_search == -1 && result_search1 == -1)
	{
		a.mass[a.last + 1].place = place;
		a.mass[a.last + 1].row = row;
		a.last++;
		freeplace--;
		cout << "Успешно\n";
	}
	else
	{
		cout << "Билет уже куплен\n";
		return;
	}
}

// Удаление из списка
void delet(list_mass& a)
{
	int row;
	int place;
	cout << "Укажите ряд: ";
	cin >> row;
	cout << "Укажите место: ";
	cin >> place;
	int result_search = finde(a, row, place);
	if (result_search != -1)
	{
		a.mass[a.last + 1].place = 0;
		a.mass[a.last + 1].row = 0;
		a.last--;
		freeplace++;
		cout << "успешно!" << endl;
	}
	else
	{
		cout << "Билета нет\n";
		return;
	}
	for (int i = 0; i <= a.last; i++)
	{
		a.mass[i] = a.mass[i + 1];
	}
}

// Уточнение количества свободных мест
void show_buy(list_mass& a)
{
	for (int i = 1; i <= a.last; i++)
	{
		cout << "[" << i << "] " "Ряд: " << a.mass[i].row << " " << "Место: " << a.mass[i].place << " " << endl;
	}
	cout << "Количество свободных мест в зале: " << freeplace << endl;
}

// Поиск билета
void findshow(list_mass& a)
{
	int row;
	int place;
	cout << "Укажите ряд: ";
	cin >> row;
	cout << "Укажите место: ";
	cin >> place;
	int result_search = finde(a, row, place);
	if (result_search != -1)
	{
		cout << "Номер билета: " << result_search << endl;
	}
	else
	{
		cout << "Билета нет\n";
		return;
	}
}

// Изменение элемента списка
void edit(list_mass& a)
{
	int editelem;
	cout << "Укажите номер билета, который хотите изменить: ";
	cin >> editelem;
	for (int i = 1; i <= a.last; i++)
	{
		if (editelem == i)
		{
			int place;
			int row;
			cout << "Укажите новый ряд: ";
			cin >> row;
			cout << "Укажите новое место: ";
			cin >> place;
			a.mass[i].place = place;
			a.mass[i].row = row;
			cout << "Успешно\n";
		}
	}
}
/*---------------------/ ОПЕРАЦИИ С БРОНЬЮ /--------------------*/
// Просмотр бронированных билетов
void show_bron(list_massbron* b)
{
	for (int i = 1; i <= b->last; i++)
	{
		cout << "[" << i << "] " "Ряд: " << b->mass[i].row << " " << "Место: " << b->mass[i].place << " " << "Фамилия: " << b->mass[i].second_name << " " << endl;
	}
	cout << "Количество свободных мест в зале: " << freeplace << endl;
}

// Функция добавления брони
void add_bron(list_massbron* b, list_mass& a)
{
	int row;
	int place;
	char second_name1[20];
	cout << "Укажите ряд: ";
	cin >> row;
	cout << "Укажите место: ";
	cin >> place;
	cout << "Укажите фамилию: ";
	cin >> second_name1;
	int result_search = finde_bron(b, row, place);
	int result_search1 = finde(a, row, place);
	if (result_search == -1 && result_search1 == -1)
	{
		b->mass[b->last + 1].place = place;
		b->mass[b->last + 1].row = row;
		strcpy(b->mass[b->last + 1].second_name, second_name1);
		b->last++;
		freeplace--;
		cout << "Успешно\n";
	}
	else
	{
		cout << "Билет уже куплен\n";
		return;
	}
}
// Функция покупки брони
void buy_bron(list_mass* a, list_massbron* b)
{
	int row;
	int place;
	char second_name1[20];
	cout << "Укажите ряд: ";
	cin >> row;
	cout << "Укажите место: ";
	cin >> place;
	cout << "Укажите фамилию: ";
	cin >> second_name1;
	int result_search = finde_bron(b, row, place);
	if (result_search != -1)
	{
		a->mass[a->last + 1].place = b->mass[result_search].place;
		a->mass[a->last + 1].row = b->mass[result_search].row;
		b->last--;
		a->last++;
		cout << "Успешно\n";
	}
	else
	{
		cout << "Билет не зарегестрирован\n";
		return;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	list_mass a;
	list_massbron b;
	a.last = 0;
	b.last = 0;
	char chouse;
	cout << "1 - Произвести покупку билета \n";
	cout << "2 - Вернуть билет\n";
	cout << "3 - Вывод списка\n";
	cout << "4 - Длина списка\n";
	cout << "5 - Определение номера билета\n";
	cout << "6 - Поменять билет\n";
	cout << "7 - Выкупить с брони\n";
	cout << "0 - Конец\n";
	do
	{
		cout << "Ответ пользователя: ";
		cin >> chouse;
		switch (chouse)
		{
		case '1':
		{
			cout << "Выберите вид покупки: \n";
			cout << "1 - Прямая покупка\n2 - Бронирование\n3 - Назад\n";
			cout << "Ваш выбор: ";
			cin >> chouse;
			switch (chouse)
			{
			case '1':
			{
				add(a, &b);
				break;
			}
			case '2':
			{
				add_bron(&b, a);
				break;
			}
			}
			break;
		}
		case '2':
		{
			delet(a);
			break;
		}
		case '3':
		{
			cout << "1 - Вывести список купленных\n2 - Вывести список заброннированных\n3 - Назад\n";
			cout << "Ваш выбор: ";
			cin >> chouse;
			switch (chouse)
			{
			case '1':
			{
				show_buy(a);
				break;
			}
			case '2':
			{
				show_bron(&b);
				break;
			}
			}
			break;
		}
		case '4':
		{
			cout << "Длина списка: " << a.last << endl;
			break;
		}
		case '5':
		{
			findshow(a);
			break;
		}
		case '6':
		{
			edit(a);
			break;
		}
		case '7':
		{
			buy_bron(&a, &b);
			break;
		}
		case '0':
		{
			exit(0);
		}
		default: cout << "Некорректный ввод. Используйте цифры 1-7 для управления и 0 для выхода\n" << endl;
		}
	} while (chouse != 0);
	return 1;
}
