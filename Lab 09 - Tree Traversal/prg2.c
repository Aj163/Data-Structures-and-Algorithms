//Infix expression tree

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 200

typedef struct binary_tree
{
	char data;
	struct binary_tree *left, *right;
}node;


node *get_new_node(char num)
{
	node *t = (node*)malloc(sizeof(node));
	t->left = NULL;
	t->right = NULL;
	t->data = num;
	return t;
}

void *st[MAX];
int t=-1;

void *get()
{
	return st[t--];
}

void put(void *add)
{
	st[++t] = add;
}

char stack[MAX], top=-1;

void push(char a)
{
	if(top==MAX-1)
	{
		printf("Stack Overflow.\n");
		return;
	}
	top++;
	stack[top] = a;
}

char pop()
{
	if(top==-1)
	{
		printf("Stack Empty.\n");
		return 0;
	}
	return stack[top--];
}

int isoperand(char a)
{
	if(a>='0' && a<='9')
		return 1;
	if(a>='A' && a<='Z')
		return 1;
	if(a>='a' && a<='z')
		return 1;
	return 0;
}

int prec(char a)
{
	if(a=='-' || a=='+')
		return 0;
	if(a=='*' || a=='/')
		return 1;
	if(a=='%')
		return 3;
	if(a=='^' || a=='&' || a=='|')
		return 2;
	return -1;
}

void inorder(node *cur)
{
	if(cur==NULL)
		return;

	inorder(cur->left);
	printf("%c ", cur->data);
	inorder(cur->right);
}

void main()
{
	char str[500], c, post[500], p=0;
	int l, i;
	node *root = NULL, *t = NULL, *t1 = NULL, *t2 = NULL;

	printf("\nEnter infix expression : ");
	scanf("%s", str);

	l = strlen(str);
	for(i=0; i<l; i++)
	{
		if(isoperand(str[i]))
			post[p++] = str[i];
		else if(str[i]=='(')
			push(str[i]);
		else if(str[i]==')')
		{
			c = pop();
			while(c!='(')
			{
				post[p++] = c;
				c = pop();
			}
		}
		else
		{
			while(top!=-1 && prec(stack[top])>=prec(str[i]))
				post[p++] = pop();
			push(str[i]);
		}
	}
	while(top!=-1)
		post[p++] = pop();

	for(i=0; i<=p; i++)
	{
		if(isoperand(post[i]))
		{
			t = get_new_node(post[i]);
			put((void *)t);
		}
		else
		{
			t2 = (node *)get();
			t1 = get();
			t = get_new_node(post[i]);
			t->left = t1;
			t->right = t2;
			put((void *)t);
		}
	}

	printf("Inorder : ");
	root = get();
	inorder(root);

	printf("\n\n");
}