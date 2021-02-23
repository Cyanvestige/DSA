#include <stdio.h>
#include<stdlib.h>
int main()
{
	int a[3][4] = {{1,2,3,4},{2,4,6,8},{1,3,5,7}};
	int *b[3],**c;
	int i,j;

	
	b[0] = (int *)malloc(4 * sizeof(int));
	b[1] = (int *)malloc(5 * sizeof(int));
	b[2] = (int *)malloc(6 * sizeof(int));



	c = (int**)malloc(5*sizeof(int));
	c[0] = (int *)malloc(4 * sizeof(int));
	c[1] = (int *)malloc(4 * sizeof(int));
	c[2] = (int *)malloc(4 * sizeof(int));
	c[4] = (int *)malloc(7 * sizeof(int));
	
	c[4][6] = 3;
	b[2][6] = 1;
	b[1][6] = 2;
	printf("%d ",c[4][6]);
	printf("\n");
	printf("%d ",b[1][5]);
	printf("\n");
	printf("%d ",b[1][6]);
	free(c);
	free(b);
	return 0;

}