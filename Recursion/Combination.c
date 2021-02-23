#include <stdio.h>
int factorial(int n)
{
	int i;
	int re = 1;
	for(i = 1;i <= n;i++)
	{
		re *= i; 
	}
	return re;
}

/*factorial:
int Combi(int n, int r)
{
	return factorial(n) / (factorial(r) * factorial(n-r));
}
*/
//Recursion with Pascal Triangle:
int Combi(int n,int r)
{
	if(r == 0 || r == n)
		return 1;
	else
		return Combi(n-1,r) + Combi(n-1,r-1); 
}

int main()
{
	printf("%d",Combi(4,2));
}