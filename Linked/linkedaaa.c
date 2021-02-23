#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
}*first;
void Create(int A[], int n)
{
	int i;
	struct Node *t, *last;
	first = (struct Node *)malloc(sizeof(struct Node));

	first->data = A[0];
	first->next = NULL;
	last = first;
	for (i = 1; i < n; i++)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}
void InsertNode(int n, int pos)
{
	int i;
	struct Node *p = first;
	struct Node *t = (struct Node *)malloc(sizeof(struct Node));
	if (pos == 0)
	{
		t->data = n;
		t->next = first;
		first = t;
	}
	else
	{
		for (i = 0; i < pos - 1 && p; i++)
			p = p->next;
		t->data = n;
		t->next = p->next;
		p->next = t;
	}
}


int Display(struct Node *p)
{
	printf("\n");
	while (p != 0)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

int main()
{
	int n, pos;
	int A[] = {1, 22, 3, 4, 5};
	Create(A, 5);
	struct Node *p = first;
	InsertNode(100, 0);
	Display(first);
	InsertNode(200, 1);
	Display(first);
	InsertNode(300, 2);
	Display(first);
	free(first);
	return 0;
}

