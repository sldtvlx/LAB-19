#include <iostream>
using namespace std;
char a;

class stack
{
public:
	char data;
	stack* prev;
};

stack* sozd_stack(int n)
{
	if (n == 0)
	{
		return NULL;
	}

	stack* top, * p;
	top = NULL;
	p = new stack;

	cout << "Введите элементы: ";
	cin >> a;
	p->data = a;
	p->prev = NULL;
	top = p;

	for (int i = 2; i <= n; i++)
	{
		stack* h = new stack;

		cin >> a;
		h->data = a;
		h->prev = top;
		top = h;
	}
	return top;
}

void print(stack* top)
{
	if (top == NULL)
	{
		cout << "Стек пуст" << endl;
	}

	else
	{
		stack* p = top;

		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->prev;
		}
		cout << endl;
	}
}

void add(stack*& first, int n)
{
	stack* p = first;
	stack* h = new stack;

	cout << "Введите элемент для добавления: ";
	cin >> h->data;
	h->prev = p;
	first = h;

	while (p->prev != NULL)
	{
		stack* h = new stack;

		cout << "Введите элемент для добавления: ";
		cin >> h->data;
		h->prev = p->prev;
		p->prev = h;

		if (p->prev->prev != NULL)
		{
			p = p->prev->prev;
		}

		else {
			p = p->prev;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите кол-во элементов: ";
	int n;
	cin >> n;
	stack* st = sozd_stack(n);
	cout << "Стек: ";
	print(st);
	add(st, n);

	cout << "Изменённый стек: ";
	print(st);
	return 0;
}