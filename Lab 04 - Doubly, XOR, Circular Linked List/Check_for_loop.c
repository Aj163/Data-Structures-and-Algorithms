//Check for loop

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linked_list
{
	int num;
	struct linked_list *next;
}node;

node *head=NULL, *temp, *t, *last;

void insert(int n)
{
	if(head==NULL)
	{
		head = (node*)malloc(sizeof(node));
		head->num = n;
		head->next = NULL;
		last = head;
	}
	else
	{
		temp = (node*)malloc(sizeof(node));
		temp->num = n;
		last->next = temp;
		temp->next = NULL;
		last = temp;
	}
}

void link(int p)
{
	int ctr=1;
	temp = head;
	while(ctr<p && temp!=NULL)
	{
		temp = temp->next;
		ctr++;
	}
	last->next = temp;
}

void display()
{
	printf("\nCurrent list is\n");
	temp = head;
	while(temp != NULL)
	{
		printf("%d -> ", temp->num);
		temp = temp->next;
	}
	printf("NULL\n");
}

void main()
{
	int ch, n, p;

	do
	{
		printf("\n1. Insert node\n2. Link last node\n3. Check for loop\nx. Any other number to exit.\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);

		if(ch==1)
		{
			printf("\nEnter data : ");
			scanf("%d", &n);

			insert(n);
			display();
		}
		else if(ch==2)
		{
			printf("\nEnter node number : ");
			scanf("%d", &p);
			link(p);
		}
		else if(ch==3)
		{
			temp = head;
			t = head->next;
			while(t!=NULL && temp!=t)
			{
				t = t->next;
				if(t==NULL)
					break;
				t = t->next;
				temp = temp->next;
			}
			
			if(t==temp)
				printf("Loop exists.\n");
			else
				printf("No loop exists.\n");
		}
	}while(ch>=1 && ch<=2);
}
