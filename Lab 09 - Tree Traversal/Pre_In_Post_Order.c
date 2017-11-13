//Binary tree - Preorder, Inorder, Postorder

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

void inorder(node *cur)
{
	if(cur==NULL)
		return;

	inorder(cur->left);
	printf("%d ", cur->data);
	inorder(cur->right);
}

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

void main()
{
	int ch;
	node *root = NULL;

	do
	{
		printf("\n1. Add node\n2. Preorder\n3. Inorder\n4. Postorder\nx. Exit");
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
			printf("\n");
			preorder(root);
			printf("\n");
		}
		else if(ch==3)
		{
			printf("\n");
			inorder(root);
			printf("\n");
		}
		else if(ch==4)
		{
			printf("\n");
			postorder(root);
			printf("\n");
		}

	}while(ch>=1 && ch<=4);
}