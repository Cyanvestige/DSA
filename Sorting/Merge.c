#include<stdio.h>
/*void Merge(int A[],int B[],int Final[],int m,int n)
{
	int i,j,k;
	i = j = k = 0;
	while(i < m && j < n)
	{
		if(A[i] < B[j])
			Final[k++] = A[i++];
		else
			Final[k++] = B[j++];
	}
	for(;i < m;i++)
		Final[k++] = A[i];
	for(;j < n;j++)
		Final[k++] = B[j];
}*/



void MergeSingle(int A[],int l,int mid,int h)
{
	int i,j,k;
	int Final[100];
	i = l;
	j = mid + 1;
	k = l;
	while(i <= mid && j <= h)
	{
		if(A[i] < A[j])
			Final[k++] = A[i++];
		else
			Final[k++] = A[j++];
	}
	for(;i <= mid;i++)
		Final[k++] = A[i];
	for(;j <= h;j++)
		Final[k++] = A[j];
	for(i = 0;i <= h;i++)
		A[i] = Final[i]; 
}

void MergeSort(int A[],int n)
{
	int p,l,mid,h,i;
	for(p = 2;p <= n;p*=2)
	{
		for(i = 0;i + p - 1 <= n;i+=p)
		{	
			l = i;
			h = i + p - 1;
			mid = (l+h) / 2;
			MergeSingle(A,l,mid,h);
		}
	}
	if(p / 2 < n)
		MergeSingle(A,0,p/2-1,n-1);	
}

void MergeRecur(int A[],int l,int h)
{
	int mid;
	if(l < h)
	{
		mid = (l+h)/2;
		MergeRecur(A,l,mid);
		MergeRecur(A,mid+1,h);
		MergeSingle(A,l,mid,h);
	}
}

int main()
{
	int i;
	int A[4] = {2,1,6,4};
	int M[8] = {2,6,4,7,1,8,5,9};

	
	MergeSort(A,4);
	MergeRecur(M,0,7);
	for(i = 0;i < 4;i++)
		printf("%d ",A[i]);
	printf("\n");
	for(i = 0;i < 8;i++)
		printf("%d ",M[i]);
	return 0;
}
