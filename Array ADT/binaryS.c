#include <stdio.h>
#include <stdlib.h>

int B(int A[],int key,int h)
{
	int l,mid;
	l = 0;
	while(1)
	{
		mid = (l + h)/2;
		if(l == h)
			return h;
		else
		{	
			if(A[mid] > key)
				h = mid;
			else
				l = mid + 1;
		}
	}	
}

int main()
{
	int A[] = {1,2,7,8,9,12,16};
	int answer;
	answer = B(A,1,7);
	printf("%d\n",answer);
	return 0;
}
