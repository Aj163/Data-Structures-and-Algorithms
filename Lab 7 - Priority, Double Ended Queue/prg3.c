//Double ended queue using linked list

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define inf (1e9)

typedef struct linked_list
{
	int data;
	struct linked_list *next;
}node;

node *front = NULL, *t1, *t2, *rear = NULL;

void enqf(int num)
{
	if(front==NULL)
	{
		t1 = (node*)malloc(sizeof(node));
		t1->data = num;
		t1->next = NULL;
		front = rear = t1;
		return;
	}

	t1 = (node*)malloc(sizeof(node));
	t1->data = num;
	t1->next = front;
	front = t1;
}

void enqr(int num)
{
	if(front==NULL)
	{
		t1 = (node*)malloc(sizeof(node));
		t1->data = num;
		t1->next = NULL;
		front = rear = t1;
		return;
	}

	t1 = (node*)malloc(sizeof(node));
	t1->data = num;
	rear->next = t1;
	rear = t1;
}

int deqf()
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
	free(t1);
	return ret;
}

int deqr()
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
	while(t1->next != rear)
		t1 = t1->next;

	rear = t1;
	t1 = t1->next;
	rear->next = NULL;
	ret = t1->data;
	free(t1);
	return ret;
}

void main()
{
	int ch, n, p;

	do
	{
		printf("\n1. Enqueue front\n2. Enqueue rear\n3. Dequeue front\n4. Dequeue rear\nx. Any other number to exit.\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);

		if(ch==1)
		{
			printf("\nEnter data : ");
			scanf("%d", &n);

			enqf(n);
		}
		else if(ch==2)
		{
			printf("\nEnter data : ");
			scanf("%d", &n);

			enqr(n);
		}
		else if(ch==3)
		{
			p = deqf();
			if(p == inf)
			{
				printf("Queue Empty\n");
				continue;
			}
			else
				printf("Popped element : %d\n", p);
		}
		else if(ch==4)
		{
			p = deqr();
			if(p == inf)
			{
				printf("Queue Empty\n");
				continue;
			}
			else
				printf("Popped element : %d\n", p);
		}
	}while(ch>=1 && ch<=4);
}