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
		void Set(int i,int j,int x);
		int Get(int i,int j);
		void Display();
		int GetDimension(int n){return n;}
};

void Lower::Set(int i,int j,int x)
{
	if(i >= j)
		A[(1+(i-1))*(i-1)/2 + j] = x;
}

int Lower::Get(int i,int j)
{
	if(i >= j)
		return A[(1+(i-1))*(i-1)/2 + j];
	return 0;
}

void Lower::Display()
{
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(i >= j)
				cout<<A[(1+(i-1))*(i-1)/2 + j]<<" ";
			else
				cout<<"0 ";
		}
		cout << endl;
	}
}

int main()
{
	int di;
	cout<<"Enter the Dimention";
	cin>>di;
	Lower Matrix(di);
	cout << "Enter All Elements";
	int x;
	for(int i = 1;i <= di;i++)
		for(int j = 1;j <= di;j++)
		{
			cin>>x;
			Matrix.Set(i,j,x);
		}
	Matrix.Display();
}

