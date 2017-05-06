#include <iostream>

using namespace std;

struct node
{
	int val;
	node *next;
};

//dodawanie na pocz¹tek listy
void push(node*&H, int x)			//ampersand (referencja) po to by mo¿na by³o modyfikowaæ
{
	node *tmp = new node;
	tmp->val = x;					//wartoœæ dla tmp jest równa x

	tmp->next = H;
	H = tmp;
}

//dodawanie na ostani element listy
void push_last(node*&H, int x)
{
	node *tmp = new node;
	tmp->val = x;

	node *p = H;

	if (H != NULL)
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		tmp->next = p->next;
		p->next = tmp;
	}
	else
	{
		tmp->next = H;
		H = tmp;
	}
}

//usuwanie z konca (bez drugiego argumentu, poniewa¿ nie dodajemy nic)
void pop(node*&H)
{
	node *p = H;

	if (H != NULL)
	{
		if (p->next == NULL)
		{
			H = H->next;
			delete p;
		}
		else
		{
			node *s = H;
			while (s->next->next != NULL)
			{
				s = s->next;
			}
			p = s->next;
			s->next = p->next;
			delete p;
		}
	}
}

//usuwanie z poczatku
void Del(node*&H)
{
	node *p = H;
	H = H->next;
	delete p;
}

//wyswietlanie
void show(node *H)					//brak referencji, bo nie trzeba nic edytowaæ (samo wyœwietlanie)
{
	cout << "H -> ";
	node *p = H;
	while (p != NULL)
	{
		cout << p->val << " -> ";
		p = p->next;
	}
	cout << "NULL" << endl;
}



//wstawianie elementu za danym X
void push_after_x(node*&H, int x, int po_ktorym)
{
	node *tmp = new node;
	tmp->val = x;
	node *p = H;
	if (H != NULL)
	{
		while (p->next != NULL && p->val != po_ktorym)
			p = p->next;

		if (p->val == po_ktorym)
		{
			if (p->next != NULL)
			{
				tmp->next = p->next;
				p->next = tmp;
			}
			else
			{
				tmp->next = p->next;
				p->next = tmp;
			}
		}
	}
}

//wstawianie elementu przed danym X
void push_before_x(node*&H, int x, int przed_ktorym)
{
	node *tmp = new node;
	tmp->val = x;
	node *p = H;

	if (H != NULL)
	{
		if (p->val == przed_ktorym)
		{
			tmp->next = H;
			H = tmp;
		}
		else
		{
			while (p->next != NULL && p->next->val != przed_ktorym)
			{
				p = p->next;
			}
			if (p->next != NULL)
			{
				tmp->next = p->next;
				p->next = tmp;
			}
		}
	}
}

//zamiana z nastêpnikiem elementu o wartoœci x
void swap_after(node*&H, int x)
{
	node *p = H;
	node *s = H;

	if (H != NULL && p->next != NULL)
	{
		if (p->val == x)
		{
			s = p->next;
			H = H->next;
			p->next = s->next;
			s->next = p;
		}
		else
		{
			while (p->next != NULL && p->next->val != x)
			{
				p = p->next;
			}
			if (p->next != NULL && p->next->next != NULL)
			{
				s = p->next;
				p->next = s->next;
				p = p->next;
				s->next = p->next;
				p->next = s;
			}
		}
	}
}

//zamiana z poprzednikiem o wartosci x
void swap_before(node *&H, int x)
{
	node *p = H;
	node *s = H;
	//node *tmp;

	if (H != NULL && p->val != x)
	{
		if (p->val != x)
		{
			if (p->next->val == x)
			{
				s = p->next;
				p->next = s->next;
				s->next = H;
				H = s;
			}
			else
			{
				while (p->next->next != NULL && p->next->next->val != x)
				{
					p = p->next;
				}

				if (p->next->next != NULL)
				{
					s = p->next;
					p->next = s->next;
					p = p->next;
					s->next = p->next;
					p->next = s;
				}
			}
		}
	}
}

