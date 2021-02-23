#include <stdio.h>
#include <stdlib.h>
#include "ArrayQue.h"


void create();
void Preorder(struct Tree *p);
void Inorder(struct Tree *p);
void Postorder(struct Tree *p);
void PreorderItr(struct Stack *s,struct Tree *p);
void PostorderItr(struct Stack *s,struct Tree *p);
void Levelorder(struct Tree *p);
int count(struct Tree *p);
int height(struct Tree *p);
int main()
{
	struct Stack s;
	CreateStack(&s,100);
	create();
	Preorder(root);
	printf("\nInorder:");
	Inorder(root);
	printf("\nPostorder:");
	Postorder(root);
	printf("GGG\n");
	printf("Level\n");
	
	printf("%d",count(root));
	printf("\n%d",height(root));
	return 0;
}


void create()
{
	struct Tree *p,*t;
	struct ArrQueue q;
	struct Stack s;
	int x;

	Createque(&q,100);
	printf("Enter the root");
	scanf("%d",&x);
	root = (struct Tree *)malloc(sizeof(struct Tree));
	root->data = x;
	root->lchild = root->rchild = NULL;
	Enque(&q,root);
	while(!isEmpty(&q))
	{
		p = Deque(&q);
		printf("Enter the lfhand child of %d",p->data);
		scanf("%d",&x);
		if(x != -1)
		{
			t = (struct Tree *)malloc(sizeof(struct Tree));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			Enque(&q,t);
		}
		printf("Enter the rfhand child of %d",p->data);
		scanf("%d",&x);
		if(x != -1)
		{
			t = (struct Tree *)malloc(sizeof(struct Tree));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			Enque(&q,t);
		}
	}
}

void Preorder(struct Tree *p)
{
	if(p)
	{
		printf("%d ",p->data);
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}

void Inorder(struct Tree *p)
{
	if(p)
	{
		Inorder(p->lchild);
		printf("%d ",p->data);
		Inorder(p->rchild);
	}
}

void Postorder(struct Tree *p)
{
	if(p)
	{
		Postorder(p->lchild);
		Postorder(p->rchild);
		printf("%d ",p->data);
	}
}

void Levelorder(struct Tree *p)
{
	struct ArrQueue new;
	Createque(&new,100);
	printf("%d ",p->data);
	Enque(&new,root);
	while(!isEmpty(&new))
	{
		p = Deque(&new);
		if(p->lchild)
		{
			printf("%d ",p->lchild->data);
			Enque(&new,p->lchild);
			
		}
		if(root->rchild)
		{
			printf("%d ",p->rchild->data);
			Enque(&new,p->rchild);
		}
		
	}
}


void PreorderItr(struct Stack *s,struct Tree *p)
{
	struct Tree * t = p;
	while(s->top != -1 || t != NULL)
	{
		if(t != NULL)
		{
			printf("%d ",t->data);
			Push(s,(int)t);
		    t = t->lchild;
		}
		else
		{
			t = Pop(s);
			t = t->rchild;
		}
	}
}
//not working
void PostorderItr(struct Stack *s,struct Tree *p)
{
	struct Tree *t = p;
	long int temp;
	while(s->top != -1 || t != NULL)
	{
		if(t != NULL)
		{
			Push(s,(int)t);
		    t = t->lchild;
		}
		else
		{
			temp = (long int)Pop(s);
			if(temp > 0)
			{
				Push(s,-1 * temp);
				t=((struct Tree*)temp)->rchild;
			}
			else
			{
				printf("%d",((struct Tree*)temp)->data);
				t = NULL;
			}
		}
	}
}

int count(struct Tree *p)
{
	if(p)
		return count(p->lchild)+count(p->rchild)+1; 
	return 0;
}

int height(struct Tree *p)
{
	int x;
	int y;
	x = height(p->lchild);
	y = height(p->rchild);
	if(!p)
		return 0;
	if(x > y)
		return x + 1;
	else
		return y + 1;

}

