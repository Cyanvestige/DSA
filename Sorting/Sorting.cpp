#include <iostream>
#include <vector>
using namespace std;
class BubbleSort{
	private:
		void Swap(vector<int>& v,int i,int j)
		{
			int tmp = v[i];
			v[i] = v[j];
			v[j] = tmp;
		}
	public:
		void Sort(vector<int>& v){
			for(int i = 0;i < v.size() - 1;i++)
				for(int j = 0;j < v.size() - 1 - i;j++)
					if(v[j] > v[j+1])
						Swap(v,j,j+1);
		}
};
class SelectionSort{
	private:
		void Swap(vector<int>& v,int i,int j)
		{
			int tmp = v[i];
			v[i] = v[j];
			v[j] = tmp;
		}
	public:
		void Sort(vector<int>& v){
			for(int i = 0;i < v.size();i++){
				int min = i;
				for(int j = i+1;j < v.size();j++)
					if(v[j] < v[min])
						min = j;	
				Swap(v,i,min);
			}
		}
};

class InsertionSort{
	private:
		void Swap(vector<int>& v,int i,int j)
		{
			int tmp = v[i];
			v[i] = v[j];
			v[j] = tmp;
		}
	public:
		void Sort(vector<int>& v){
			for(int i = 1;i < v.size();i++){
				for(int j = i;j > 0 && v[j-1] > v[j];j--){
					Swap(v,j-1,j);
				}
			}
		}
};

class MergeSort{
	private:
		
		void Merge(vector<int>& v,int lo,int mid,int hi){
			vector<int> aux(v);
			int i = lo;
			int j = mid+1;
			for(int k = lo; k <= hi;k++)
			{
				if(i > mid)                 v[k] = aux[j++];
				else if(j > hi)       		v[k] = aux[i++];
				else if(aux[j] < aux[i])    v[k] = aux[j++];
				else                        v[k] = aux[i++];
			}
		}
		void Sort(vector<int>& v,int lo,int hi){
			if(lo >= hi) return;
			int mid = lo + (hi - lo)/2;
			Sort(v,lo,mid);
			Sort(v,mid+1,hi);
			Merge(v,lo,mid,hi);
			
		}

		int Less(int a,int b){
			return a<b?a:b;
		}
		
	public:
		void Sort(vector<int>& v){
			Sort(v,0,v.size()-1);
		}
		void ItrSort(vector<int>& v,int lo){
			int N = v.size();
			for(int sz = 1;sz < N;sz +=sz)
				for(int lo = 0; lo < N - sz;lo += sz+sz)
					Merge(v,lo,lo+sz-1,Less(lo+sz+sz-1,N-1));
		}
};

class QuickSort{
	private:
		void Swap(vector<int>& v,int i,int j){
			int tmp = v[i];
			v[i] = v[j];
			v[j] = tmp;
		}
		bool Less(int a,int b){
			return a<b?true:false;
		}
		int Partition(vector<int>& v,int lo,int hi){
			int i = lo;
			int j = hi+1;
			while(true){
				while(Less(v[++i],v[lo]))
					if(i == hi) break;
				while(Less(v[lo],v[--j]))
					if(j == lo) break;
				if(j <= i) break;
				Swap(v,i,j);
			}
			Swap(v,lo,j);
			return j;
		}	
		void Sort(vector<int>& v,int lo,int hi){
			if(lo >= hi) return;
			int j = Partition(v,lo,hi);
			Sort(v,lo,j-1);
			Sort(v,j+1,hi);
		}
	public:
		void Sort(vector<int>& v){
			Sort(v,0,v.size()-1);
		}
};
void Print(vector<int>& input)
{
	for(auto i:input){
		cout<<i<<" ";
	}
	cout<<endl;
}

int main(){
	vector<int> v1 = {2,5,3,7};
	vector<int> v2 = {6,3,1,9};
	vector<int> v3 = {8,2,6,1};
	vector<int> v4 = {8,2,6,1,7,5,9,4};
	vector<int> v5 = {1,2,3,3,2,1,5,5,3,2,4,3,1};
	SelectionSort Sel;
	BubbleSort Bul;
	InsertionSort Ins;
	MergeSort Mer;
	QuickSort Qui;
	Qui.Sort(v1);
	Qui.Sort(v2);
	Qui.Sort(v3);
	Qui.Sort(v4);
	Mer.ItrSort(v5,0);
	Print(v1);
	Print(v2);
	Print(v3);
	Print(v4);
	Print(v5);
	return 0;
}