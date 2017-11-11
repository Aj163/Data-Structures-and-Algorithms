//To check if a tree is a Binary Search Tree

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define inf ((int)(1e9))

typedef struct binary_tree
{
	int data;
	struct binary_tree *left, *right;
}node;

node *get_new_node(int num)
{
	node *t = (node*)malloc(sizeof(node));
	t->left = NULL;
	t->right = NULL;
	t->data = num;
	return t;
}

int bst(node *cur, int a, int b)
{
	if(cur == NULL)
		return 1;

	if(a < cur->data && cur->data < b)
		return (bst(cur->left, a, cur->data) & bst(cur->right, cur->data, b));
	return 0;
}

void add(int num, node *cur)
{
	int ch;
	node *t;

	printf("\nCurrent node : %d\n", cur->data);
	printf("Traverse left(0)/right(1) ? ");
	scanf("%d", &ch);

	if(ch==0)
	{
		if(cur->left)
			add(num, cur->left);
		else
			cur->left = get_new_node(num);
	}
	else
	{
		if(cur->right)
			add(num, cur->right);
		else
			cur->right = get_new_node(num);
	}
}

void print_tree(node *cur)
{
	int flag=0;

	if(cur==NULL)
	{
		printf("#");
		return;
	}

	printf("%d", cur->data);

	if(cur->left)
	{
		printf("(");
		print_tree(cur->left);
		flag=1;
	}
	if(cur->right)
	{
		if(!flag)
			printf("(#,");
		else
			printf(",");

		print_tree(cur->right);
		flag=2;
	}

	if(flag==1)
		printf(",#");

	if(flag)
		printf(")");
}

void main()
{
	int ch;
	node *root = NULL;

	do
	{
		printf("\nCurrent tree : ");
		print_tree(root);

		printf("\n1. Insert node\n2. Check if BST\nx. Exit");
		printf("\nEnter your choice : ");
		scanf("%d", &ch);

		if(ch==1)
		{
			printf("\nEnter data : ");
			scanf("%d", &ch);

			if(!root)
				root = get_new_node(ch);
			else
				add(ch, root);

			ch=1;
		}
		else if(ch==2)
		{
			if(bst(root, -inf, inf))
				printf("\nIt is a BST\n");
			else
				printf("\nIt is not a BST\n");
			ch=1;
		}
		
	}while(ch==1);
}

/*

Test Case 1:
1 5
1 2 0
1 8 1
1 4 0 1
1 0 0 0
1 6 1 0
1 3 0 1 0

Output:
It is a BST

     5
   /   \
  2     8
 / \   /
0   4 6
   /
  3 

x-------------x

Test Case 2:
1 5
1 2 0
1 1 1
1 4 0 1
1 0 0 0
1 6 1 0
1 3 0 1 0

Output:
It is a BST

     5
   /   \
  2     8
 / \   /
0   4 1
   /
  3 

*/