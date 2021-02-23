#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Array 
{
	int *A;
	int size;
	int length;
};
void Input(int *);
void DisplayArr(int*,int);
void Display(struct Array arr);
void Append(struct Array *arr,int x);
void Insert(struct Array *arr,int index,int x);
int Delete(struct Array *arr,int index);
void swap(int *a,int *b);
int LinearSearch(struct Array arr,int key);

int BinarySearch(struct Array arr,int x);
int BinarySearchRec(struct Array arr,int l,int mid,int h);
void ReverseArr1(struct Array *arr);
void ReverseArr2(struct Array *arr);
void InserttoSorted(struct Array *arr, int);
void PoNeExchan(struct Array *arr);
struct Array UnionUnsor(struct Array,struct Array);
struct Array UnionSor(struct Array ,struct Array);
struct Array IntersecUnsor(struct Array arr,struct Array arr2);
struct Array IntersecSor(struct Array arr,struct Array arr2);
struct Array DiffUnsor(struct Array arr,struct Array arr2);
struct Array DiffSor(struct Array arr,struct Array arr2);

bool isSorted(struct Array arr);
void SelSort(struct Array *arr);


int main()
{
	int i;
	int choice;
	int tar;
	int pos;
	int re;
	struct Array arr;
	printf("This is Array ADT\n");
	printf("Please enter the size of array\n");
	Input(&arr.size);
	printf("%d",arr.size);
	printf("Please enter how many elements are in the array\n");
	Input(&arr.length);
	arr.A = (int*)malloc(arr.size * sizeof(int));
	for(i = 0;i < arr.length;i++)
	{
		printf("Please enter arr[%d]= ",i);
		Input(&arr.A[i]);
	}
	do
	{
		printf("\n\nBasic:\n1.Display     2.Append     3.Insert     4.Delete\nSearch:\n5.LinearSearch     6.BinarySearch\n0.Exit the program\n");
		Input(&choice);
	
		switch(choice)
		{
			case 1:
				Display(arr);
				break;
			case 2:
				printf("\nPlease input the number you want to append to the array:");
				Input(&tar);
				Append(&arr,tar);
				break;
			case 3:
				printf("\nPlease input the number you want to append to the array:");
				Input(&tar);
				printf("\nPlease input the index where you want to append the number");
				Input(&pos);
				Insert(&arr,pos,tar);
				break;
			case 4:
				printf("\nPlease input the index of the element you want to delete:");
				scanf("%d",&pos);
				Delete(&arr,pos);
				break;
			case 5:
				printf("\nPlease input the number you are looking for:");
				Input(&tar);
				if(LinearSearch(arr,tar) == -1)
					printf("NOT FOUND");
				else
					printf("%d is arr[%d]",tar,LinearSearch(arr,tar));
				break;
			case 6:
				printf("\nPlease input the number you are looking for:");
				Input(&tar);
				if(BinarySearch(arr,tar) == -1)
					printf("NOT FOUND");
				else
					printf("%d is arr[%d]",tar,BinarySearch(arr,tar));
				break;
			




		}
	}while(choice != 0);
	



	
	return 0;
}
void Input(int *n)
{
	while(scanf("%d",n) != 1)
		if(getchar() != '\n')
			continue;
}







	/*struct Array arr;
	int n,i;
	printf("Enter size of an array");
	scanf("%d",&arr.size);
	arr.A = (int*)malloc(arr.size*sizeof(int));
	arr.length = 0;

	printf("Enter number of numbers");
	scanf("%d",&n);

	printf("Enter all Elements");
	for(i = 0;i < n;i++)
		scanf("%d",&arr.A[i]);
	arr.length = n;
	*/
	






void DisplayArr(int *arr,int n)
{
	int i;
	printf("\nElements are\n");
	for(i = 0;i < n;i++)
	printf("%d ",arr[i]);
}

void Display(struct Array arr)
{
	int i;
	printf("\nElements are\n");
	for(i = 0;i < arr.length;i++)
		printf("%d ",arr.A[i]);
}

void Append(struct Array *arr,int x)
{
	if(arr->length < arr->size)
		arr->A[arr->length++] = x;
}

void Insert(struct Array *arr,int index,int x)
{
	int i;
	if(index >= 0 && index < arr->length)
	{
		for(i = arr->length;i > index;i--)
			arr->A[i] = arr->A[i - 1];
		arr->A[index] = x;
		arr->length++;
	}
}

int Delete(struct Array *arr,int index)
{
	int i;
	int x;
	x = 0;
	if(index >= 0 && index < arr->length)
	{
		x = arr->A[index];
		for(i = index;i < arr->length;i++)
			arr->A[i] = arr->A[i+1];
		arr->length--;
	}
	return x;
}

