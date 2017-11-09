//To check if a tree is a Binary Search Tree

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define inf ((int)(1e9))

typedef struct binary_tree
{
	int data;
	int maxi, mini;
	int min, max;
	struct binary_tree *left, *right;
}node;

node *get_new_node(int num)
{
	node *t = (node*)malloc(sizeof(node));
	t->left = NULL;
	t->right = NULL;

	t->mini = inf;
	t->min = inf;

	t->maxi = -inf;
	t->max = -inf;

	t->data = num;
	return t;
}

int bst(node *cur)
{
	if(cur == NULL)
		return 1;
	if((cur->maxi < cur->mini) && (cur->maxi < cur->data) && (cur->mini > cur->data))
		return bst(cur->left)*bst(cur->right);
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
		if(cur->min > num)
			cur->min = num;
		if(cur->max < num)
			cur->max = num;

		if(cur->left)
		{
			add(num, cur->left);
			if(cur->maxi < num)
				cur->maxi = num;
		}
		else
		{
			t = get_new_node(num);
			cur->left = t;
			cur->maxi = num;
			t->max = t->min = num;
			
		}

	}
	else
	{
		if(cur->min > num)
				cur->min = num;
			if(cur->max < num)
				cur->max = num;

		if(cur->right)
		{
			add(num, cur->right);
			if(cur->mini > num)
				cur->mini = num;
		}
		else
		{
			t = get_new_node(num);
			cur->right = t;
			cur->mini = num;
			t->max = t->min = num;
			
		}
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

		//if(root)
		//printf("\n%d__%d__%d__%d\n", root->mini, root->min, root->maxi, root->max);

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
			if(bst(root))
				printf("\nIt is a BST\n");
			else
				printf("\nIt is not a BST\n");
			ch=1;
		}
		
	}while(ch==1);
}