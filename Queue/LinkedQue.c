#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
}*front,*rear;
void Enque(int);
int Deque();
void Display();
void Input(int a);


int main()
{
	int op;
	int x;
	do
	{
		printf("Select an option\n");
		printf("1.Enque 2.Deque 3.Display 0.QUIT");
		while(scanf("%d",&op) == 0)
			while(getchar() != '\n')
				continue;
		switch(op)
		{
			case 1:
				printf("Input the number");
				while(scanf("%d",&x) == 0)
					while(getchar() != '\n')
						continue;
				Enque(x);
				break;

			case 2:
				printf("%d is Dequed",Deque());
				break;
			case 3:
				Display();
				break;
		}
	}while(op != 0);
}

void Enque(int x)
{
	
	struct Node *t;
	t = (struct Node*)malloc(sizeof(struct Node));
	t->data = x;
	t->next = NULL;
	if(front == NULL)
	{
		front = rear = t;
	}
	else
	{
		rear->next = t;
		rear = rear->next;
	}
}

int Deque()
{
	int x;
	struct Node *q; 
	x = front->data;
	q = front;
	front = front->next;
	free(q);
	return x;
}

void Display()
{
	struct Node *i;
	i = front;
	while(i != NULL)
	{
		printf("%d ",i->data);
		i = i->next;
	}
	
}