//usuwanie elementu znajdujacego sie przed elementem o wartosci x
void delete_before(node *&H, int x)
{
	node *p = H;
	node *s = H;

	if (H != NULL && p->val != x)
	{
		if (p->next->val == x)
		{
			H = H->next;
			delete p;
		}
		else
		{
			while (p->next != NULL && p->next->val != x)
			{
				if (s->val != p->val)
				{
					s = s->next;
				}
				p = p->next;
			}

			if (p->next != NULL)
			{
				s->next = p->next;
				delete p;
			}
		}
	}
}
//przeniesienie ostatniego elementu na pierwszy
void last_to_first(node *&H)
{
	node *p = H;
	node *s = H;

	if (H != NULL && p->next != NULL)
	{
		while (p->next->next != NULL)
		{
			p = p->next;
		}
		s = p->next;
		p->next = s->next;
		s->next = H;
		H = s;
	}
}

//zamiana pierwszego elementu z ostatnim
void swap_first_last(node*&H)
{
	node *p = H;
	node *s = H;
	node *tmp = H;

	if (H != NULL && p->next != NULL)
	{
		while (p->next->next != NULL)
		{
			p = p->next;
		}
		if (tmp->next->next == NULL)
		{
			s = p->next;
			p->next = s->next;
			s->next = H;
			H = s;
		}
		else
		{
			s = p->next;
			p->next = s->next;
			s->next = H;
			H = s;
			H->next = tmp->next;
			tmp->next = p->next;
			p->next = tmp;
			tmp->next = NULL;
		}
	}
}


//usuwanie X
void delete_x(node *&H, int x)
{
	node* p = H;
	node* s = H;

	if (H != NULL)
	{
		if (H->val == x)
		{
			Del(H);
		}
		else
		{
			while (p->next != NULL && p->next->val != x)
			{
				p = p->next;
			}
			if (p->next != NULL)
			{
				s = p->next;
				p->next = s->next;
				delete s;
			}
		}
	}
}

//usuwanie co 2 element
void delete_2(node *&H)
{
	node* p = H;
	node* s;

	if (H != NULL)
	{
		while (p != NULL && p->next != NULL)
		{
			s = p->next;
			p->next = s->next;
			p = s->next;
			delete s;
		}
	}
}

//usuwanie parzystych
void delete_even(node *&H)
{
	node *p = H;
	node *s = H;

	if (H != NULL)
	{
		while (p->val % 2 == 0)
		{
			node *s = H;
			p = s->next;
			H = H->next;
			delete s;
		}
		while (p != NULL)
		{
			if (p->next->val % 2 == 0)
			{
				s = p->next;
				p->next = s->next;
				s->next = p;
				delete s;

				while (p->val % 2 == 0)
				{
					s = p->next;
					p->next = s->next;
					s->next = p;
					delete s;
				}
			}
			else
			{
				p = p->next;
			}
		}
	}
}


//H->2->4->NULL		H->2->2->4->4->4->4->NULL
void copy_value(node *&H)
{
	node *p = H;
	node *s = H;

	if (H != NULL)
	{
		while (p != NULL)
		{
			for (int i = 1; i < p->val; i++)
			{
				node *tmp = new node;
				tmp->val = p->val;
				tmp->next = p->next;
				p->next = tmp;
				p = p->next;
			}
			p = p->next;
		}
	}
}

//kopiowanie za siebie
void copy_before(node *&H)
{
	node* p = H;

	while (p != NULL)
	{
		node *tmp = new node;
		tmp->val = p->val;
		tmp->next = p->next;
		p->next = tmp;
		p = tmp->next;
	}
}

//funkcja ³¹cz¹ca
void polacz(node *&H, node *&H1)
{
	node *p = H;

	while (p->next != NULL)
	{
		p = p->next;
	}

	p->next = H1;
	H1 = NULL;
}

//wieksze od sredniej kopia na koniec
void srednia_kopia_nakoniec(node *&H)
{
	node *H1 = NULL;
	node *p = H;
	node *x = H;
	int i = 0;
	int suma = 0;

	if (H != NULL && p->next != NULL)
	{
		while (p != NULL)
		{
			i++;
			suma = suma + p->val;
			p = p->next;
		}

		int srednia = suma / i;

		node *s = H;

		while (s != NULL)
		{
			if (srednia < s->val)
			{
				push_last(H1, s->val);
			}
			s = s->next;
		}

		while (x->next != NULL)
		{
			x = x->next;
		}

		x->next = H1;
	}
}

