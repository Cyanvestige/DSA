#include <stdio.h>
#include <stdlib.h>
struct Queue
{
	int size;
	int front;
	int rear;
	int *Q;
};
void Enque(struct Queue*,int n);
int Deque(struct Queue*);
void Display(struct Queue);


int main()
{
	int op;
	int x;
	struct Queue q;
	printf("Enter the size:");
	scanf("%d",&q.size);
	q.Q = (int*)malloc(q.size * sizeof(int));
	q.front = q.rear = 0;
	do
	{
		printf("1.Enque 2.Deque 3.Display 0.QUIT");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				
				printf("input the num");
				scanf("%d",&x);
				Enque(&q,x);
				break;
			case 2:
				printf("%d is Dqued",Deque(&q));
				break;
			case 3:
				Display(q);
				break;
		}

	}while(op!=0);
}

void Enque(struct Queue *q,int x)
{
	if((q->rear+1) % q->size == q->front)
		printf("Queue is full.");
	else
	{
		q->rear = (q->rear+1) % q->size;
		q->Q[q->rear] = x;
	}
}

int Deque(struct Queue *q)
{
	int x = -1;
	if(q->front == q->rear)
		printf("Queue is Empty");
	else
	{
		q->front = (q->front + 1) % q->size;
		x = q->Q[q->front];
	}
	return x;
}	

void Display(struct Queue q)
{
	int i;
	i = q.front + 1;
	do
	{
		printf("%d ",q.Q[i]);
		i = (i+1) % q.size;
	}while(i != (q.rear+1) % q.size);
}
Queue{
	if((a.rear + 1) % a.size == a.front)
	{
		FULL
	}
	else
	{
		a.A[a.rear + 1 % a.size] = x
		
	}
}