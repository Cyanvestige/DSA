#include <stdio.h>
#include <stdlib.h>
int FindMisSor(int *);
void swap(int *a,int *b);
int partition(int *arr,int p,int n);
void QuickSort(int *arr,int p,int n);
int MasterMiss(int *arr);
void MasterMiss2(int *arr);
void MasterMissHash(int *arr);
void Selsort(int *arr,int n);
int BubbleMAX(int *arr,int n);
void Dupli(int *arr,int n);
void DupliHash(int *arr,int n);
void DupliCheck(int *,int);
void PairSum(int *,int,int a);
//My method
void swap(int *a,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int *arr,int p,int n)
{
	int i,j;
	i = p,j = n;
	do
	{
		do{i++;}while(arr[i] <= arr[p]);
		do{j--;}while(arr[j] > arr[p]);
		if(i < j)
			swap(&arr[i],&arr[j]);
	}while(i < j);
	swap(&arr[p],&arr[j]);
	return j;
}
void QuickSort(int *arr,int p,int n)
{
	int j;
	if(p < n)
	{
		j = partition(arr,p,n);
		QuickSort(arr,p,j);
		QuickSort(arr,j+1,n);
	}

}
int main()
{
	int i;
	int arr[] = {7,4,2,3,8,8,5,6,11,11};
	for(i = 0;i < 10;i++)
		printf("%d ",arr[i]);
	printf("\n");
	PairSum(arr,10,11);
	return 0;
}
/*



int FindMisSor(int *arr)
{
	int i;
	i = 0;
	while(i <= 11)
	{
		if(arr[i+1] != arr[0] + i + 1)
			return (arr[i] + arr[i+1]) / 2;
		else
			i++;
		
	}
}*/

//Master Method:
int MasterMiss(int *arr)
{
	int i;
	int sum;
	int re;
	sum = 0;
	for(i = 0;i < 11;i++)
		sum += arr[i]; 
	re = ((arr[i - 1] - arr[0] + 1) * (arr[0] + arr[i - 1])) / 2; 
	printf("%d\n",re);
	return re - sum;
}
//Master Method 2:
void MasterMiss2(int *arr)
{
	int i;
	int diff;
	i = 0;
	diff = arr[0];
	while(i < 10)
	{
		if(arr[i] - i != diff)
			printf("\nMissing %d",i + diff++);
		i++;
	} 
}
//Master Method 3:
void MasterMissHash(int *arr)
{
	int i;
	int MAX;
	int *tmp;
	MAX = BubbleMAX(arr,10);
	printf("\nMAX IS %d\n",MAX);
	tmp = (int*)malloc((MAX+1) * sizeof(int));
	for(i = arr[0];i < MAX + 1;i++)
		tmp[i] = 0;
	i = 0;
	while(i < 10)
		tmp[arr[i++]] = 1;
	for(i = 0;i < MAX + 1;i++)
	{
		if(tmp[i] == 0)
			printf("%d Missing\n",i);
	}
	
}

void Selsort(int *arr,int n)
{
	int i,j,k;
	for(i = 0;i < n - 1;i++)
	{
		for(j = k = i;j < n;j++)
			if(arr[j] < arr[i])
				k = j;
		swap(&arr[k],&arr[i]);
	}
}

int BubbleMAX(int *arr,int n)
{
	int i,j;
	for(i = 0;i < 1;i++)
		for(j = 0;j < n - i - 1;j++)
			if(arr[j] > arr[j+1])
				swap(&arr[j],&arr[j+1]);
	return arr[n-1];
}

void Dupli(int *arr,int n)
{
	int LastDup = 0;
	int i = 0;
	int j;
	while(i < n - 1)
	{
		if(arr[i] == arr[i+1])
		{
			j = i;
			LastDup = arr[i];
			while(arr[j] == LastDup)
			{
				j++;
			}
			printf("%d is duplicated %d times\n",arr[i],j - i);
			i = j;
		}
		else
			i++;
	}
}

void DupliHash(int *arr,int n)
{
	int i;
	int MAX;
	int *tmp;
	MAX = BubbleMAX(arr,10);
	printf("\nMAX IS %d\n",MAX);
	tmp = (int*)malloc((MAX+1) * sizeof(int));
	for(i = 0;i < MAX + 1;i++)
		tmp[i] = 0;
	i = 0;
	while(i < n)
		tmp[arr[i++]]++;
	i = 0;
	for(i = 0;i < MAX+1;i++)
		if(tmp[i] > 1)
			printf("%d is duplicated %d times\n",i,tmp[i]);
}

void DupliCheck(int *arr,int n)
{
	int i,j;
	int count;
	for(i = 0;i < n;i++)
	{	
		count = 1;
		if(arr[i] != -1)
		{
			for(j = i + 1;j < n;j++)
				if(arr[j] == arr[i])
				{
					count++;
					arr[j] = -1;
				}
			if(count > 1)
				printf("%d is duplicated %d times\n",arr[i],count);	
		}
	}
}

void PairSum(int *arr,int n,int sum)
{
	int i,j;
	for(i = 0;i < n - 1;i++)
	{
		for(j = i + 1;j < n;j++)
		{
			if(arr[i] + arr[j] == sum)
			{
				printf("%d and %d\n",arr[i],arr[j]);
				i++;
			}
		}
	}
}

