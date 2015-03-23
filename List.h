#include <iostream>

struct node
{
	int valor;
	node* next;
	node* prev;

};

class List
{
public:
	node* start;
	node* end;

private:
	unsigned int size;

public:
	List(){ start = NULL; end = NULL; size = 0; }
	~List(){ Clear(); }
	unsigned int Count()
	{
		return size;
	}
	void Add(unsigned int Num)
	{
		node* new_node;
		new_node = new node;
		new_node->valor = Num;
		if (start == NULL)
		{
			start = end = new_node;
		}
		else
		{
			end->next = new_node;
			new_node->prev = end;
			new_node = end;
		}
	}
	bool Del(node* Item)
	{
		if (Item == NULL)
			return false;

		if (Item->prev != NULL)
		{
			Item->prev->next = Item->next;
			if (Item->next != NULL)
			{
				Item->next->prev = Item->prev;
			}
			else{ end = Item->prev; }
			if (Item->prev == NULL)
			{
				Item->next = start;
			}
			if (Item->next == NULL && Item->prev == NULL)
			{
				end = start = NULL;
			}
			delete Item;
			--size;
			return true;
		}
	}
	void Clear()
	{
		node* tmp1;
		node* tmp2;
		tmp1 = start;
		while (tmp1->next != NULL)
		{
			tmp2 = tmp1;
			delete tmp2;
			tmp1 = tmp1->next;
		}
		start = end = NULL;
		size = 0;

	}

};

