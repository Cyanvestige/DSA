#include <stdio.h>
#include <stdlib.h>
struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
}*head, *last, *first;

void Create(int *, int);
void Display(int);
void DisplayE(int n);

void Insert(int, int);
void Delete(int);
void Reverse();

int main()
{
	int A[] = {1, 2, 3, 4, 5};
	Create(A, 5);
	Display(12);
	Insert(888, 4);
	Display(12);
	Delete(3);
	Display(12);
	Reverse();
	Display(12);
}

void Create(int * A, int n)
{
	int i;
	struct Node *t;
	head = (struct Node*)malloc(sizeof(struct Node));
	first = (struct Node*)malloc(sizeof(struct Node));
	head->data = 0;
	head->prev = head;
	first = head;

	if (first == head)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->prev = t;
		t->data = A[0];
		t->next = t;
		last = t;
		first = t;
	}
	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		t->prev = last;
		last->next = t;
		last = t;
	}
	first->prev = last;
	last->next = first;
}

void Display(int n)
{
	struct Node *p;
	int i = 0;
	p = first;
	while (i < n)
	{
		printf("%d ", p->data);
		p = p->next;
		i++;
	}
	printf("\n");
}
void DisplayE(int n)
{
	struct Node *p;
	int i = 0;
	p = last;//Got wrong , miswrote 'first'.
	while (i < n)
	{
		printf("%d ", p->data);
		p = p->prev;
		i++;
	}
	printf("\n");
}

void Insert(int n, int pos)
{
	struct Node *t;
	t = (struct Node*)malloc(sizeof(struct Node));
	if (pos == 0)
	{
		t->prev = last;
		t->data = n;
		t->next = first;
		first = t;

	}
	else
	{
		int i;
		struct Node *q;
		q = first;
		for (i = 0; i < pos - 1; i++)
		{
			q = q->next;
		}
		t->prev = q;
		t->data = n;
		t->next = q->next; // first and first relation
		if (q->next)
		{
			q->next->prev = t;
			q->next = t;
		}
	}
}

void Delete(int pos)
{
	struct Node *q;
	q = first;
	if (pos == 1)
	{
		first = first->next;
		last->next = first;
		first->prev = last;//forgot make the first one's previous one the last one.
	}
	else
	{
		int i;
		struct Node *p, *q;
		p = last;
		q = first;
		for (i = 0; i < pos - 1; i++)
		{
			p = q;
			q = q->next;
		}
		p->next = q->next;
		q->next->prev = p;
		q = NULL;
		free(q);
	}
}

void Reverse()
{
	struct Node *p, *q, *tmp;
	int i;
	p = first;
	do
	{
		tmp = p->prev;
		p->prev = p->next;
		p->next = tmp;
		p = p->next;
	} while (p != first); //NOT LAST !!! should be first
	first = first->next;//!!!!!! not know reason yet!
}





