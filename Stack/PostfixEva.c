#include <stdio.h>
#include <stdlib.h>


struct Stack
{
	int top;
	int size;
	int *A;
};

void Push(struct Stack *,int n);
void Pop(struct Stack *);
int isOperator(char);
int Calculate(struct Stack *,char *);
void Push(struct Stack *st,int n)
{
	st->A[st->top+1] = n;
	st->top++;
}
void Pop(struct Stack *st)
{
	if(st->top != -1)
		st->top--;
}
int isOperator(char a)
{
	if(a == '+' || a == '-' || a == '*' || a == '/')
		return 1;
	else
		return 0;
}
int Calculate(struct Stack *st,char *S)
{
	int i,x1,x2;
	for(i = 0;S[i] != '\0';i++)
	{	
		x1 = st->A[st->top];
		x2 = st->A[st->top - 1];
		if(isOprand(S[i]))
		{
			switch(S[i])
			{
				case '+':
					Pop(st);
					Pop(st);
					Push(st,(x1 + x2));
					break;
				case '-':
					Pop(st);
					Pop(st);
					Push(st,(x2 - x1));
					break;
				case '*':
					Pop(st);
					Pop(st);
					Push(st,(x1 * x2));
					break;
				case '/':
					Pop(st);
					Pop(st);
					Push(st,(x2 / x1));
					break;
			}
		}
		else
			Push(st,S[i]-'0');
	
	}
	return st->A[st->top];
}

int main()
{
	struct Stack st;
	st.size = 11;
	st.top = -1;
	st.A = (int*)malloc(st.size * sizeof(int));
	char S[] = "35*62/+4-";
	printf("%d",Calculate(&st,S));

}