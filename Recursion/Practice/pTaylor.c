#include<stdio.h>
double taylorE(int x,int n)
{
	static double P = 1,F = 1;
	double R;
	if(n == 0)
		return 1;
	R = taylorE(x,n-1);
	F *= n;
	P *= x;
	
	return R + P/F; 
}

//method 2
double e(int x, int n)
{
	int i;
	double r = 1.0;
	for(i = n;i > 0;i--)
	{
		r = 1 + x*r / i;
	}
	return r;
}
//method 3
double e2(int x, int n)
{
	static double r = 1.0;
	if(n == 0)
		return r;
	r = 1 + x*r / n;
	return e2(x,n-1);

}

int main()
{
	printf("%f\n",taylorE(3,10));
	printf("%f",e(3,10));
	printf("%f",e2(3,10));

}