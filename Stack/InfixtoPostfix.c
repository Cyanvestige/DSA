#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
	char ltr;
	struct Node *next;
}*top;
void Push(char);
char Pop();
int isOperator(char);
int pre(char );
char *convert(char * infix);
int main()
{
	Push('#');
	char infix[50] = "a+b*c-d/e";
	char *result;
	puts(convert(infix));
	return 0;

}

void Push(char s)
{
	struct Node *p;
	p = (struct Node *)malloc(sizeof(struct Node));
	p->ltr = s;
	p->next = top;
	top = p;
}

char Pop()
{
	char x;
	if(top != NULL)
	{
		struct Node *p;
		p = top;
		x = p->ltr;
		top = p->next;
		free(p);
	}
	return x;
}

int isOperator(char o)
{
	if(o == '+' || o == '-' || o == '*' || o == '/')
		return 1;
	else
		return 0;
}

int pre(char o)
{
	if(o == '+' || o == '-')
		return 1;
	else if(o == '*' || o == '/')
		return 2;
	return 0;
}

char *convert(char * infix)
{
	char *post;
	int i = 0,j = 0;
	post = (char *)malloc(strlen(infix) * sizeof(char) + 1);
	while(infix[i] != '\0')
	{
		if(isOperator(infix[i]) == 1)
		{
			if(pre(infix[i]) > pre(top->ltr))
				Push(infix[i++]);
			else
				post[j++] = Pop();
		}
		else
			post[j++] = infix[i++];
	}
	while(top != NULL)
		post[j++] = Pop();
	post[j] = '\0';
	return post;
}