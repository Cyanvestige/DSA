#include <stdio.h>
struct stack 
{
	int size;
	int top;
	int *Q;
};

void Push(struct stack *S,int n)
{
	if(S->top == S->size - 1)
		printf("FULL");
	else
	{
		S->top++;
		S->Q[S->top] = n;
	}
}

int Pop(struct stack *S)
{
	if(S->top == -1)
	{
		printf("Empty");
	}
	else
	{
		S->top--;
	}
	return S->Q[S->top+1];
}

int IsEmpty(struct stack S)
{
	return S.top == -1?1:0;
}