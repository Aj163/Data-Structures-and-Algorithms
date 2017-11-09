//Binary Search Tree
//get_max, get_min
//Print path to search

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct binary_tree
{
	int data;
	struct binary_tree *left, *right;
}node;
node *root = NULL;

node *get_new_node(int num)
{
	node *t = (node*)malloc(sizeof(node));
	t->left = NULL;
	t->right = NULL;
	t->data = num;
	return t;
}

void insert(node *cur, int num)
{
	if(cur == NULL)
		root = get_new_node(num);
	else if(num < cur->data)
	{
		if(cur->left)
			insert(cur->left, num);
		else
			cur->left = get_new_node(num);
	}
	else if(num > cur->data)
	{
		if(cur->right)
			insert(cur->right, num);
		else
			cur->right = get_new_node(num);
	}
}

node *get_min(node *cur)
{
	if(cur == NULL)
		return cur;
	if(cur->left == NULL)
		return cur;
	return get_min(cur->left);

}

node *get_max(node *cur)
{
	if(cur == NULL)
		return cur;
	if(cur->right == NULL)
		return cur;
	return get_max(cur->right);
}

node *delete(node *cur, int num)
{
	if(cur == NULL)
		return cur;

	if(num < cur->data)
		cur->left = delete(cur->left, num);
	else if(num > cur->data)
		cur->right = delete(cur->right, num);
	else
	{
		if(cur->left == NULL)
		{
			node *temp = cur->right;
			free(cur);
			return temp;
		}
		if(cur->right == NULL)
		{
			node *temp = cur->left;
			free(cur);
			return temp;
		}

		node *temp = get_min(cur->right);
		cur->data = temp->data;
		cur->right = delete(cur->right, temp->data);
	}
	return cur;
}

int search(node *cur, int num)
{
	if(cur == NULL)
		return 0;
	if(cur->data == num)
		return 1;
	if(num < cur->data)
		return search(cur->left, num);
	if(num > cur->data)
		return search(cur->right, num);
}

void print_path(node *cur, int num)
{
	if(cur == NULL)
		return;
	printf("%d ", cur->data);
	if(num < cur->data)
		print_path(cur->left, num);
	if(num > cur->data)
		print_path(cur->right, num);
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

	do
	{
		printf("\nCurrent tree : ");
		print_tree(root);

		printf("\n1. Insert node\n2. Delete node\n3. Search\n4. Minimum value\n5. Maximum value\nx. Exit");
		printf("\nEnter your choice : ");
		scanf("%d", &ch);

		if(ch==1)
		{
			printf("\nEnter data : ");
			scanf("%d", &ch);

			insert(root, ch);
			ch=1;
		}
		else if(ch==2)
		{
			printf("\nEnter data : ");
			scanf("%d", &ch);

			root = delete(root, ch);
			ch=1;
		}
		else if(ch==3)
		{
			printf("\nEnter data : ");
			scanf("%d", &ch);
			printf("\n");

			if(search(root, ch))
				print_path(root, ch);
			else
				printf("Element not found.\n");
			ch=1;
		}
		else if(ch==4)
		{
			if(get_min(root) == NULL)
				printf("\nEmpty Tree\n");
			else
				printf("\nMinimum Value : %d\n", get_min(root)->data);
			ch=1;
		}
		else if(ch==5)
		{
			if(get_max(root) == NULL)
				printf("\nEmpty Tree\n");
			else
				printf("\nMaximum Value : %d\n", get_max(root)->data);
			ch=1;
		}

	}while(ch==1);
}