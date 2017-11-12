//Single Source Shortest Path using DFS and topological sort : O(V+E)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define inf ((int)(1e9))
#define N 1000

typedef struct graph_adj_list
{
	int node;
	int weight;
	struct graph_adj_list *next;
}node;

int V, E, pos;
int ver[N], vis[N] = {0}, dis[N];
node *adj[N] = {NULL};

void dfs(int x)
{
	node *temp = adj[x];

	if(vis[x])
		return;
	vis[x] = 1;

	while(temp != NULL)
	{
		dfs(temp->node);
		temp = temp->next;
	}

	ver[pos--] = x;
}

void topological_sort()
{
	int i;
	pos = V-1;
	for(i=0; i<V; i++)
		if(vis[i]==0)
			dfs(i);
}

void shortest_paths()
{
	int i;
	node *temp;

	for(i=0; i<N; i++)
		dis[i] = inf;
	dis[0] = 0;

	for(i=0; i<V; i++)
	{
		temp = adj[ver[i]];
		while(temp != NULL)
		{
			if(dis[temp->node] > dis[ver[i]] + temp->weight)
				dis[temp->node] = dis[ver[i]] + temp->weight;

			temp = temp->next;
		}
	}
}

int main()
{
	int i, min_cost, x, y, w;
	node *temp;

	printf("Enter number of nodes and edges : ");
	scanf("%d%d", &V, &E);

	printf("\nEnter the pair of edges(directed) with thier weights (i, j, w) where 0<=i,j<n which form a DAG\n");
	for(i=0; i<E; i++)
	{
		scanf("%d%d%d", &x, &y, &w);
		temp = (node *)malloc(sizeof(node));
		temp->node = y;
		temp->weight = w;
		temp->next = adj[x];
		adj[x] = temp;
	}

	topological_sort();
	shortest_paths();

	printf("\nMinimum distance from sorce vertex(0) for node 0 to %d are\n", V-1);
	for(i=0; i<V; i++)
		printf("%d ", dis[i]);

	printf("\n\n");
}

/*

Test Case 1:
6 9
0 2 3
5 3 5
2 3 1
2 1 8
4 5 3
1 4 1
0 1 2
0 4 7
0 5 1

Output:
0 2 3 4 3 1

*/