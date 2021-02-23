#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*top = NULL;



void Push(int n)
{
	struct Node *p;
	p = (struct Node *)malloc(sizeof(struct Node));
	if(p == NULL)
		printf("Stack Overflow");
	else
	{	
		p->data = n;
		p->next = top;
		top = p;
	}
}

int Pop()
{
	int val;
	if(top != NULL)
	{
		struct Node *q;
		q = top;
		val = q->data;
		top = top->next;
		free(q);
	}
	else
	{
		printf("Empty");
	}
	return val;
}

void Peek(int n)
{
	if(top != NULL)
	{
		int i;
		for(i = 0; i < n-1;i++)
			top = top->next;	
		printf("the %dth is %d",n,top->data);
	}
	else
	{
		printf("Empty");
	}
}

int Peektop()
{
	if(top != NULL){
		return top->data;
	}
	else
		printf("Empty");
	return 0;	
}

void Display()
{
	struct Node *p;
	p = top;
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
}

int isEmpty(){
	if(top == NULL)
		return 1;
	return 0;
}