//pierwszy na ostatni
void przenies_do_innej(node *&H, node *&H1, int x)
{
	H1 = NULL;
	node *p = H;
	node *s = H;

	if (H != NULL)
	{
		if (p->val == x)
		{
			H = H->next;
		}

		else
		{
			while (p->next != NULL && p->next->val != x)
			{
				p = p->next;
			}

			if (p->next != NULL)
			{
				s = p->next;
				p->next = s->next;
			}
		}

		if (H1 != NULL && p->next != NULL)
		{
			node *y = H1;
			while (y->next != NULL)
			{
				y = y->next;
			}
			s->next = y->next;
			y->next = s;
		}

		else if (H1 == NULL)
		{
			s->next = H1;
			H1 = s;
		}

		polacz(H, H1);
	}
}

//wieksze od sredniej przenieœæ na koniec
void srednia_przeniesc_nakoniec(node *&H)
{
	node *H1 = NULL;
	node *p = H;
	int i = 0;
	int suma = 0;

	if (H != NULL && p->next != NULL)
	{
		while (p != NULL)
		{
			i++;
			suma = suma + p->val;
			p = p->next;
		}

		int srednia = suma / i;

		node *x = H;
		while (x != NULL)
		{
			if (srednia < x->val)
			{
				x = H;
				przenies_do_innej(H, H1, x->val);
			}
			else
			{
				x = NULL;
			}
		}

		node *s = H;
		if (H != NULL)
		{
			while (s->next != NULL)
			{
				if (srednia < s->next->val)
				{
					przenies_do_innej(H, H1, s->next->val);
				}
				s = s->next;
			}
		}

		if (s->next != NULL)
		{
			node *y = H;
			while (y != NULL)
			{
				if (srednia < y->val)
				{
					przenies_do_innej(H, H1, y->val);
				}
				y = y->next;
			}
		}
	}
}

// H->1->2->3->3->2->1->2->3
void copy_2(node *&H)
{
	node *p = H;
	node *H1 = NULL;
	node *H2 = NULL;

	if (H != NULL)
	{
		while (p != NULL)
		{
			push(H1, p->val);
			p = p->next;
		}

		node *s = H1;

		while (s != NULL)
		{
			push(H2, s->val);
			s = s->next;
		}

		polacz(H, H1);
		polacz(H, H2);
	}
}

//modulo
void modulo_del(node *&H)
{
	node *p = H;
	node *s = H;

	if (H != NULL && H->next != NULL)
	{
		while (s != NULL)
		{
			if ((p->val + p->next->val) % 2 == 0)
			{
				s = p->next;
				H = H->next->next;
				delete p;
				delete s;
				p = H;
				s = H;
			}
			else
			{
				s = NULL;
			}
		}

		if (H != NULL)
		{
			while (p->next != NULL && p->next->next != NULL)
			{
				if ((p->next->val + p->next->next->val) % 2 == 0)
				{
					node *x = p->next;
					node *y = x->next;
					p->next = y->next;
					delete x;
					delete y;
				}

				else if (p->next != NULL)
				{
					p = p->next;
				}
			}
		}
	}
}

// sortowanie
void sort(node * &H) {
	node * max = H;
	node * p = H;
	node * prev_max = NULL;
	node * H2 = NULL;
	while (H != NULL)
	{
		prev_max = NULL;
		p = H;
		max = H;
		while (p->next != NULL)
		{
			if (p->next->val > max->val)
			{
				//cout << p->next->val << " jest wieksze od " << max->val<< endl;
				prev_max = p;
				max = p->next;
			}
			p = p->next;
		}
		if (prev_max == NULL)
		{
			H = H->next;
			max->next = H2;
			H2 = max;
		}
		else
		{
			prev_max->next = max->next;
			max->next = H2;
			H2 = max;
		}
	}

	H = H2;
	H2 = NULL;
}

//odwracanie
void rev(node *&H)
{
	node *p;
	node *H2 = NULL;

	while (H != NULL)
	{
		p = H;
		H = H->next;
		p->next = H2;
		H2 = p;
	}
	H = H2;
	H2 = NULL;
}



int main()
{
	node *H = NULL;
	node *H1 = NULL;



	push(H, 6);
	push(H, 6);
	push(H, 7);
	push(H, 5);
	push(H, 9);
	push(H, 10);
	


	show(H);
	modulo_del(H);
	show(H);

	system("pause");
}