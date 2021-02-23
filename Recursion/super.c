#include <stdio.h>
int FiboRec(int a)
{
	if(a <= 1)return a;
	return FiboRec(a-2)+Fibo(a-1);
}

int rfib(int n)
{
 	if(n<=1)return n;
 	return rfib(n-2)+rfib(n-1);
}

int main()
{
	printf("%d\n ",FiboRec(0));
	printf("%d\n ",rfib(0));
	return 0;
}