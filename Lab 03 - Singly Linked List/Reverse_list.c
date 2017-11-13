//Reverse a List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linked_list
{
	int num;
	struct linked_list *next;
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
	}
	else if(pos==1)
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
		while(ctr<pos && t!=NULL)
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

void reverse()
{
	node *prev;
	if(head==NULL || head->next==NULL)
		return;
	
	prev = NULL;
	temp = head;
	t = temp->next;

	while(t!=NULL)
	{
		temp->next = prev;
		prev = temp;
		temp = t;
		t = t->next;
	}

	temp->next = prev;
	head = temp;
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
		printf("\n1. Insert node\n2. Reverse List\nx. Any other number to exit.\n");
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
			reverse();
			display();
		}
	}while(ch>=1 && ch<=2);
}