#include<stdio.h>
int TOH(int n,int a,int b,int c)
{
	static int time = 0;
	if(n >= 0){
		TOH(n - 1,a,c,b);
		printf("move from %d to %d\n",a,c);
		time++;
		TOH(n - 1,b,a,c);
	}
	return time;
}

int main()
{
	printf("%d",TOH(3,1,2,3));
	return 0;	
}