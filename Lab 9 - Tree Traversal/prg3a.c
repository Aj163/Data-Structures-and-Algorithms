//Construct tree from preorder and inorder

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct binary_tree
{
	int data;
	struct binary_tree *left, *right;
}node;

void postorder(node *cur)
{
	if(cur==NULL)
		return;

	postorder(cur->left);
	postorder(cur->right);
	printf("%d ", cur->data);
}

node *get_new_node(int num)
{
	node *t = (node*)malloc(sizeof(node));
	t->left = NULL;
	t->right = NULL;
	t->data = num;
	return t;
}

node *get_tree(int pre[], int a, int b, int in[], int l, int r)
{
	if(l>r || a>b)
		return NULL;

	node *t = get_new_node(pre[a]);
	int i, m;

	//Search for root
	for(i=l; i<=r; i++)
		if(in[i] == pre[a])
			break;

	m = i-l;
	t->left = get_tree(pre, a+1, a+m, in, l, i-1);
	t->right = get_tree(pre, a+m+1, b, in, i+1, r);

	return t;
}

void main()
{
	int n, i;
	int pre[200], in[200];
	node *root = NULL;

	printf("\nEnter number of nodes : ");
	scanf("%d", &n);

	printf("Enter Preorder traversal : ");
	for(i=0; i<n; i++)
		scanf("%d", &pre[i]);

	printf("Enter Inorder traversal : ");
	for(i=0; i<n; i++)
		scanf("%d", &in[i]);

	root = get_tree(pre, 0, n-1, in, 0, n-1);
	printf("\nPostorder : ");
	postorder(root);
	printf("\n\n");
}