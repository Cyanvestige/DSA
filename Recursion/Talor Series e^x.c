#include <stdio.h>
double e(int x,int n)
{
	static double F = 1,P = 1;
	double R;
	if(n == 0)
		return 1;
	
	R = e(x,n - 1);
	F *= n;
	P *= x;
	return R + P/F; 
	
}

int main()
{
	printf("%f",e(2,4));
	return 0;
}