#include <stdio.h>
#include <stdlib.h>
void Swap(int *x,int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void Bubble(int *x,int n)
{
	int i;
	int j;
	int flag;
	for(i = 0;i < n - 1;i++)
	{	
		flag = 0;
		for(j = 0;j < n - 1 - i;j++)
		{
			if(x[j] > x[j+1])
			{
				Swap(&x[j],&x[j+ 1]);
				flag = 1;
			}
		}
		if(flag == 0)
			break;
	}
}

int main()
{
	int n;
	int i;
	int *arr;
	printf("How many numbers?");
	scanf("%d",&n);
	arr = malloc(n*sizeof(int));
	for(i = 0;i < n;i++)
	{
		printf("arr[%d]= ",i);
		scanf("%d",&arr[i]);
	}
	for(i = 0;i < n;i++)
	{
		printf("%d ",arr[i]);
	}
	Bubble(arr,n);
	for(i = 0;i < n;i++)
	{
		printf("%d ",arr[i]);
	}
	free(arr);
	return 0;

}