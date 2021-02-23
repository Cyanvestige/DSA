#include<stdio.h>
#include<stdlib.h>

int MAX(int a[],int n)
{
	int i,j,tmp;
	for(i = 0;i < n - 1;i++)
		for(j = i;j < n - 1 - i;j++)
			if(a[j] > a[j+1])
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;		 
			}
	return a[n-1];
} 

void Count(int C[],int n)
{
	int *arr,i,j;
	j = 0;
	arr = (int*)malloc((MAX(C,8) + 1) * sizeof(int));
	for(i = 0;i < n - 1;i++)
		arr[i] = 0;
	i = 0;
	for(i = 0;i < n - 1;i++)
		arr[C[j++]]++;
	i = 0;
	j = 0;
	while(j < n)
	{
		if (arr[i] > 0)
		{
			C[j++] = i;
			arr[i]--;  
		}
		else
			i++;
	}
}

int main()
{
	int i;
	int M[] = {2,6,4,7,1,8,5,9};
	
	for(i = 0;i < 8;i++)
		printf("%d ",M[i]);
	printf("\n");
	Count(M,8);
	for(i = 0;i < 8;i++)
		printf("%d ",M[i]);
}