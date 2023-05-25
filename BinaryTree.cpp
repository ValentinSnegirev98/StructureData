Постановка задачи: 
•	Реализовать представление бинарного дерева в виде дважды связного списка братьев и сыновей.
•	Реализовать вывод дерева на экран.
•	Выполнить индивидуальное задание: Построить полное дерево с указанной высотой.

  #include <iostream>
#include <conio.h>
#include <iomanip>
#include <fstream>
using namespace std;

// Исходная структура "Дерево".
struct Node 
{
	int value;
	Node* son;
	Node* brother;
};

// Функция определения высоты дерева
int Length(Node* head)
{
	int count = 0;
	Node* current = head;
	while (current != NULL)
	{
		count++;
		current = current->brother;
	}
	return(count);
}

// Функция добавления узла в дерево
void Add(Node*& node, int item)
{
	if (node == NULL)
	{
		node = new Node;
		node->value = item;
		node->son = NULL;
		node->brother = NULL;
	}
	else if(item<node->value)
	{
		Add(node->son, item);
	}
	else
	{
		Add(node->brother, item);
	}

}

// Функция вывода дерева
void PrintTree(Node*& node)
{
	if (node == NULL)
	{
		cout << "U" << endl;
	}
	else
	{
		cout << node->value;
		if (node->brother != NULL)
		{
			cout << " - ";
			PrintTree(node->brother);
		}
		if (node->son != NULL)
		{
			cout << endl << "---------------" << endl;
			cout<< "(" << node->value << ")";

			PrintTree(node->son);
		}
	}
}

int main()
{
	setlocale(0, "");
	ifstream f("tree.txt");
	Node* root = NULL;
	Node* top = NULL;
	int elem = 1, key_top, count = 0;
	while (!f.eof())
	{
		f >> elem;
		Add(root, elem);

	}
	f.close();
	PrintTree(root);
	cout << endl;
	system("pause");
	return 0;
}
