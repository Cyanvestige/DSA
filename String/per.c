#include <stdio.h>
int Pu(char *S,int k);
int Pu2(char *S,int l,int h);
void swap(char *a,char *b);
int main()
{
	char S[] = "ABCDE";
	Pu(S,0);
	Pu2(S,0,4);
	return 0;
}
void swap(char *a,char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
//Method 1
int Pu(char *S,int k)
{
	static int A[10] = {0};
	static char res[10];
	int i;
	if(S[k] == '\0')
	{
		res[k] = '\0';
		printf(res);
		printf("\n");
	}
	else
	{
		for(i = 0;S[i] != '\0';i++)
			if(A[i] == 0)
			{
				res[k] = S[i];
				A[i] = 1;
				Pu(S,k+1);
				A[i] = 0;
			}
	}
	
}

int Pu2(char *S,int l,int h)
{
	static int c = 1;
	int j;
	if(l == h)
	{
		printf("%d",c++);

		printf(S);
		printf("\n");
	}
	else
	
		for(j = l;j <= h;j++)
		{
			swap(&S[l],&S[j]);
			Pu2(S,l+1,h);
			swap(&S[l],&S[j]);
		}
}