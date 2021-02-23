#include <stdio.h>
#include <stdlib.h>

struct Node{
	struct Node *prev;
	int data;
	struct Node *next;
}*first = NULL;

void Create(int *,int);
void Display(struct Node *p);
void Insert(struct Node *p,int n,int pos);
void Delete(struct Node*p,int pos);
void Reverse(struct Node *p);
void DisplayR(struct Node *p);
int main()
{
	int A[] = {10,20,30,40,50};
	Create(A,5);
	DisplayR(first);
	Display(first);
	Insert(first,99,5);
	Display(first);
	Reverse(first);
	Display(first);


}

void Create(int *A,int n)
{
	int i;
	struct Node *t,*last;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->prev = first->next = NULL;
	first->data = A[0];
	last = first;
	for(i = 1;i < n;i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		
		t->next = last->next;
		t->prev = last;
		
		last->next = t;
		last = t;
	}
}

void Display(struct Node *p)
{
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");

}

void DisplayR(struct Node *p)
{
	while( p->next != NULL)
	{
		p = p->next;
	}

	while(p)
	{
		printf("%d ",p->data);
		p=p->prev;
	}
	printf("\n");

}



void Insert(struct Node *p,int n,int pos)
{
	int i;
	struct Node *t;
	
	if(pos == 0)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->prev = NULL;
		t->data = n;
		t->next = p;
		first->prev = t;
		first = t;
	}
	else
	{
		for(i = 0;i < pos -1 ;i++)
			p = p->next;
		t = (struct Node*)malloc(sizeof(struct Node));
		t->prev = p;
		t->data = n;
		t->next = p->next;
		
		if(p->next)
			p->next->prev = t;
		p->next = t;
	}
}

void Delete(struct Node *p,int pos)
{
	int i;
	if(pos == 1)
	{
		if(first->next == NULL)
		{	
			first = NULL;
			free(first);
		}
		else
		{
			first = p->next;
			first->prev = NULL;
		}
	}

	else
	{
		struct Node *q = NULL;
		for(i = 0;i < pos - 1;i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		p->next->prev = q;
		p = NULL;
	}
}

void Reverse(struct Node *p)
{
	struct Node *tmp;
	while(p != NULL)
	{
		tmp = p->next;
		p->next = p->prev;
		p->prev = tmp;
		p = p->prev;
		if(p != NULL && p->next == NULL ) 
			first = p;
	}

}


