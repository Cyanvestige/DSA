#include<stdio.h>
void toBin(int a)
{
	int k;
	k = a % 2;
	a = a / 2;
	if(a != 0)
		toBin(a);

	printf("%d",k);  
}

int main()
{
	toBin(24);
}
