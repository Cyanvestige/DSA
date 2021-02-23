#include <stdio.h>

int power(int x,int n)
{
	if (n == 0)
		return 1;
	return x * power(x,n-1);
}

/*
int power(int m,int n)
{
	if (n == 0)
		return 1;
	if(n % 2 == 0)
		return power(m * m,n / 2);
	else
		return m * power(m * m,(n - 1) / 2);
}*/
 
int main(){
	printf("%d",power(2,9));
	return 0;
}

