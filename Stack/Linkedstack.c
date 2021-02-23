#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int data;
	struct Stack *next;
}*top;

void Push(int);
void Pop();
void Peek(int n);
void Peektop();
void Display();
int main()
{
	int op;
	int n;
	int pos;
	printf("1.Push  2.Pop  3.Peek  4.PeekTop 5.Display 0.Quit\n");
	printf("Select an option");
	scanf("%d",&op);
	if(op != 0 )
	{
		while(op != 0)
		{
			
			switch(op)
			{
				case 1:
					printf("Input a number\n");
					scanf("%d",&n);
					Push(n);
					break;
				case 2:
					Pop();
					break;
				case 3:
					printf("input the position\n");
					scanf("%d",&pos);
					Peek(pos);
					break;
				case 4:
					Peektop();
					break;
				case 5:
					Display();
					break;
			}
			printf("1.Push  2.Pop  3.Peek  4.PeekTop  5.Display 0.Quit\n");
			printf("Select an option");
			scanf("%d",&op);
		}
	}
}

void Push(int n)
{
	struct Stack *p;
	p = (struct Stack *)malloc(sizeof(struct Stack));
	if(p == NULL)
		printf("Stack Overflow");
	else
	{	
		p->data = n;
		p->next = top;
		top = p;
	}
}

void Pop()
{
	if(top != NULL)
	{
		struct Stack *q;
		q = top;
		top = top->next;
		free(q);
	}
	else
	{
		printf("Empty");
	}
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

void Peektop()
{
	if(top != NULL)
		printf("the top one is %d",top->data);
	else
		printf("Empty");	
}

void Display()
{
	struct Stack *p;
	p = top;
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
}