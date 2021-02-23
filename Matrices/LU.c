#include <stdio.h>
#include <stdlib.h>
void Display(int matrix[])
{
	int i,j;
	int n = 0;
	for(i = 0;i < 3;i++)
	{
		for(j = 0;j < 3;j++)
		{
			printf("%d ",matrix[n++]);
		}
		printf("\n");
	}
}

void Multiply(int m1[],int m2[],int newm[])
{
	
	int i,j,k,n;
	n = 0;
	for(i = 0;i < 3;i++)
	{
		for(j = 0;j < 3;j++)
		{
			for(k = 0;k < 3;k++)
				newm[n] += m1[i*3 + k] * m2[j + 3*k];
			n++;	
		}
	}
}

//void LUFac(int m1[],int new1[],int new2[])

int main()
{
	int *newm = (int*)malloc(9 * sizeof(int));
	int i = 0;

	int m1[9] = {2,3,-1,0,-2,-1,0,0,-5};
	int m2[9] = {1,0,0,2,1,0,-1,-3,1};
	for(i = 0;i < 9;i++)
		newm[i] = 0;
	Display(m1);
	printf("\n");
	Display(m2);
	
	printf("\n");
	Multiply(m2,m1,newm);
	Display(newm);

}