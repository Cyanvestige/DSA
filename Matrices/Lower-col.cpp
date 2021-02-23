#include <iostream>
using namespace std;
class Lower
{
	private:
		int n;
		int *A;
	public:
		Lower(int n)
		{
			this->n = n;
			A = new int[n];
		}
		~Lower(){delete []A;}
		void Set(int i,int j,int n);
		int Get(int i,int j);
		int GetDimension(int n){return n;}
		void Display();
};

void Lower::Set(int i,int j,int x)
{
	if(i >= j)
		A[((n+(n-(j-2)))*(j-1))/2 + i - j] = x;
}

int Lower::Get(int i,int j)
{
	if(i >= j)
		return A[((n+(n-(j-2)))*(j-1))/2 + i - j];
	return 0;
}

void Lower::Display()
{
	int i,j;
	for(i = 1;i <= n;i++)
	{
		for(j = 1;j <= n;j++)
		{
			if(i >= j)
				cout<<A[((n+(n-(j-2)))*(j-1))/2 + i - j]<<" ";
			else
				cout<<"0 ";
		}
		cout<<"\n";
	}
}

int main()
{
	int n;
	cout<<"Enter the Dimension";
	cin>>n;
	cout<<"Enter all the elements";
	Lower matrix(n);
	int i,j;
	int x;
	for(i = 1;i <= n;i++)
	{
		for(j = 1;j <= n;j++)
		{
			cin>>x;
			matrix.Set(i,j,x);
		}
	}
	matrix.Display();
	return 0;
}