#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
}*first;
struct Node *second;
void Create(int A[],int n);
void Create2(int A[],int n);
void DisplayRec(struct Node *p);
int Display(struct Node *p);
int Count(struct Node *p);
int CountRec(struct Node *p);
int Sum(struct Node *p);
int SumRec(struct Node *p);
int Max(struct Node *p);
int MaxRec(struct Node *p);
struct Node *Search(struct Node *,int);
struct Node *SearchRec(struct Node *,int);
struct Node *SearchToTop(struct Node *,int);
void InsertNode(int,int);
void InsertLast(int);
void InsertSort(int);
void Delete(int);
int CheckSorted(struct Node *p);
void RemoveDupli(struct Node *p);
void ReverseByArray(struct Node *p);
void ReverseByLink(struct Node *p);
void ReverseByLinkRec(struct Node *xxx,struct Node *p);
void Concatenate(struct Node *a,struct Node *b);

int main()
{
	int A[]= {1,2,2,2,5};
	int B[] = {9,9,7,6,4};
	Create(A,5);
	Display(first);
	Create2(B,5);
	ReverseByLink(first);
	Display(first);
	ReverseByLinkRec(NULL,first);
	Display(first);
	Concatenate(first,second);
	Display(first);
	free(first);
	return 0;
}

void Create(int A[],int n)
{
	int i;
	struct Node *t,*last;
	first = (struct Node *)malloc(sizeof(struct Node));
	
	first->data = A[0];
	first->next = NULL;
	last = first;
	for(i = 1;i < n;i++)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

void Create2(int B[],int n)
{
	int i;
	struct Node *t,*last;
	second = (struct Node *)malloc(sizeof(struct Node));
	second->data = B[0];
	second->next = NULL;
	last = second;
	for(i = 1;i < n;i++)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = B[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

void DisplayRec(struct Node *p)
{
	if(p != NULL)
	{
		DisplayRec(p->next);
		printf("%d ",p->data);
		
	}
}

int Display(struct Node *p)
{
	printf("\n");
	while(p != 0)
	{
		printf("%d ",p->data);
		p = p->next;
	}
}

int Count(struct Node *p)
{
	int c = 0;
	while(p != 0)
	{
		p = p->next;
		c++;
	}
	return c;
}

int CountRec(struct Node *p)
{
	if(p == NULL)
		return 0;
	return CountRec(p->next) + 1;
}

int Sum(struct Node *p)
{
	int s = 0;
	while(p)
	{
		s = s + p->data;
		p = p->next; 
	}
	return s;
}

int SumRec(struct Node *p)
{
	if(!p)
		return 0;
	return SumRec(p->next) + p->data;
}


int Max(struct Node *p)
{
	int max = -32768;
	while(p)
	{
		if(p->data > max)
			max = p->data;
		p = p->next;
	}
	return max;
}

int MaxRec(struct Node *p)
{
	int x = 0;
	if(!p)
		return -32768;
	else
	{
		x = MaxRec(p->next);
		return x > p->data?x:p->data;
	}

}

struct Node *Search(struct Node *p,int key)
{
	while(p != NULL)
	{	
		if(p->data == key)
			return p;
		p = p->next;
	}
	return NULL;
}

struct Node *SearchRec(struct Node *p,int key)
{
	if(p == NULL)
		return NULL;
	if(p->data == key)
		return p;
	SearchRec(p->next,key);
}

struct Node *SearchToTop(struct Node *p,int key)
{
	struct Node *q = NULL;
	while(p != NULL)
	{
		if(p->data == key)
		{
			q->next = p->next;
			p->next = first;
			first = p;
			return p;
		}
		q = p;
		p = p->next;
	}
}

void InsertNode(int n,int pos)
{
	int i;
	struct Node *p = first;
	struct Node *t = (struct Node *)malloc(sizeof(struct Node));
	if(pos == 0)
	{
		t->data = n;
		t->next = first->next;
		first = t;
	}
	else
	{
		for(i = 0;i < pos-1 && p;i++)
			p = p->next;
		t->data = n;
		t->next = p->next;
		p->next = t;
	}
}

void InsertLast(int n)
{
	struct Node *last;
	struct Node *t = (struct Node *)malloc(sizeof(struct Node));
	t->data = n;
	t->next = NULL;
	if(first == NULL)
		first = last = t;
	else
	{
		last->next = t;
		last = t;
	}
}

void InsertSort(int n)
{
	struct Node *t = (struct Node *)malloc(sizeof(struct Node));
	struct Node *p,*q;
	p = first;
	q = NULL;
	while(p->data < n)
	{
		q = p;
		p = p->next;
	}
	t->data = n;
	t->next = p;
	q->next = t;
}

void Delete(int n)
{
	if(first != NULL)
	{
		
		if(n == 1)
		{
			struct Node *p = first->next;
			first = NULL;
			first = p;
		}
		else
		{
			int i;
			struct Node *p = first;
			struct Node *q = NULL;
			for(i = 1;i < n;i++)
			{
				q = p;
				p = p->next;
			}
			q->next = p->next;
			free(p);			
		}
	}
}

int CheckSorted(struct Node *p)
{
	while(p->next != NULL)
	{
		if(p->data < p->next->data)
			p = p->next;
		else
			return 0;
	}
	return 1;
}

void RemoveDupli(struct Node *p)
{
	struct Node *q = p->next;
	while(q != NULL)
	{
		if(q->data == p->data)
		{
			p->next = q->next;
			free(q);
			q = p->next;
		}
		else
		{
			p = q;
			q = q->next;
		}
	}

}

void ReverseByArray(struct Node *p)
{
	int *tmp = (int*)malloc(Count(first) * sizeof(int));
	int i = 0;
	while(p != NULL)
	{
		tmp[i++] = p->data;
		p = p->next;
	}
	p = first;
	i--;
	while(i >= 0)
	{
		p->data = tmp[i--]; 
		p = p->next;
	}
	free(tmp);	
}

void ReverseByLink(struct Node *p)
{
	int i;
	struct Node *q,*r;
	q=r=NULL;
	while(p!=NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}	
	first = q;
}

void ReverseByLinkRec(struct Node *q,struct Node *p)
{
	if(p != NULL)
	{
		ReverseByLinkRec(p,p->next);
		p->next = q;
	}
	else
		first = q;
}

void Concatenate(struct Node *p,struct Node *q)
{
	while(p->next != NULL)
		p = p->next;
	p->next = q;
}