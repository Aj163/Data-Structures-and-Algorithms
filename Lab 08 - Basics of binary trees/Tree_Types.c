//Full, Complete, Perfect

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max(a, b) (a>b ? a : b)

typedef struct binary_tree
{
	int data;
	struct binary_tree *left, *right;
}node;

int total_nodes = 0;

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

int check_full(node *cur)
{
	if(cur==NULL)
		return 1;

	if(cur->left == NULL && cur->right != NULL)
		return 0;
	if(cur->left != NULL && cur->right == NULL)
		return 0;

	return (check_full(cur->left) & check_full(cur->right));
}

int check_complete(node *cur, int node_num)
{
	if(cur==NULL)
		return 1;
	if(node_num > total_nodes)
		return 0;

	return (check_complete(cur->left, node_num*2) & check_complete(cur->right, node_num*2 +1));
}

int get_height(node *cur)
{
	if(cur==NULL)
		return 0;

	return max(get_height(cur->left), get_height(cur->right)) +1;
}

int check_perfect(node *cur)
{
	if((1<<get_height(cur)) == total_nodes+1)
		return 1;
	return 0;
}

void main()
{
	int ch;
	node *root = NULL;

	do
	{
		printf("\n\nCurrent tree : ");
		print_tree(root);
		printf("\n");

		printf("\n1. Add node\n2. Check for full binary tree");
		printf("\n3. Check for complete binary tree\n4. Check for perfect binary tree\nx. Exit");
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

			total_nodes++;
			ch=1;
		}
		else if(ch==2)
		{
			if(check_full(root))
				printf("\nFull Binary Tree\n");
			else
				printf("\nNot a Full Binary Tree\n");
		}
		else if(ch==3)
		{
			if(check_complete(root, 1))
				printf("\nComplete Binary Tree\n");
			else
				printf("\nNot a Complete Binary Tree\n");
		}
		else if(ch==4)
		{
			if(check_perfect(root))
				printf("\nPerfect Binary Tree\n");
			else
				printf("\nNot a Perfect Binary Tree\n");
		}

	}while(ch>=1 && ch<=4);
}

/*

Test Case 1:
1 1
1 2 0
1 3 1
1 4 0 0
1 5 0 1
1 6 1 0

Output:
Complete

x-------------x

Test Case 2:
1 1
1 2 0
1 3 1
1 4 0 0
1 5 0 1

Output:
Complete
Full

x-------------x

Test Case 3:
1 1
1 2 0
1 3 1
1 4 0 0
1 5 0 1
1 7 1 1

Output:
NONE

x-------------x

Test Case 4:
1 1
1 2 0
1 3 1
1 6 1 0
1 7 1 1

Output:
Full

x-------------x

Test Case 5:
1 1
1 2 0
1 3 1
1 4 0 0
1 5 0 1
1 6 1 0
1 7 1 1

Output:
Full
Complete
Perfect

*/