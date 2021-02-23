#include <stdio.h>
void Swap(int *a,int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void Selection(int arr[],int n)
{
	int i,j,k;
	for(i = 0;i < n - 1;i++)
	{
		for(j = k = i;j < n;j++)
		{
			if(arr[j] < arr[k])
				k = j;
		}
		Swap(&arr[i],&arr[k]);

	}
}

int main()
{
	int arr[5] = {4,2,6,1,7};
	int i;
	for(i = 0;i < 5;i++)
	{
		printf("%d ",arr[i]);
	}
	Selection(arr,5);
	for(i = 0;i < 5;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}