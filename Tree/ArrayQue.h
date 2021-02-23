#include <stdio.h>
#include <stdlib.h>
struct Tree
{
	struct Tree *lchild;
	int data;
	struct Tree *rchild;
}*root = NULL;

struct ArrQueue
{
	int size;
	int front;
	int rear;
	struct Tree **Q;
};



struct Stack
{
	int size;
	int top;	
	int *S;
};


void Createque(struct ArrQueue *q,int size);
void Enque(struct ArrQueue *p,struct Tree* n);
void CreateStack(struct Stack *s,int size);
void Push(struct Stack *s,int n);
struct Tree *Pop(struct Stack *s);
struct Tree *Deque(struct ArrQueue *p);
int isEmpty(struct ArrQueue *p);


void CreateStack(struct Stack *s,int size)
{
	s->size = size;
	s->top = -1;
	s->S = (int*)malloc(s->size * sizeof(int));
}


void Createque(struct ArrQueue *q,int size)
{
	q->size = size;
	q->front = q->rear = 0;
	q->Q = (struct Tree**)malloc(q->size * sizeof(struct Tree *));
}

void Enque(struct ArrQueue *p,struct Tree *n)
{
	if((p->rear + 1) % p->size == p->front)
	{
		printf("FULL");
	}
	else
	{
		p->rear = (p->rear + 1) % p->size;
		p->Q[p->rear] = n;
		
	}
}

struct Tree *Deque(struct ArrQueue *p)
{
	struct Tree *x = NULL;
	if(p->rear == p->front)
	{
		printf("Empty");
		return NULL;
	}
	else
	{
		p->front = (p->front + 1) % p->size;
		x = p->Q[p->front];
		return x;
	}
}

int isEmpty(struct ArrQueue *p)
{
	return p->rear == p->front;
}

void Push(struct Stack *s,int n)
{
	if(s->top != s->size)
	{
		s->top++;
		s->S[s->top] = n;
	}
	else
	{
		printf("FULL");
	}
}

struct Tree *Pop(struct Stack *s)
{
	struct Tree * x = NULL;
	if(s->top != -1)
	{	
		x = (struct Tree *)s->S[s->top];
		s->top--;
		return x;
	}
	else
		return NULL;
}