#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first;

void Create(int *, int);
int FindMid(struct Node*);
void rearrange (struct Node *first);
void Display();
int main()
{
	int A[] = {1, 2, 3, 4, 5, 6, 7};
	Create(A, 7);
	printf("%d", FindMid(first));
	printf("\n");
	rearrange (first);
	Display();
}

void Display()
{
	struct Node *p = first;
	while (p != NULL)
	{
		printf("%d", p->data);
		p = p ->next;
	}
}
void Create(int *A, int n)
{
	int i;
	struct Node*t, *last;
	first = (struct Node*)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;
	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

int FindMid(struct Node *l)
{
	struct Node *p, *q;
	p = q = first;
	while (q != NULL)
	{
		q = q->next;

		if (q)q = q->next;
		if (q)p = p->next;
	}
	return p->data;
}

void rearrange (struct Node *l)

{

	struct Node *p, *q;

	int temp;

	if (!first || !first-> next) return;

	p = first;

	q = first-> next;

	while (q)

	{
		temp = p->data;
		p -> data = q -> data;
		q -> data = temp;
		p = q ->next;
		q = p ? p -> next : 0;

	}

}