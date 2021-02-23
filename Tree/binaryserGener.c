#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *lchild;
	int data;
	struct Node *rchild;
}*root;

struct Stack
{
	int top;
	int size;
	struct Node **s;
};

void Push(struct Stack *,struct Node *);
struct Node * Pop(struct Stack*);
int Peektop(struct Stack*);
void creatPre(int pre[],int n);
void Inorder(struct Node* n);
void createStack(struct Stack *st,int size);
int main()
{
	int pre[] = {30,20,10,15,25,40,50,45};
	creatPre(pre,8);
	Inorder(root);
}

void createStack(struct Stack *st,int size)
{
	st->size = 100;
	st->top = -1;
	st->s = (struct Node**)malloc(st->size * sizeof(struct Node*));
}


void creatPre(int pre[],int n)
{
	struct Stack st;
	struct Node *t,*p;
	int i = 0;
	createStack(&st,100);
	root = (struct Node*)malloc(sizeof(struct Node));
	root->data = pre[i++];

	root->lchild = root->rchild = NULL;
	p = root;
	while(i < n)
	{
		if(pre[i] < p->data)
		{
			t = (struct Node*)malloc(sizeof(struct Node));
			t->data = pre[i++];
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			Push(&st,p);
			p = t;
		}
		else
		{
			if(pre[i] > p->data && (st.top == -1 || pre[i] < st.s[st.top]->data))
			{	
				
				t = (struct Node*)malloc(sizeof(struct Node));
				t->data = pre[i++];
				t->lchild = t->rchild = NULL;
				p->rchild = t;
				p = t;
				
			}
			else
				p = Pop(&st);
				
		}
		
	}
}

void Inorder(struct Node *p)
{
	if(p)
	{
		Inorder(p->lchild);
		printf("%d ",p->data);
		Inorder(p->rchild);
	}
}


void Push(struct Stack *st,struct Node* t)
{
	st->top++;
	st->s[st->top] = t;
	
}

struct Node *Pop(struct Stack *st)
{
	if(st->top != -1)
	{
		struct Node *x;
		x = st->s[st->top];
		st->top--;
		return x;
	}
	else
		printf("Empty");
}