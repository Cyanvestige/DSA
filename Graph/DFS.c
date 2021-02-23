#include <stdio.h>
#include "Stack.h"
int map[7][7] = {{0,0,0,0,0,0,0},
				 {0,0,1,0,0,1,0},
				 {0,1,0,1,0,0,0},
				 {0,0,1,0,1,0,0},
				 {0,0,0,1,0,0,0},
				 {0,1,0,0,0,0,1},
				 {0,0,0,0,0,1,0}};



void DFS(int A[][7],int start,int n)
{
	int v;
	static int visited[7] = {0};
	if(visited[start] == 0)
	{
		printf("%d",start);
		visited[start] = 1;
		for(v = 1;v < 7;v++)
		{
			if(map[start][v] == 1 && visited[v] == 0)
				DFS(map,v,n);
		}
	}
}

int main()
{
	
	DFS(map,1,7);
	


}