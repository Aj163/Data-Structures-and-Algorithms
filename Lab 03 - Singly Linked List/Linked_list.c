//Linked List - Sort, Insert, Delete

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

void delete(int pos)
{
	int ctr=2;
	if(head==NULL)
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
		while(ctr<pos && t->next!=NULL)
		{
			t = t->next;
			temp = temp->next;
			ctr++;
		}

		temp->next = t->next;
		t->next = NULL;
		free(t);
	}
}

void swap(node *a, node *b)
{
	int k = a->num;
	a->num = b->num;
	b->num = k;
}

void sort()
{
	int flag=1;
	if(head==NULL || head->next == NULL)
		return;

	while(flag)
	{
		flag=0;
		temp = head;
		t = head->next;
		while(t!=NULL)
		{
			if(temp->num>t->num)
			{
				flag=1;
				swap(temp, t);
			}
			temp = t;
			t = t->next;
		}
	}
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
		printf("\n1. Insert node\n2. Delete node\n3. Sort List\nx. Any other number to exit.\n");
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
		else if(ch==3)
		{
			sort();
			display();
		}
	}while(ch>=1 && ch<=3);
}