#include <stdio.h>
int toBin(int a)
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
	char A[] = "solution";
	int i;
	long int x,h;
	h = 0;
	x = 0;
	for(i = 0;A[i] != '\0';i++)
	{
		x = 1;
		x = x<<A[i] - 97;
		if((x & h) > 0)
			printf("%c is duplicated",A[i]);
		else
			h = x | h;

	}
	return 0;
}


