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
int vis[N] = {0};
node *adj[N] = {NULL};

void dfs(int x, int par)
{
	node *temp = adj[x];

	while(temp != NULL)
	{
		if(vis[temp->node] == 0)
		{
			vis[temp->node] = 1;
			dfs(temp->node, x);
		}
		else if(temp->node != par)
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

	printf("\nEnter the pair of edges(undirected) (i, j) where 0<=i,j<n\n");
	for(i=0; i<E; i++)
	{
		scanf("%d%d", &x, &y);

		temp = (node*)malloc(sizeof(node));
		temp->next = adj[x];
		temp->node = y;
		adj[x] = temp;

		temp = (node*)malloc(sizeof(node));
		temp->next = adj[y];
		temp->node = x;
		adj[y] = temp;
	}

	for(i=0; i<V; i++)
		if(vis[i]==0)
		{
			vis[i]=1;
			dfs(i, -1);
		}

	if(flag)
		printf("\nCycle Present.\n\n");
	else
		printf("\nNo cycle present.\n\n");
}

/*

Test Case 1:
6 6
1 0
2 4
4 3
5 3
0 2
4 5

Output:
Cycle Predent.

x---------------x

Test Case 2:
5 2
3 2
3 2

Output:
Cycle Predent.

x---------------x

Test Case 3:
3 2
1 2
3 2

Output:
No cycle present.

*/