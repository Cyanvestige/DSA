#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int map[7][7] = {{0,0,0,0,0,0,0},
				 {0,0,1,0,0,1,0},
				 {0,1,0,1,0,0,0},
				 {0,0,1,0,1,0,0},
				 {0,0,0,1,0,0,0},
				 {0,1,0,0,0,0,1},
				 {0,0,0,0,0,1,0}};

void BFS(int map[][7],int start,int n){
	queue<int> q;
	q.push(start);
	vector<int> visited(7,0);
	while(!q.empty()){
		start = q.front();
		q.pop();
		visited[start] = 1;
		printf("%d ",start);
		for(int i = 0;i < n;i++){
			if(map[start][i] == 1 && visited[i] == 0){
				q.push(i);
			}
		}
	}
}

int main()
{
	BFS(map,1,7);
}