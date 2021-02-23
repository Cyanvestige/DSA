#include <stdio.h>
#include <limits.h>
int minDistance(int dist[], int sptSet[])
{
	int min = INT_MAX, min_index;
	for(int i = 0;i < 16;i++)
		if(sptSet[i] == 0  && dist[i] <= min){
			min = dist[i];
			min_index = i;
		}
	return min_index;
}

void printSolution(int dist[]){
	printf("Vertex \t\t Distance from Source\n");
	for(int i = 0;i < 16;i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[16][16], int src)
{
	int dist[16];
	int sptSet[16];
	for(int i = 0; i < 16;i++)
		dist[i] = INT_MAX, sptSet[i] = 0;

	dist[src] = 0;

	for(int count = 0;count < 15;count++){
		int u = minDistance(dist,sptSet);

		sptSet[u] = 1;

		for(int v = 0;v < 16;v++)
			if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	printSolution(dist); 
}
int main(){
	int graph[16][16] = { { 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
	                    { 1, 0, 2, 0, 1, 6, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
	                    { 0, 2, 0, 3, 0, 0, 5, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
	                    { 0, 0, 3, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0}, 
	                    { 3, 1, 0, 0, 0, 3, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0},
	                    { 0, 6, 0, 0, 3, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0}, 
	                    { 0, 2, 5, 0, 0, 2, 0, 1, 0, 1, 3, 2, 0, 0, 0, 0}, 
	                    { 0, 0, 1, 2, 0, 0, 1, 0, 0, 0, 0, 3, 0, 0, 0, 0}, 
	                    { 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 4, 5, 0, 0}, 
	                    { 0, 0, 0, 0, 1, 1, 1, 0, 2, 0, 2, 0, 0, 1, 5, 0}, 
	                    { 0, 0, 0, 0, 0, 0, 3, 0, 0, 2, 0, 2, 0, 0, 2, 3}, //10
	                    { 0, 0, 0, 0, 0, 0, 2, 3, 0, 0, 2, 0, 0, 0, 0, 1}, //11
	                    { 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 2, 0, 0}, //12
	                    { 0, 0, 0, 0, 0, 0, 0, 0, 5, 1, 0, 0, 2, 0, 1, 0}, 
	                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 2},
	                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 0, 0, 2, 0}
	                	}; 
	dijkstra(graph,0);
}
	  
