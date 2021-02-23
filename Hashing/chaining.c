#include <stdio.h>
#include "chains.h"

int hash(int key)
{
	return key%10;
}
void Insert(struct Node *H[],int key)
{
	int index = hash(key);
	SortedInsert(&H[index],key);
}
int main()
{
	struct Node *HT[10];
	int i;
	for(i = 0;i < 10;i++)
		HT[i] = NULL;
	Insert(HT,12);
	Insert(HT,22);
	Insert(HT,42);
	Insert(HT,43);
	Display(HT[3]);
	Display(HT[2]);
	printf("%d\n",Search(HT[hash(22)],22)->data);
		
	return 0;
}