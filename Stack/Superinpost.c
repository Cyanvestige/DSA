#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
	char ltr;
	struct Node *next;
}*top;
void Push(char);
char Pop();
int isOperand(char);
int outPre(char);
int inPre(char);
char *convert(char * infix);
int main()
{
	Push('#');
	char infix[50] = "((a+b)*c)-d^e^f";
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

int isOperand(char l)
{
	if(l == '+' || l == '-' || l == '*' || l == '/' || l == '(' || l == ')' || l == '^')
		return 1;
	else
		return 0;
}
int inPre(char l)
{
	if(l == '+' || l == '-')
		return 2;
	else if(l == '*' || l == '/')
		return 4;
	else if(l == '^')
		return 5;
	else if(l == '(')
		return 0;
	return 0;
}

int outPre(char l)
{
	if(l == '+' || l == '-')
		return 1;
	else if(l == '*' || l == '/')
		return 3;
	else if(l == '^')
		return 6;
	else if(l == '(')
		return 7;
	return 0;
}

char *convert(char * infix)
{
	char *post;
	int i = 0,j = 0;
	post = (char *)malloc(strlen(infix) * sizeof(char) + 1);
	while(infix[i] != '\0')
	{
		if(isOperand(infix[i]))
		{
			if(outPre(infix[i]) > inPre(top->ltr) || top == NULL)
			{
				Push(infix[i++]);
			}
			else
			{
				while(outPre(infix[i]) < inPre(top->ltr))
				{
					
					post[j++] = top->ltr;
					Pop();
				}
				if(outPre(infix[i]) == inPre(top->ltr))
				{
					Pop();
					i++;
				}
				else
					Push(infix[i++]);
			}	
		}
		else
		{
			post[j++] = infix[i++];
		}
	}
	while(top != NULL)
	{	
		
		post[j++] = top->ltr;
		top = top->next;
	}
	post[j] = '\0'; 
	return post;

}