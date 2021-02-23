#include <iostream>
using namespace std;
class Diagonal
{
	private:
		int n;
		int *A;
	public:
		Diagonal(int n)
		{
			this->n = n; 
			A = new int[n];
		}
		~Diagonal(){delete []A;}
		void Set(int i,int j,int x)
		{
			if(i == j)
				A[i-1] = x;
		}

		int Get(int i,int j)
		{
			if(i == j)
				return A[i-1];
			return 0;
		}
		void Display()
		{
			for(int i = 1;i <= n;i++)
			{
				for(int j = 1;j <= n;j++)
				{
					if(i == j)
						cout<<A[i - 1]<<" ";
					else
						cout<<"0";
				}
				cout << endl;
			}
		}
		int GetDimension(int n){return n;}
};

int main()
{
	int i,j,d;
	cout<<"Enter the Dimension";
	cin>>d;
	Diagonal dm(d);

	int x;
	cout << "Enter All Elements";
	for (i = 1; i <= d; i++)
	{
		for (j = 1; j <= d; j++)
		{
			cin >> x;
			dm.Set(i, j, x);
		}
	}

	dm.Display();
	return 0;
}
