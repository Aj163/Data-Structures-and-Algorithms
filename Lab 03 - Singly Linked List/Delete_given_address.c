//Delete a node while temp is at that node.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define inf -1e9

typedef struct linked_list
{
	int num;
	struct linked_list *next;
}node;

node *head=NULL, *temp, *t;

void insert(int pos, int n)
{
	int ctr=2;
	if(pos==1 || head->num==inf)
	{
		temp = (node*)malloc(sizeof(node));
		temp->next = head;
		temp->num = n;
		head = temp;
	}
	else
	{
		t = head->next;
		temp = head;
		while(ctr<pos && t->num!=inf)
		{
			t = t->next;
			temp = temp->next;
			ctr++;
		}

		t = (node*)malloc(sizeof(node));
		t->next = temp->next;
		t->num = n;
		temp->next = t;
	}
}

void delete(int pos)
{
	int ctr=1;
	if(head->num==inf)
		return;
	else if(pos==1)
	{
		temp = head;
		head = head->next;
		temp->next = NULL;
		free(temp);
	}
	else
	{
		t = head->next;
		temp = head;
		while(ctr<pos && t->num!=inf)
		{
			t = t->next;
			temp = temp->next;
			ctr++;
		}

		temp->num = t->num;
		temp->next = t->next;
		t->next = NULL;
		free(t);
		
	}
}

void display()
{
	printf("\nCurrent list is\n");
	temp = head;
	while(temp->num != inf)
	{
		printf("%d -> ", temp->num);
		temp = temp->next;
	}
	printf("NULL\n");
}

void main()
{
	int ch, n, p;

	head = (node*)malloc(sizeof(node));
	head->num = inf;
	head->next = NULL;

	do
	{
		printf("\n1. Insert node\n2. Delete node\nx. Any other number to exit.\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);

		if(ch==1)
		{
			printf("\nEnter data and valid position : ");
			scanf("%d%d", &n, &p);

			insert(p, n);
			display();
		}
		else if(ch==2)
		{
			printf("\nEnter valid position : ");
			scanf("%d", &p);

			delete(p);
			display();
		}
	}while(ch>=1 && ch<=2);
}