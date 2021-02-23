#include <stdio.h>
void insert(int A[],int n)
{
	int temp;
	int i = n;
	temp = A[n];
	while(i > 1 && temp > A[i/2])
	{
		A[i] = A[i/2];
		i = i / 2;
	}
	A[i] = temp; 
}
void swap(int A[],int x,int y)
{
	int tmp;
	tmp = A[x];
	A[x] = A[y];
	A[y] = tmp;
}
void Delete(int A[],int n)
{
	int i,j;
	int temp = A[n];
	int val = A[1];
	A[1] = A[n];
	A[n] = val;
	i = 1;
	j = i * 2;
	A[i] = temp;
	while(j < n-1)
	{
		if(A[j+1] > A[j])
			j = j+1;
		if(A[i] < A[j])
		{	
			swap(A,i,j);
			i = j;
			j = 2 * j;
		}
		else
			break;
	}
}
int main()
{
	int i;
	int A[10] = {0,10,20,30,25,5,40,35};//index is from 1 not zero;

	for(i = 0;i < 8;i++)
	{
		printf("%d ",A[i]);
	}
	for(i = 2;i <= 7;i++)
	{
		insert(A,i);
	}
	printf("\n");
	for(i = 1;i <= 7;i++)
	{
		printf("%d ",A[i]);
		
	}
	for(i = 7;i > 1;i--)
		Delete(A,i);
	printf("\n");
	for(i = 1;i <= 7;i++)
	{
		printf("%d ",A[i]);
	}

}