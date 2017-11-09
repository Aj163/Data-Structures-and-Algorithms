//Binary tree - Insert, Delete, Search

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

int search(int num, node *cur)
{
	if(!cur)
		return 0;
	if(cur->data == num)
		return 1;
	return search(num, cur->left) | search(num, cur->right);
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

void delete(node *cur)
{
	int ch;

	if(!cur)
		return;

	printf("\nCurrent node : %d\n", cur->data);
	printf("Traverse left(0)/right(1) OR delete left(2)/right(3) child ? ");
	scanf("%d", &ch);

	if(ch==0)
		delete(cur->left);
	if(ch==1)
		delete(cur->right);
	if(ch==2)
		cur->left = NULL;
	if(ch==3)
		cur->right = NULL;
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

		printf("\n1. Add node\n2. Delete node\n3. Search node\nx. Exit");
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
			printf("\nDelete root node ? yes(1)/no(0) : ");
			scanf("%d", &ch);

			if(ch)
			{
				free(root);
				root = NULL;
			}
			else
				delete(root);

			ch=2;
		}
		else if(ch==3)
		{
			printf("Enter data to search : ");
			scanf("%d", &ch);
			if(search(ch, root))
				printf("Element present\n");
			else
				printf("Element not present\n");

			ch=3;
		}

	}while(ch>=1 && ch<=3);
}