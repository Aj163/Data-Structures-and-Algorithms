//DFS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct linked_list
{
	int data;
	struct linked_list *next;
}node;

int n, m;
int vis[500] = {0};
node *adj[500] = {NULL};

void dfs(int x)
{
	node *t = adj[x];

	if(vis[x])
		return;
	printf("%d ", x);
	vis[x] = 1;

	while(t != NULL)
	{
		dfs(t->data);
		t = t->next;
	}
}

void main()
{
	int i, a, b;
	node *t;

	printf("\nEnter number of nodes and edges : ");
	scanf("%d%d", &n, &m);

	printf("\nEnter the pair of edges(undirected) (i j) where 0<=i,j<n\n");
	for(i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);

		t = (node *)malloc(sizeof(node));
		t->data = b;
		t->next = adj[a];
		adj[a] = t;

		t = (node *)malloc(sizeof(node));
		t->data = a;
		t->next = adj[b];
		adj[b] = t;		
	}
	
	printf("\nOrder of traversal of nodes.\n");
	for(i=0; i<n; i++)
		if(vis[i] == 0)
			dfs(i);

	printf("\n\n");
}

/*

Graph Input :

7 8
3 4
3 0
4 2
0 2
2 6
2 1
1 5
0 1

*/