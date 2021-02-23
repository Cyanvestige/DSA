#include <stdio.h>
#include "Queue.h"
int map[][7] = {{0,0,0,0,0,0,0},
						{0,0,1,1,0,0,0},
						{0,1,0,0,1,0,0},
						{0,1,0,0,1,0,0},
						{0,0,1,1,0,1,1},
						{0,0,0,0,1,0,0},
						{0,0,0,0,1,0,0}};

void BFS(int B[][7],int start,int n)
{
	struct Queue A;
	A.size = 8;
	A.Q = (int*)malloc(A.size * sizeof(int));
	A.front = A.rear = 0;
    static int visited[7] = {0};
	int v;
	printf("%d",start);
	
	Enque(&A,start);
	
	visited[start] = 1;
	while(!isEmpty(&A))
	{
		start = Deque(&A);
		for(v = 1;v <= 7;v++)
		{
			if(map[start][v] == 1 && visited[v] == 0)
			{
				printf("%d",v);
				visited[v] = 1;
				Enque(&A,v);

			}
		}
	} 
}

int main()
{
	
	


	BFS(map,1,7);
	


}