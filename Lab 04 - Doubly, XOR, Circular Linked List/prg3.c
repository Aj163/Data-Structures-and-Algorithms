//XOR Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linked_list
{
	int num;
	struct linked_list *xor;
}node;

node *head=NULL, *temp, *t, *prev, *p;

node *xor(node *a, node *b)
{
	long long int c = (long long int)a, d = (long long int)b;
	return (node*)(c^d);
}

void insert(int pos, int n)
{
	int ctr=2;
	if(head==NULL)
	{
		head = (node*)malloc(sizeof(node));
		head->num = n;
		head->xor = NULL;
	}
	else if(pos==1)
	{
		temp = (node*)malloc(sizeof(node));
		temp->xor = head;
		temp->num = n;
		head->xor = xor(head->xor, temp);
		head = temp;
	}
	else
	{
		t = head->xor;
		temp = head;
		prev = NULL;
		while(ctr<pos && t!=NULL)
		{
			t = xor((t->xor), temp);
			p = temp;
			temp = xor((temp->xor), prev);
			prev = p;
			ctr++;
		}
		
		t = (node*)malloc(sizeof(node));
		t->xor = xor(xor(temp->xor, prev), temp);
		t->num = n;
		temp->xor = xor(t, prev);
		if(xor(t->xor, temp))
			(xor(t->xor, temp))->xor = xor(xor((xor(t->xor, temp))->xor, t), temp);
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
		head = head->xor;
		if(head)
			head->xor = xor(head->xor, temp);
		temp->xor = NULL;
		free(temp);
	}
	else
	{
		t = head->xor;
		temp = head;
		prev = NULL;
		while(ctr<pos && t->xor!=temp)
		{
			t = xor((t->xor), temp);
			p = temp;
			temp = xor((temp->xor), prev);
			prev = p;
			ctr++;
		}
		
		temp->xor = xor(xor(t->xor, temp), prev);
		if(xor(t->xor, temp))
			(xor(t->xor, temp))->xor = xor(xor(temp, t), (xor((t->xor), temp))->xor);
		t->xor = NULL;
		free(t);
	}
}

void display()
{
	printf("\nCurrent list is\n");
	temp = head;
	prev = NULL;
	p = NULL;
	while(temp != NULL)
	{
		printf("%d --> ", temp->num);
		t = temp;
		temp = xor((temp->xor), prev);
		p = prev;
		prev = t;

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
