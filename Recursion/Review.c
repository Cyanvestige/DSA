#include <stdio.h>
int Sum(int n)
{
	if(n == 0)
		return 0;
	return n + Sum(n-1);
}

int Factorial(int n)
{
	if(n == 0)
		return 1;
	return n * Factorial(n-1);
}

int Power(int n,int exp)
{
	if(exp == 0)
		return 1;
	return n * Power(n,exp - 1);
}

int Power2(int n,int exp)
{
	if(exp == 0)
		return 1;
	if(exp % 2 != 0)
		return n * Power2(n*n,(exp-1)/2);
	else
		return Power2(n*n,exp/2);
}

double Taylor(int a,int n)
{
	static double P = 1,F = 1;
	static double R;

	if(n == 0)
		return 1;
	R = Taylor(a,n-1);//forgot R =
	P = P * a;
	F = F * n;
	return R + P/F;
}

double Taylor2(int a,int n)
{
	int i;
	static double r = 0;
	for(i = n;i > 0;i--)
		r = 1 + a*r/i;
	return r;
}

double Taylor2Recursive(int a,int n)
{
	static double r;
	if(n == 0)
		return r;
	r = 1 + a*r/n;
	return Taylor2Recursive(a,n-1);
}

int Fibo(int a)
{
	int n0 = 0,n1 = 1,s = 0;
	int i;
	for(i = 0;i < a;i++)
	{
		s = n0 + n1;
		n0 = n1;
		n1 = s;
	}
	return s;
}

int FiboRec(int a)
{
	if(a <= 1)return a;
	return FiboRec(a-2)+FiboRec(a-1);
}

int rfib(int n)
{
 	if(n<=1)return n;
 	return rfib(n-2)+rfib(n-1);
}

int FiboRecMemo(int a)
{
	int i;
	int F[10];
	for(i = 0;i < 10;i++)
		F[i] = -1;
	if(a <= 1)
	{	
		F[a] = a;
		return a;
	}

	else
	{
		if(F[a-1] == -1)
			F[a-1] = FiboRecMemo(a-1);
		if(F[a-2] == -1)
			F[a-2] = FiboRecMemo(a-2);
		return F[a-2] + F[a-1];
	}

}


int TOH(int n,int a,int b,int c)
{
	static int time = 0;
	if(n >= 0)
	{
		TOH(n - 1,a,c,b);
		printf("move from %d to %d",a,c);
		time++;
		TOH(n - 1,b,a,c);
	}
	return time;
}

int main()
{
	printf("%d ",Sum(5));
	printf("%d ",Factorial(5));
	printf("%d ",Power(2,5));
	printf("%d ",Power2(2,5));
	printf("%f ",Taylor(3,10));
	printf("%f ",Taylor2(3,10));
	printf("%f ",Taylor2Recursive(3,10));
	printf("%d\n ",Fibo(5));
	printf("%d\n ",FiboRec(5));
	printf("%d\n ",rfib(5));
	printf("%d ",FiboRecMemo(5));
	printf("%d ",TOH(3,1,2,3));

	return 0;
}