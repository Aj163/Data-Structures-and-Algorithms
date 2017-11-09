//Circular queue using Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define inf (1e9)

typedef struct linked_list
{
	int data;
	struct linked_list *next;
}node;

node *rear=NULL, *front = NULL, *t1, *t2;

void enq(int n)
{
	if(front==NULL)
	{
		t1 = (node*)malloc(sizeof(node));
		t1->data = n;
		t1->next = t1;
		front = rear = t1;
		return;
	}

	t1 = (node*)malloc(sizeof(node));
	t1->data = n;
	rear->next = t1;
	rear = t1;
	rear->next = front;
}	

int deq()
{
	int ret;
	if(front==NULL)
		return inf;
	if(front==rear)
	{
		t1 = front;
		front = rear = NULL;
		ret = t1->data;
		free(t1);
		return ret;
	}

	t1 = front;
	front = front->next;
	ret = t1->data;
	rear->next = front;
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
			printf("\nEnter data : ");
			scanf("%d", &n);

			enq(n);
		}
		else if(ch==2)
		{
			p = deq();
			if(p==inf)
			{
				printf("Queue Empty\n");
				continue;
			}
			printf("Popped Element : %d\n", p);
		}
	}while(ch>=1 && ch<=2);
}
