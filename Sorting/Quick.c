#include <stdio.h>
#include <limits.h>
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int A[], int l, int h)
{
	int pivot = A[l];
	int i = l, j = h;
	do
	{
		do {i++;} while (A[i] <= pivot);
		do {j--;} while (A[j] > pivot);
		if (i < j)swap(&A[i], &A[j]);
	} while (i < j);
	swap(&A[l], &A[j]);
	return j;
}

void QuickSort(int A[], int l, int h)
{
	int j;
	if (l < h)
	{
		j = partition(A, l, h);
		QuickSort(A, l, j);
		QuickSort(A, j + 1, h);
	}
}

int main()
{
	int A[] = {6, 13, 7, 12, 3}, n = 5, i;
	QuickSort(A, 0, n);

	for (i = 0; i < 5; i++)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}