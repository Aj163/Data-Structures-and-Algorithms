//Circular Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linked_list
{
	int num;
	struct linked_list *next;
}node;

node *last=NULL, *temp, *t;
int total=0;

void insert(int n, int pos)
{
	int ctr=1;
	if(last==NULL)
	{
		last = (node*)malloc(sizeof(node));
		last->num = n;
		last->next = last;
		total = 1;
	}
	else if(total < pos)
	{
		total++;
		temp = (node*)malloc(sizeof(node));
		temp->num = n;
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
	else
	{
		total++;
		temp = last;
		while(ctr<pos)
		{
			ctr++;
			temp = temp->next;
		}
		
		t = (node*)malloc(sizeof(node));
		t->num = n;
		t->next = temp->next;
		temp->next = t;
	}
}	

void delete(int pos)
{
	int ctr=1;
	if(last==NULL)
		return;
	else if(total==1)
	{
		free(last);
		last = NULL;
		total=0;
	}
	else
	{
		temp = last;
		while(ctr<pos)
		{
			ctr++;
			temp = temp->next;
		}
		
		t = temp->next;
		temp->next = t->next;
		t->next = NULL;
		free(t);

		if(total==pos)
			last = temp;
		total--;
	}
}

void display()
{
	if(last==NULL)
	{
		printf("\nCurrent list is\nNULL\n");
		return;
	}
	printf("\nCurrent list is\nHEAD --> ");
	temp = last->next;
	while(temp != last)
	{
		printf("%d --> ", temp->num);
		temp = temp->next;
	}
	printf("%d --> ", temp->num);
	printf("HEAD\n");
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

			insert(n, p);
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
