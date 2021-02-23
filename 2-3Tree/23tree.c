#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node * lch;
	int data1;
	int data2;
	struct Node * midch;
	struct Node *rch;
}*root;

struct Node *CreateNode()
{
	struct Node *t;
	t = (struct Node *)malloc(sizeof(struct Node));
	t->lch = t->midch = t->rch = NULL;
	t->data1 = t->data2 = 0;
	return t;
}
void Insert(struct *Node p,int key)
{
 	struct Node *x = p; 
 	struct Node *pre; 
 	if(root == NULL)
 	{
 		struct Node *t;
		t = (struct Node *)malloc(sizeof(struct Node));
		t->lch = t->midch = t->rch = NULL;
		t->data1 = t->data2 = 0;
		root = t;
		root->data1 = key;
 		return;
 	}
 	while(x != NULL)
 	{
 		pre = x;
 		if(key < x->data1)
 			x = x->lch;
		else if(key > x->data1 && key > x->data2)
			x = x->rch;
		else
			x = x->midch;
	}
 	if(pre->data2 == 0)
 	{
 		pre->data2 = key;
 	}
 	else
 		root = Split(pre,key);
 	
}

struct Node *Split(struct Node *p,struct Node *up,int key)
{
	struct Node *up;
	struct Node *equi;
	up = CreateNode();
	equi = CreateNode();
	if(key < p->data1)
	{
		up->data1 = p->data1;
		equi->data1 = p->data2
		p->data1 = key;
		p->data2 = 0;
	}
	else if(key > p->data2)
	{
		up->data1 = p->data2;
		equi->data1 = key;
		p->data2 = 0;
	}
	else
	{
		up->data1 = key;
		equi->data1 = p->data2;
		p->data2 = 0;
	}
	return up;
}
