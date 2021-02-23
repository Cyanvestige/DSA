#include <stdio.h>
#include <stdlib.h>
struct Stack
{
	int size;
	int top;
	int *s;
};


int Push(struct Stack *,int);
int Pop(struct Stack *);
int Peek(struct Stack st,int pos);
int stacktop(struct Stack st);
int isFull(struct Stack st);
int isEmpty(struct Stack st);
void Display(struct Stack st);






int main()
{
	struct Stack st;
	int size;
	int n;
	int op;
	int p;
	printf("How many elements are there?");
	scanf("%d",&size);
	st.size = size;
	st.top = -1;
	st.s = (int *)malloc(size * sizeof(int));
	printf("1.Push  2.Pop  3.Peek  4.PeekTop  5.isFull  6.isEmpty  0.Quit\n");
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
					printf("%d is pushed\n",Push(&st,n));
					break;
				case 2:
					printf("%d is popped\n",Pop(&st));
					break;
				case 3:
					printf("input the position\n");
					scanf("%d",&p);
					printf("the %dth is %d\n",p,Peek(st,p));
					break;
				case 4:
					printf("the top one is %d\n",stacktop(st));
					break;
				case 5:
					if(isFull(st))
						printf("Full\n");
					else
						printf("Not Full\n");
					break;
				case 6:
					if(isEmpty(st))
						printf("Empty\n");
					else
						printf("Not Empty\n");
					break;
				case 7:
					Display(st);
					break;
			}
			printf("1.Push  2.Pop  3.Peek  4.PeekTop  5.isFull  6.isEmpty  7.Display 0.Quit\n");
			printf("Select an option");
			scanf("%d",&op);
		}
	}
}

int Push(struct Stack *st,int n)
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
		printf("No Element");
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
