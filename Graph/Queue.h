#include <stdio.h>
#include <stdlib.h>
struct Queue
{
	int size;
	int front;
	int rear;
	int *Q;
}*top = NULL;

void InitialQue(struct Queue *A,int size)
{
	
	A->size = size;
	A->Q = (int*)malloc(sizeof(int) * size);
	A->front = A->rear = 0;
}

void Enque(struct Queue *A,int key)
{
	if((A->rear + 1) % A->size == A->front)
		printf("The queue is full");
	else
	{
		A->rear = (A->rear+1) % A->size;
		A->Q[A->rear] = key;
	}
}

int Deque(struct Queue *A)
{
	int x = -1;
	if(A->rear == A->front)
		printf("The queue is empty");
	else
	{
		A->front = (A->front + 1)%A->size;
		x = A->Q[A->front];
	}
}

int isEmpty(struct Queue *A)
{
	return A->rear == A->front?1:0;
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