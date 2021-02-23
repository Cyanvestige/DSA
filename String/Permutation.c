#include <stdio.h>
void swap(char * a,char *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Permu(char S[],int k)
{
	static int A[10] = {0};
	static char Rec[10];
	int i;
	if(S[k] == '\0')
	{
		Rec[k] = '\0';
		printf(Rec);
	}
	else	
	{
		for(i = 0;S[i] != '\0';i++)
		
			if(A[i] == 0)
			{
				Rec[k] = S[i];
				A[i] = 1;
				Permu(S,k+1);
				A[i] = 0;
			}
		
	}
}

void Permu2(char S[],int l)
{
	int i;
	static int c = 1;
	if(l <= 1 && c <= 300)
	{
		printf("%d",c++);
		printf("%s\n",S);
	}
	else
	{
		int n1 = l - 1;
		
		for(i = 0;i < l;i++)
		{
			swap(&S[n1],&S[i]);
			Permu2(S,n1);
			swap(&S[n1],&S[i]);
		}
	
	}

}

int main()
{
	char S[] = "ABC";
	Permu2(S,3);
	return 0;
}