void swap(int *a,int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int LinearSearch(struct Array arr,int key)
{
	int i;
	for(i = 0;i < arr.length;i++)
		if(arr.A[i] == key)
			return i;
	return -1;
}	


int BinarySearch(struct Array arr,int key)
{
	int mid;
	int l = 0;
	int h = arr.length-1;
	while(l <= h)
	{
		mid = (l + h) / 2;
		if(key  < arr.A[mid])
			h = mid - 1;
		else if(key > arr.A[mid])
			l = mid + 1;
		else
			return mid;
	}
	return -1;
}

int BinarySearchRec(struct Array arr,int l,int h,int key)
{
	int mid;
	
	if(l <= h)
	{
		mid = (l+h)/2;
		if(key == arr.A[mid])
			return mid;
		else if(key < arr.A[mid])
			return BinarySearchRec(arr,l,mid - 1,key);
		else
			return BinarySearchRec(arr,mid + 1,h,key);
	}
	return - 1;
}

void ReverseArr1(struct Array *arr)
{
	int tmp[arr->length];
	int i;
	int j;
	for(i = 0, j = arr->length - 1;j >= 0;i++,j--)
	{
		tmp[i] = arr->A[j]; 
	}

	for(i = 0;i < arr->length ;i++)
	{
		arr->A[i] = tmp[i];
	}
}

void ReverseArr2(struct Array *arr)
{
	int i,j;
	for(i = 0,j = arr->length - 1;i < j;i++,j--)
		swap(&arr->A[i],&arr->A[j]);
}

void InserttoSorted(struct Array *arr,int key)
{
	int i;
	i = arr->length - 1;
	while(arr->A[i] > key)
	{
		arr->A[i+1] = arr->A[i];
		i--;
	}
	arr->A[i+1] = key;
	arr->length++;
}

bool isSorted(struct Array arr)
{
	int i;
	for(i = 0;i < arr.length - 1;i++)
		if(arr.A[i] > arr.A[i+1])
			return false;
	return true;
}

void SelSort(struct Array *arr)
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

void PoNeExchan(struct Array *arr)
{
	int l,h;
	l = 0;
	h = arr->length - 1;
	while(l < h)
	{
		if(arr->A[l] < 0)l++;
		if(arr->A[h] >= 0)h--;
		swap(&arr->A[l],&arr->A[h]);
	}
}

struct Array UnionUnsor(struct Array arr,struct Array arr2)
{
	int i,j,k;
	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array)); 
	arr3->size = 10;
	for(i = 0;i < arr.length;i++)
		arr3->A[i] = arr.A[i];
	k = i;
	for(i = 0;i < arr2.length;i++)
	{
		if(LinearSearch(*arr3,arr2.A[i]) == -1)
		{	
			arr3->length = k+1;
			arr3->A[k++] = arr2.A[i];
		}
	}
	return *arr3;
}


struct Array UnionSor(struct Array arr,struct Array arr2)
{
	int i,j,k;
	i = j = k = 0;
	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array)); 
	arr3->size = 10;

	while(i < arr.length && j <arr2.length)
	{
		if(arr.A[i] < arr2.A[j])
			arr3->A[k++] = arr.A[i++];
		else if(arr.A[i] > arr2.A[j])
			arr3->A[k++] = arr2.A[j++];
		else
		{
			arr3->A[k++] = arr.A[i++];
			j++;
		}
	}
	
	for(;i < arr.length;i++)
		arr3->A[k++] = arr.A[i];
	for(;j < arr2.length;j++)
		arr3->A[k++] = arr2.A[j];

	arr3->length = k;
	return *arr3;
}

struct Array IntersecUnsor(struct Array arr,struct Array arr2)
{
	int i,j,k;
	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array)); 
	arr3->size = 10;
	k = 0;
	arr3->length = 0;
	for(i = 0;i < arr.length;i++)	
		for(j = 0;j < arr2.length;j++)
			if(arr.A[i] == arr2.A[j])
				if(LinearSearch(*arr3,arr.A[i]) == -1)
				{
					arr3->A[k++] = arr.A[i];
				}
	arr3->length = k;
	return *arr3;		
}


struct Array IntersecSor(struct Array arr,struct Array arr2)
{
	int i,j,k;
	i = j = k = 0; 
	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
	arr3->size = 10;
	while(i < arr.length && j < arr2.length)
	{
		if(arr.A[i] < arr2.A[j])
			i++;
		else if(arr.A[i] > arr2.A[j])
			j++;
		else
		{
			arr3->A[k++] = arr.A[i++];
			j++; 
		}
	}
	arr3->length = k;
	return *arr3; 
}

struct Array DiffUnsor(struct Array arr,struct Array arr2)
{
	int i,j,k;
	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array)); 
	arr3->size = 10;
	arr3->length = 0;
	k = 0;
	for(i = 0;i < arr.length;i++)
		if(LinearSearch(arr2,arr.A[i]) == -1)
			arr3->A[k++] = arr.A[i];
	for(j = 0;j < arr2.length;j++)
		if(LinearSearch(arr,arr2.A[j]) == -1)
			arr3->A[k++] = arr2.A[j];
	arr3->length = k;
	return *arr3;
}

struct Array DiffSor(struct Array arr,struct Array arr2)
{
	int i,j,k;
	i = j = k = 0; 
	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array)); 
	arr3->size = 10;
	while(i < arr.length && j < arr2.length)
	{
		if(arr.A[i] < arr2.A[j])
			arr3->A[k++] = arr.A[i++];
		else if(arr.A[i] > arr2.A[j])
			arr3->A[k++] = arr2.A[j++];
		else
		{
			i++;
			j++;
		}
	}
	for(;i < arr.length;i++)
		arr3->A[k++] = arr.A[i];
	for(;j < arr2.length;j++)
		arr3->A[k++] = arr2.A[j];
	arr3->length = k;
	return *arr3;
}
