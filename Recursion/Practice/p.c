#include <stdio.h>
int Fibo(int n)
{
	int i,s,n0,n1;
	n0 = 0;
	n1 = 1;
	if(n == 0)
		return n0;
	if(n == 1)
		return n1;
	for(i = 2;i <= n;i++)
	{
		s = n0 + n1;
		n0 = n1;
		n1 = s;
	}
	return s;
}

int FiboRec(int n)
{
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	return FiboRec(n-1) + FiboRec(n-2);
}

int FiboRecX(int n)
{
	int i,F[n];
	for(i = 0;i < n;i++)
		F[i] = -1;
	if(n <= 1)
	{
		F[n] = n;
		return F[n];
	}
	else
	{
		if(F[n-1] == -1)
			F[n-1] = FiboRecX(n-1);
		if(F[n-2] == -1)
			F[n-2] = FiboRecX(n-2);
		return F[n-1] + F[n-2];
	}

}

int main()
{
	for(int i = 0;i < 10;i++)
		printf("%d ",FiboRecX(i));
	return 0;
}