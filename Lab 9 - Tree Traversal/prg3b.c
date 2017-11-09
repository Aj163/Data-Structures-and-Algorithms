//Construct tree from postorder and inorder

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct binary_tree
{
	int data;
	struct binary_tree *left, *right;
}node;

void preorder(node *cur)
{
	if(cur==NULL)
		return;

	printf("%d ", cur->data);
	preorder(cur->left);
	preorder(cur->right);
	
}

node *get_new_node(int num)
{
	node *t = (node*)malloc(sizeof(node));
	t->left = NULL;
	t->right = NULL;
	t->data = num;
	return t;
}

node *get_tree(int post[], int a, int b, int in[], int l, int r)
{
	if(l>r || a>b)
		return NULL;

	node *t = get_new_node(post[b]);
	int i, m;

	//Search for root
	for(i=l; i<=r; i++)
		if(in[i] == post[b])
			break;

	m = i-l;
	t->left = get_tree(post, a, a+m-1, in, l, i-1);
	t->right = get_tree(post, a+m, b-1, in, i+1, r);

	return t;
}

void main()
{
	int n, i;
	int post[200], in[200];
	node *root = NULL;

	printf("\nEnter number of nodes : ");
	scanf("%d", &n);

	printf("Enter Postorder traversal : ");
	for(i=0; i<n; i++)
		scanf("%d", &post[i]);

	printf("Enter Inorder traversal : ");
	for(i=0; i<n; i++)
		scanf("%d", &in[i]);

	root = get_tree(post, 0, n-1, in, 0, n-1);
	printf("\nPreorder : ");
	preorder(root);
	printf("\n\n");
}