#include <stdio.h>
//method 1
/*
int power(int n,int e)
{
	if(e == 0)
		return 1;
	return power(n,e-1) * n;
}*/
//method2
int power(int n,int e)
{
	if(e == 0)
		return 1;
	if(e % 2 != 0)
		return n * power(n*n,(e-1)/2);
	return power(n*n,e/2);
}

int main()
{
	printf("%d",power(2,3));
	return 0;
}

