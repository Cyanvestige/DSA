#include <stdio.h>
int Fact(int n)
{
	if(n == 0)
		return 1;
	return n * Fact(n - 1);
}

int main()
{
	printf("%d",Fact(5));
	return 0 ;
}