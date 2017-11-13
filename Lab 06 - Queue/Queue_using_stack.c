//Queue using stack

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 500

int s[MAX];
int top=-1;

void push(int n)
{
	top++;
	s[top] = n;
}

int pop()
{
	return s[top--];
}

void insert(int t, int p)
{
	int e;
	if(t==-1)
		push(p);
	else
	{
		e = pop();
		insert(t-1, p);
		push(e);
	}
}

void reverse(int t)
{
	int p;
	if(t==-1)
		return;
	p = pop();
	reverse(t-1);
	insert(t-1, p);
}

void enq(int n)
{
	if(top==MAX-1)
	{
		printf("Queue full\n");
		return;
	}
	reverse(top);
	push(n);
	reverse(top);
}

void deq()
{
	if(top==-1)
		printf("Queue empty\n");
	else
		printf("Popped element : %d\n", s[top--]);
}

void main()
{
	int n, ch;

	do
	{
		printf("\n1. Enqueue\n2. Dequeue\nx. Any other number to exit\nEnter your choice : ");
		scanf("%d", &ch);

		if(ch==1)
		{
			printf("\nEnter data : ");
			scanf("%d", &n);

			enq(n);
		}
		else if(ch==2)
			deq();
	}while(ch==1 || ch==2);
}