//Stack implemented using linked list

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF (-1e9)

typedef struct stack_node
{
	int data;
	struct stack_node *next;
} node;
node *head = NULL, *temp;

int push(int n)
{
	temp = (node *)malloc(sizeof(node));
	if(temp==NULL)
	{
		printf("Memory Full (Stack Overflow).\n");
		return 0;
	}

	if(head==NULL)
	{
		head = temp;
		head->next = NULL;
		head->data = n;
	}
	else
	{
		temp->next = head;
		head = temp;
		head->data = n;
	}
	return 1;
}

int pop()
{
	int ret=0;
	if(head==NULL)
	{
		printf("Stack Empty\n");
		return INF;
	}
	else
	{
		temp = head;
		head = head->next;
		temp->next = NULL;
		ret = temp->data;
		free(temp);
		return ret;
	}
}

void main()
{
	int ch, n, p;

	do
	{
		printf("\n1. Push\n2. Pop\nx. Any other number to exit.\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);

		if(ch==1)
		{
			printf("\nEnter data : ");
			scanf("%d", &n);

			if(push(n))
				printf("Element pushed into stack\n");
		}
		else if(ch==2)
		{
			p = pop();
			if(p!=INF)
				printf("Popped element : %d\n", p);
		}

	}while(ch>=1 && ch<=2);
}