#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int A[10];
	int length;
	int size;
}Data;

void Display(Data);
void Append(Data *,int);
void Insert(Data *,int,int);
void Delete(Data *,int);
void swap(int *a,int *b);
int BinaryS(Data arr,int key);
int BinarySR(Data arr, int l,int h,int key);
void BubSort(Data *arr);
void SelSort(Data*);



void Display(Data arr)
{
	int i;
	for(i = 0;i < arr.length;i++)
		printf("%d ",arr.A[i]);
	printf("\n");
}

void Append(Data *arr,int x)
{
	if(arr->length < arr->size)
		arr->A[arr->length++] = x;
}

void Insert(Data *arr,int index,int x)
{
	int i;
	for(i = arr->length; i > index;i--)
		arr->A[i] = arr->A[i-1];
	arr->A[index] = x;
	arr->length++;
}

void Delete(Data *arr,int index)
{
	int i;
	for(i = index;i < arr->length;i++)
		arr->A[i] = arr->A[i+1];
	arr->length--;
}

void swap(int *a,int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int LinearS(Data *arr,int key)
{
	int i;
	for(i = 0;i < arr->length;i++)
		if(arr->A[i] == key)
		{
			swap(&arr->A[0],&arr->A[i]);
			return i;
		}
	return -1;
}

int BinaryS(Data arr,int key)
{
	int l,h,mid,i;
	l = 0;
	h = arr.length-1;
	while(l <= h)
	{
		mid = (l + h)/2;
		if(arr.A[mid] < key)
			l = mid + 1;
		else if (arr.A[mid] > key)
			h = mid - 1;
		else
			return mid;
	}
	return -1;
}

int BinarySR(Data arr, int l,int h,int key)
{
	int mid; 
	mid = (l + h) / 2; 
	if(arr.A[mid] < key)
		BinarySR(arr,mid+1,h,key);
	else if(arr.A[mid] > key)
		BinarySR(arr,l,mid-1,key);
	else
		return mid;
}
void SelSort(Data *arr)
{
	int i,j,k;
	for(i = 0;i < arr->length - 1;i++)
	{
		for(j = k = i;j < arr->length;j++)
			if(arr->A[j] < arr->A[k])
				k = j;
		swap(&arr->A[i],&arr->A[k]);
	}
}

void BubSort(Data *arr)
{
	int i,j,flag;
	for(i = 0;i < arr->length -1;i++)
	{
		flag = 0;
		for(j = 0;j < arr->length - i - 1;j++)
		{
			if(arr->A[j] > arr->A[j+1])
			{	
				swap(&arr->A[j],&arr->A[j+1]);
				flag = 1;
			}
		}
		if(flag == 0) return;
	}
}

int main()
{
	Data X = {{4,1,6,7,3},5,10};
	Display(X);
	Append(&X,2);
	Display(X);
	Delete(&X,5);
	Display(X);
	Insert(&X,3,2);
	Display(X);
	Delete(&X,3);
	Display(X);
	printf("%d\n", LinearS(&X,3));
	BubSort(&X);
	Display(X);
	printf("%d\n", BinaryS(X,7));
	printf("%d\n", BinarySR(X,0,4,4));
	return 0;
}



