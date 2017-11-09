//Priority queue using linked list

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define inf (1e9)

typedef struct linked_list
{
	int priority, data;
	struct linked_list *next;
}node;

node *head = NULL, *t1, *t2;

void enq(int num, int prior)
{
	if(head==NULL)
	{
		head = (node*)malloc(sizeof(node));
		head->priority = prior;
		head->data = num;
		head->next = NULL;
	}
	else if(head->priority < prior)
	{
		t1 = (node*)malloc(sizeof(node));
		t1->priority = prior;
		t1->data = num;
		t1->next = head;
		head = t1;
	}
	else
	{
		t1 = head;
		while(t1 != NULL && t1->priority >= prior)
		{
			t2 = t1;
			t1 = t1->next;
		}
		t1 = (node*)malloc(sizeof(node));
		t1->priority = prior;
		t1->data = num;
		t1->next = t2->next;
		t2->next = t1;
	}
}

int deq()
{
	int ret;
	if(head==NULL)
		return inf;

	t1 = head;
	head = head->next;
	ret = t1->data;
	free(t1);
	return ret;
}

void main()
{
	int ch, n, p;

	do
	{
		printf("\n1. Enqueue\n2. Dequeue\nx. Any other number to exit.\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);

		if(ch==1)
		{
			printf("\nEnter data and priority : ");
			scanf("%d%d", &n, &p);

			enq(n, p);
		}
		else if(ch==2)
		{
			p = deq();
			if(p == inf)
			{
				printf("Queue Empty\n");
				continue;
			}
			else
				printf("Popped element : %d\n", p);
		}
	}while(ch>=1 && ch<=2);
}