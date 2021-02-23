#include <stdio.h>
/*iteration:
int fib(int n)
{
	int a = 0, b = 1;
	int i;
	int sum;
	if(n == 0)
		return a;
	else if(n == 1)
		return b;
	else
		for(i = 2;i <= n;i++)
		{
			sum = a + b;
			a = b;
			b = sum;
		}
	return sum;
}*/

/*Normal Recursion:
int fib(int n)
{
	if(n <= 1)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}*/

//Recursion with Memorization:
int fib(int n)
{
	int i;
	int Fib[10];
	for(i = 0;i < 10;i++)
		Fib[i] = -1;
	if(n <= 1)
	{
		Fib[n] = n;
		return n;
	}
	else
	{
		if(Fib[n-1] == -1)
			Fib[n-1] = fib(n-1);
		if(Fib[n-2] == -1)
			Fib[n-2] = fib(n-2);
		return Fib[n-2] + Fib[n-1];
	}
}

int main()
{
	printf("%d",fib(6));
	return 0;
}
