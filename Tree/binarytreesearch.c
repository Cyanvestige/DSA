#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *lchild;
	int data;
	struct Node *rchild;
}*root = NULL;
void Insert(int key);
void Inorder(struct Node *p);
struct Node * RESearch(struct Node *p,int key);
struct Node * Search(struct Node *p,int key);
struct Node * Delete(struct Node *p,int key);
int Height(struct Node *p);
struct Node *Inpre(struct Node *p);
struct Node *Insucc(struct Node *p);
struct Node *REinsert(struct Node *p,int key);

int main()
{
	/*Insert(10);
	Insert(5);
	Insert(20);
	Insert(8);
	Insert(30);
	*/
	root = REinsert(root,10);
	REinsert(root,5);
	REinsert(root,20);
	REinsert(root,8);
	REinsert(root,30);
	Inorder(root);
	int key = 6;
	int key2 = 6;


	

	Delete(root,8);
	Inorder(root);
	

}

void Insert(int key)
{
	struct Node *t = root;
	struct Node *r,*p;

	if(root == NULL)
	{
		p = (struct Node *)malloc(sizeof(struct Node));
		p->data = key;
		p->lchild = p->rchild = NULL;
		root = p;
		return;
	}
	while(t != NULL)
	{
		r = t;
		if(key < t->data)
			t = t->lchild;
		else if(key > t->data)
			t = t->rchild;
		else
			return;
	}
	p = (struct Node *)malloc(sizeof(struct Node));
	p->data = key;
	p->lchild = p->rchild = NULL;
	if(key < r->data)
		r->lchild = p;
	else
		r->rchild = p;
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

struct Node *RESearch(struct Node *p,int key)
{
	if(p)
	{
		if(p->data < key)
			return Search(p->rchild,key);
		else if(p->data > key)
			return Search(p->lchild,key);
		else
			return p;
	}
	return NULL;
}

struct Node * Search(struct Node *p,int key)
{
	while(p != NULL)
	{
		if(p->data == key)
			return p;
		if(key < p->data)
			p = p->lchild;
		else 
			p = p->rchild;
	}
	return NULL;
}



int Height(struct Node *p)
{
	int x,y;
	if(p==NULL) return 0;
	x = Height(p->lchild);
	y = Height(p->rchild);
	return x>y?x+1:y+1;
}

struct Node *Inpre(struct Node *p)
{
	while(p && p->rchild != NULL)
		p = p->rchild;
	return p;
}

struct Node *Insucc(struct Node *p)
{
	while(p && p->lchild != NULL)
		p = p->lchild;
	return p;
}

struct Node *Delete(struct Node *p,int key)
{
	struct Node *q;
	if(p == NULL)
		return NULL;
	if(p->lchild == NULL && p->rchild == NULL)
	{
		if(p == root)
			root = NULL;
		free(p);
		return NULL;
	}
	if(key < p->data)
		p->lchild = Delete(p->lchild,key);
	else if(key > p->data)
		p->rchild = Delete(p->rchild,key);
	else
	{
		if(Height(p->lchild) > Height(p->rchild))
		{
			q = Inpre(p->lchild);
			p->data = q->data;
			p->lchild = Delete(p->lchild,q->data);
		}
		else
		{
			q = Insucc(p->rchild);
			p->data = q->data;
			p->rchild = Delete(p->rchild,q->data);
		}
	}
	return p;
}

struct Node *REinsert(struct Node *p,int key)
{
	struct Node *t = NULL;
	if(p == NULL)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = key;
		t->lchild = t->rchild = NULL;
		return t;
	}
	if(key < p->data)
		p->lchild = REinsert(p->lchild,key);
	else
		p->rchild = REinsert(p->rchild,key);

	return p;
}
