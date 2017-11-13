//Implementqueue using array

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int q[MAX];
int f, r;

void enq(int n)
{
	if(f==-1)
	{
		//Implies r is also -1
		f = r = 0;
		q[r] = n;
	}
	else if((r+1)%MAX == f)
		printf("Queue full.\n");
	else
	{
		r = (r+1)%MAX;
		q[r] = n;
	}
}

void deq()
{
	if(f==-1)
		printf("Queue Empty\n");
	else if(f==r)
	{
		printf("Popped Element : %d\n", q[f]);
		f = r = -1;
	}
	else
	{
		printf("Popped Element : %d\n", q[f]);
		f = (f+1)%MAX;
	}
}

void main()
{
	int n, ch;
	f = r = -1;

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