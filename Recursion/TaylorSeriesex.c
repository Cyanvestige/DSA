#include <stdio.h>
/*double e(int x,int n)
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
*/

/*double e(int x,int n)
{
	int i;
	double r = 1.0;
	for(;n > 0;n--)
	{
		r = 1 + x*r/n; 
	}
	return r;
}
*/

double e(int x,int n)
{
	static double s = 1;
	if (n == 0)
		return s;

	s = 1 + x*s/n;
	return e(x,n-1);

}


int main()
{
	printf("%f",e(3,10));
	return 0;
}
