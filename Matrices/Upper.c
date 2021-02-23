#include <stdio.h>
#include <stdlib.h>
struct M
{
	int *A;
	int n;
};

void Set(struct M*,int,int,int);
int Get(struct M,int,int);
void Display(struct M);
int GetDimentsion(int);

int main()
{
	struct M matrix;
	printf("Enter the Dimension");
	scanf("%d",&matrix.n);
	matrix.A = (int *)malloc(matrix.n*(matrix.n+1)/2* sizeof(int));
	printf("Enter all the Elements:");
	int i,j,x;
	for(i = 1;i <= matrix.n;i++)
	{
		for(j = 1;j <= matrix.n;j++)
		{
			scanf("%d",&x);
			Set(&matrix,i,j,x);
		}
		
	}
	Display(matrix);
	free(matrix.A);
}

void Set(struct M *m,int i,int j,int x)
{
	if(i <= j)
		m->A[((m->n+(m->n-(i-2)))*(i-1))/2 + j - 1] = x;
} 

int Get(struct M m,int i,int j)
{
	if(i <= j)
		return m.A[((m.n+(m.n-(i-2)))*(i-1))/2 + j - 1];
	return 0;
}

void Display(struct M m)
{
	int i,j;
	for(i = 1;i <= m.n;i++)
	{
		for(j = 1;j <= m.n;j++)
		{
		
			if(i <= j)
				printf("%d",m.A[((m.n+(m.n-(i-2)))*(i-1))/2 + j - 1]);
			else
				printf("%c",'0');
		}
		printf("\n");
	}
}