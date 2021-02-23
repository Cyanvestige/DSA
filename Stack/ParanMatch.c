#include <stdio.h>
#include <stdlib.h>
struct Stack
{
	int size;
	int top;
	char *s;
};
int Push(struct Stack *,char);
int Pop(struct Stack *);
int Peek(struct Stack st,int pos);
int stacktop(struct Stack st);
int isFull(struct Stack st);
int isEmpty(struct Stack st);
void Display(struct Stack st);
int isMatch(char *,struct Stack );

int main()
{
	struct Stack res;
	res.s = (char*)malloc(100 * sizeof(char));
	res.size = 100;
	res.top = -1;
	char S[] = "((a+b)*(c-d))";
	printf("%d",isMatch(S,res));
}

int Push(struct Stack *st,char n)
{
	if(st->top != st->size - 1)
	{
		st->s[st->top + 1] = n;
		st->top++;
		return n;
	}
	
	else
	{
		printf("FULL");
	}
	
}

int Pop(struct Stack *st)
{
	int x;
	if(st->top != -1)
	{
		x = st->s[st->top--];
		return x;
	}
	else
	{
		return -1;
	}

}

int Peek(struct Stack st,int pos)
{
	int x;
	x = st.s[st.top - pos + 1];
	return x;
}

int stacktop(struct Stack st)
{
	int x;
	x = st.s[st.top];
	return x;
}

int isFull(struct Stack st)
{
	if(st.top+1 == st.size)
		return 1;
	else
		return 0;
}

int isEmpty(struct Stack st)
{
	if(st.top == -1)
		return 1;
	else
		return 0;
}

void Display(struct Stack st)
{
	int i;
	for(i = 0;i <= st.top;i++)
		printf("%d ",st.s[i]);
	printf("\n");
} 

int isMatch(char *S,struct Stack res)
{
	int i;
	for(i = 0;S[i]!='\0';i++)
	{
		if(S[i] == '(')
			Push(&res,'(');
		else if(S[i] == ')')
		{
			if(Pop(&res) == -1)
				return 0;
		}
	}
	if(isEmpty(res) == 0)
		return 0;
	else
		return 1;
}