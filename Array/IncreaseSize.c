#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *p,*q;
	int i;
	p = (int*)malloc(5*sizeof(int));
	q = (int*)malloc(10*sizeof(int));
	for(i = 5;i < 10;i++)
	{
		q[i] = i + 1;
	}
	for(i = 0;i < 5;i++)
	{
		p[i] = i + 1;
	}
	for(i = 0;i < 5;i++)
	{
		q[i] = p[i];
	}
	for(i = 0;i < 10;i++)
	{
		printf("%d ",p[i]);
	}
	printf("\n");
	for(i = 0;i < 10;i++)
	{
		printf("%d ",q[i]);
	}
	printf("\n");
	free(p);
	p = q;
	q = NULL;
	for(i = 0;i < 10;i++)
	{
		printf("%d ",p[i]);
	}
	return 0;
}