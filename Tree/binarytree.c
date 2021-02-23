#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


void create();
void Preorder(struct Tree *p);
void Inorder(struct Tree *p);
void Postorder(struct Tree *p);
int main()
{
	create();
	Preorder(root);
	printf("\nInorder:");
	Inorder(root);
	printf("\nPostorder:");
	Postorder(root);
	return 0;
}


void create()
{
	struct Tree *p,*t;
	int x;
	printf("Please input the root");
	scanf("%d",&x);
	root = (struct Tree*)malloc(sizeof(struct Tree));

	root->data = x;
	root->lchild = root->rchild = NULL;
	Enque(root);
	while(!isEmpty())
	{
		p = Deque();
		printf("Input the left child of %d",p->data);
		scanf("%d",&x);
		if(x != -1)
		{
			t = (struct Tree*)malloc(sizeof(struct Tree));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			Enque(t);
		}
		if(x != -1)
		{
			t = (struct Tree*)malloc(sizeof(struct Tree));
			t->data = x;
			t->rchild = t->lchild = NULL;
			p->rchild = t;
			Enque(t);
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

