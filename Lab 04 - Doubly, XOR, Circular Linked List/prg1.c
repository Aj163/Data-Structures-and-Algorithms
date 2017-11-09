//Doubly Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linked_list
{
	int num;
	struct linked_list *next, *prev;
}node;

node *head=NULL, *temp, *t;

void insert(int pos, int n)
{
	int ctr=2;
	if(head==NULL)
	{
		head = (node*)malloc(sizeof(node));
		head->num = n;
		head->next = NULL;
		head->prev = NULL;
	}
	else if(pos==1)
	{
		temp = (node*)malloc(sizeof(node));
		temp->next = head;
		head->prev = temp;
		temp->num = n;
		head = temp;
		temp->prev = NULL;
	}
	else
	{
		t = head->next;
		temp = head;
		while(ctr<pos && t!=NULL)
		{
			t = t->next;
			temp = temp->next;
			ctr++;
		}
		
		t = (node*)malloc(sizeof(node));
		t->next = temp->next;
		t->prev = temp;
		if(temp->next)
			(temp->next)->prev = t;
		t->num = n;
		temp->next = t;
	}
}

void delete(int pos)
{
	int ctr=2;
	if(head==NULL)
		return;
	else if(pos==1)
	{
		temp = head;
		head = head->next;
		if(head)
			head->prev = NULL;
		temp->next = NULL;
		free(temp);
	}
	else
	{
		t = head->next;
		while(ctr<pos && t->next!=NULL)
		{
			t = t->next;
			ctr++;
		}
		
		temp = t->prev;
		temp->next = t->next;
		if(t->next)
			(t->next)->prev = temp;
		t->next = NULL;
		free(t);
	}
}

void display()
{
	printf("\nCurrent list is\n");
	temp = head;
	while(temp != NULL)
	{
		printf("%d <--> ", temp->num);
		temp = temp->next;
	}
	printf("NULL\n");
}

void main()
{
	int ch, n, p;

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
