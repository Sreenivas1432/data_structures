//Find Minimum Cost Spanning Tree of a given undirected graph using Kruskal's algorithm ( C programming)
 
#include <stdio.h> 
#include <stdlib.h> 
#define MAX_EDGES 1000 
#define MAX_VERTICES 100 
typedef struct 
{     
	int from;
	int to;
	int weight; 
}Edge;
Edge edges[MAX_EDGES]; 
int parent[MAX_VERTICES];
int rank[MAX_VERTICES]; 
int num_vertices, num_edges;
void make_set(int vertex)
{
	parent[vertex] = vertex;     
	rank[vertex] = 0; 
} 
int find_set(int vertex) 
{     
	if (vertex != parent[vertex]) 
	{         
		parent[vertex] = find_set(parent[vertex]); 
    	} 
    	return parent[vertex]; 
}
void union_set(int x, int y) 
{     
	int root_x = find_set(x);     
	int root_y = find_set(y);     
	if (root_x != root_y) 
	{         
		if (rank[root_x] > rank[root_y]) 
		{             
			parent[root_y] = root_x; 
        	} 
		else 
		{             
			parent[root_x] = root_y;             
			if (rank[root_x] == rank[root_y]) 
			{                 
				rank[root_y]++; 
            	} 
        	} 
    	} 
}
int compare_edges(const void* a, const void* b) 
{
	Edge* edge1 = (Edge*)a;     
	Edge* edge2 = (Edge*)b;     
	return edge1->weight - edge2->weight; 
} 
void kruskal() 
{     
	int i, total_weight = 0; 
    	qsort(edges, num_edges, sizeof(Edge), compare_edges);     
	for (i = 0; i < num_vertices; i++) 
	{         
		make_set(i); 
    	} 
    	for (i = 0; i < num_edges; i++) 
	{         
		Edge edge = edges[i];         
		if (find_set(edge.from) != find_set(edge.to)) 
		{             
			union_set(edge.from, edge.to);             
			printf("(%d, %d) -> %d\n", edge.from, edge.to, edge.weight);             
			total_weight += edge.weight; 
        	} 
    	} 
    	printf("Total weight of MST: %d\n", total_weight); 
} 
int main() 
{
	int i; 
    	printf("Enter number of vertices: ");
	scanf("%d", &num_vertices);     
	printf("Enter number of edges: ");     
	scanf("%d", &num_edges);     
	printf("Enter edges (from to weight):\n");     
	for (i = 0; i < num_edges; i++) 
	{         
		scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].weight); 
    	} 
    	printf("Minimum Spanning Tree:\n"); 
    	kruskal();     
	return 0; 
} 
 
