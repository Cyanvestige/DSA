#include <stdio.h>
#include <stdlib.h>
struct Tree
{
	struct Tree *lchild;
	int data;
	struct Tree *rchild;
}*root = NULL;

struct Queue
{
	struct Tree *data;
	struct Queue *next;
}*top,*last;

void Enque(struct Tree *n);
struct Tree *Deque();
int isEmpty();

void Enque(struct Tree *n)
{
	struct Queue *t;
	t = (struct Queue*)malloc(sizeof(struct Queue));
	if(t != NULL)
	{
		if(top == NULL)
		{
			t->data = n;
			t->next = NULL;
			top = last = t;
		}
		else
		{
			t->data = n;
			t->next = NULL;
			last->next = t;
			last = t;
		}
	}
	else
		printf("HEAP is FULL");
}

 struct Tree *Deque()
 {
 	struct Tree *t;
 	if(top != NULL)
 	{
 		struct Queue *q;
 		q = top;
 		t = q->data;
 		top = top->next;
 		free(q);	
 		return t;
 	}
 	else
 	{
 		printf("EMPTY");
 	}
 }

int isEmpty()
{
	return top == NULL;
}