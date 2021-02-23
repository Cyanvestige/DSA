#include<stdio.h>
#include<stdlib.h>

#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
}*first;

void Create(int *,int);
void Display(struct Node*);
int REDisplay(struct Node*);
void CheckifLoop(struct Node *f);
void Insert(struct Node *p,int n,int index);
void Delete(struct Node *p,int index);
int main()
{
	int A[] = {1,2,3,7,8,12};
	Create(A,6);
	Display(first);
	printf("\n");
	int c = REDisplay(first);
	CheckifLoop(first);
	printf("\n");
	Insert(first,111,0);
	Display(first);
	Delete(first,1);
	printf("\n");
	
	Display(first);
	return 0;
}

void Create(int *A,int n)
{
	int i;
	struct Node *t,*last;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = first;
	last = first;
	for(i = 1;i < n;i++)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
	last->next = first;
	
}
void Display(struct Node *p)
{
	int i = 0;
	do
	{
		printf("%d ",p->data);
		p = p->next;
	}while(p != first);
}

int REDisplay(struct Node *p)
{
	static int flag = 0;
	if(p != first || flag == 0)
	{
		flag++;
		printf("%d ",p->data);
		REDisplay(p->next);
	}
	return flag;
}

void CheckifLoop(struct Node *f)
{
	struct Node *p,*q;
	p = q = f;
	do
	{
		p = p->next;
		q = q->next;
		q!=NULL?q->next:q;
	}while(p!=NULL && q!=NULL && q != p);
	if(p == q)
		printf("Circular");
	else
		printf("Linear");
}

void Insert(struct Node *p,int n,int index)
{
	struct Node *t = (struct Node *)malloc(sizeof(struct Node));
	if(index == 0)
	{
		t->data = n;
		t->next = p;
		while(p->next != first)
			p=p->next;
		
		first = t;
		p->next = first;
	}
	else
	{
		int i;
		for(i = 0;i < index - 1;i++)
			p = p->next;
		t->data = n;
		t->next = p->next;
		p->next = t;
	}
}

void Delete(struct Node *p,int index)
{
	int i;
	struct Node *q = NULL;
	if(index == 1)
	{
		while(p->next != first)
			p=p->next;
		if(p==first)
		{
			free(first);
			first = NULL;
		}
		else
		{
			p->next = first->next;
			free(first);
			first = p->next;
		}
	}
	else
	{
		for(i = 0;i < index - 2;i++)
			p = p->next;
		q = p->next;
		p->next = q->next;
		free(q);
	}
}


	

