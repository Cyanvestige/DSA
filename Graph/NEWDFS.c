#include <stdio.h>
#include "Linkedstack.h"
int map[7][7] = {{0,0,0,0,0,0,0},
				 {0,0,1,0,0,1,0},
				 {0,1,0,1,0,0,0},
				 {0,0,1,0,1,0,0},
				 {0,0,0,1,0,0,0},
				 {0,1,0,0,0,0,1},
				 {0,0,0,0,0,1,0}};



void DFS(int A[][7],int start,int n)
{
	struct Node s;
	int visited[7] = {0};
	Push(start);
	while(!isEmpty()){
		int curr = Pop();
		if(!visited[curr]){
			visited[curr] = 1;
			printf("%d ",curr);
		}
		for(int i = n-1;i >= 1;i--){
			if(A[curr][i] == 1 && visited[i] == 0){
				Push(i);
			}
		}
	}

}

int main()
{
	DFS(map,1,7);
}