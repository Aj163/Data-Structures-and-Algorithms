//Check for cycle in an undirected graph : O(V+E)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define inf ((int)(1e9))
#define N 1000

typedef struct graph_adj_list
{
	int node;
	struct graph_adj_list *next;
}node;

int V, E, flag=0;
int vis[N] = {0}, done[N] = {0};
node *adj[N] = {NULL};

void dfs(int x)
{
	node *temp = adj[x];
	done[x] = 1;

	while(temp != NULL)
	{
		if(vis[temp->node] == 0)
		{
			vis[temp->node] = 1;
			dfs(temp->node);
			vis[temp->node] = 0;
		}
		else
		{
			flag=1;
			return;
		}
		temp = temp->next;
	}
}

int main()
{
	int i, x, y;
	node *temp;

	printf("\nEnter the number of vertices and edges : ");
	scanf("%d%d", &V, &E);

	printf("\nEnter the pair of edges(directed) (i, j) where 0<=i,j<n\n");
	for(i=0; i<E; i++)
	{
		scanf("%d%d", &x, &y);

		temp = (node*)malloc(sizeof(node));
		temp->next = adj[x];
		temp->node = y;
		adj[x] = temp;
	}

	for(i=0; i<V; i++)
		if(done[i]==0)
		{
			vis[i]=1;
			dfs(i);
		}

	if(flag)
		printf("\nCycle Present.\n\n");
	else
		printf("\nNo cycle present.\n\n");
}

/*

Test Case 1:
6 8
5 3
2 3
2 1
4 5
1 4
0 1
0 4
0 5

Output:
No cycle present.

x---------------x

Test Case 2:
6 9
5 3
2 3
2 1
4 5
1 4
0 1
0 4
0 5
5 2

Output:
Cycle Predent.

*/