#include <stdio.h>
#include <stdlib.h>

struct Que
{
	int front;
	int rear;
	int size;
	char *A;
};

int transform(char);
void Enqueue1(struct Que *q,char x);
void Dequeue1(struct Que *q);
void Enqueue2(struct Que *q,char x);
void Dequeue2(struct Que *q);
void Enqueue3(struct Que *q,char x);
void Dequeue3(struct Que *q);
void Display(struct Que q);
int main()
{
	char sys[] = "ABCDEFGHIJ";
	
	int i = 0;
	int a;
	struct Que q1,q2,q3;
	q1.front = q2.front = q3.front = q1.rear = q2.rear = q3.rear = 0;
	q1.size = q2.size = q3.size = 10;
	q1.A = (char*)malloc(q1.size * sizeof(char));
	q2.A = (char*)malloc(q2.size * sizeof(char));
	q3.A = (char*)malloc(q3.size * sizeof(char));
	while(sys[i] != '\0')
	{
		if(transform(sys[i]) == 1)
		{
			Enqueue1(&q1,sys[i]);
		}
		else if(transform(sys[i]) == 2)
		{
			Enqueue2(&q2,sys[i]);
		}
		else 
		{
			Enqueue3(&q3,sys[i]);
		}
		i++;
	}
	while()
	Display(q1);
	Display(q2);
	Display(q3);
}

void Enqueue1(struct Que *q,char x)
{
	q->rear = (q->rear + 1) % q->size;
	q->A[q->rear] = x;
}

void Dequeue1(struct Que *q)
{
	q->front = (q->front + 1) % q->size;
}

void Enqueue2(struct Que *q,char x)
{
	q->rear = (q->rear + 1) % q->size;
	q->A[q->rear] = x;
}

void Dequeue2(struct Que *q)
{
	q->front = (q->front + 1) % q->size;
}


void Enqueue3(struct Que *q,char x)
{
	q->rear = (q->rear + 1) % q->size;
	q->A[q->rear] = x;
}

void Dequeue3(struct Que *q)
{
	q->front = (q->front + 1) % q->size;
}

int transform(char x)
{
	if(x == 'A' || x == 'B' || x == 'F')
		return 1;
	else if(x == 'C' || x == 'E' || x == 'G' || x == 'I' || x == 'J')
		return 2;
	else
		return 3;
}

void Display(struct Que q)
{
	int i;
	i = q.front + 1;
	do
	{
		printf("%c ",q.A[i]);
		i = (i+1) % q.size;
	}while(i != (q.rear+1) % q.size);
	printf("\n");
}



