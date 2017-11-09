//Binary tree - Mirror Image

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void create_mirror(node *r1, node *r2)
{
	if(r1==NULL)
		return;
	r2->data = r1->data;

	if(r1->left != NULL)
	{
		r2->right = get_new_node(0);
		create_mirror(r1->left, r2->right);
	}
	if(r1->right != NULL)
	{
		r2->left = get_new_node(0);
		create_mirror(r1->right, r2->left);
	}
}

void main()
{
	int ch;
	node *root = NULL, *root_mir = NULL;

	do
	{
		printf("\nCurrent tree : ");
		print_tree(root);
		printf("\n");

		printf("\n1. Add node\n2. Create Mirror Image\nx. Exit");
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
			printf("\nMirror Image : ");
			if(root != NULL)
				root_mir = get_new_node(0);
			else
				root_mir = NULL;

			create_mirror(root, root_mir);
			print_tree(root_mir);
		}

	}while(ch>=1 && ch<=2);
}