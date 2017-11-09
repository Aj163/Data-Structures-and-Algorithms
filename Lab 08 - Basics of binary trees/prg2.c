//Binary tree - Insert, Delete, Search

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int flag;
typedef struct binary_tree
{
	int data;
	struct binary_tree *left, *right;
}node;

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

node *get_new_node(int num)
{
	node *t = (node*)malloc(sizeof(node));
	t->left = NULL;
	t->right = NULL;
	t->data = num;
	return t;
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
		{
			t = get_new_node(num);
			cur->left = t;
		}
	}
	else
	{
		if(cur->right)
			add(num, cur->right);
		else
		{
			t = get_new_node(num);
			cur->right = t;
		}
	}
}

void check_full(node *cur)
{
	if(cur==NULL)
		return;

	if(cur->left == NULL && cur->right != NULL)
	{
		flag=0;
		return;
	}
	if(cur->left != NULL && cur->right == NULL)
	{
		flag=0;
		return;
	}

	check_full(cur->left);
	check_full(cur->right);
}

void main()
{
	int ch;
	node *root = NULL;

	do
	{
		printf("\nCurrent tree : ");
		print_tree(root);
		printf("\n");

		printf("\n1. Add node\n2. Check for full binary tree\nx. Exit");
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
			flag=1;
			check_full(root);
			if(flag)
				printf("\nFull Binary Tree\n");
			else
				printf("\nNot a Full Binary Tree\n");
		}

	}while(ch>=1 && ch<=2);
}