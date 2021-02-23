#include <stdio.h>
#include <stdlib.h>
struct Node
{
	char ltr;
	struct Node *next;
}*top;

int Push(char);
char Pop();
int isEmpty();
int isMatch(char *);

int main()
{
	char S[] = "{[(a+b)]} * {[(c-d)]}";
	printf("%d",isMatch(S));

}

int Push(char n)
{
	struct Node *p;
	p = (struct Node *)malloc(sizeof(struct Node));
	p->ltr = n;
	p->next = top;
	top = p;
	return n;
}

char Pop()
{
	if(top != NULL)
	{
		char x;
		struct Node *p;
		p = top;
		x = p->ltr;
		top = p->next;
		free(p);
		return x;
	}
	else
		return 0;
}

int isEmpty()
{
	if(top == NULL)
		return 1;
	else
		return 0;
}

int isMatch(char *S)
{
	int i;
	for(i = 0;S[i] != '\0';i++)
	{
		if(S[i] == '(' || S[i] == '[' || S[i] == '{' )
			Push(S[i]);
		

		if(S[i] == ')')
			if(top->ltr == '(' || top == NULL)
				Pop();
			else
				return 0;
		if(S[i] == ']' )
			if(top->ltr == '[' || top == NULL)
				Pop();
			else
				return 0;
		if(S[i] == '}')
			if(top->ltr == '{'  || top == NULL)
				Pop();
			else
				return 0;
	}
	if(isEmpty() == 0)
		return 0;
	else
		return 1;
}