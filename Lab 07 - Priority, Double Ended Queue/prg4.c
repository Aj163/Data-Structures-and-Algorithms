//Double ended queue using stack

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define inf (1e9)

int stack[2][500];
int top[2] = {-1, -1};


void push(int t, int a)
{
	stack[t][++top[t]] = a;
}

int pop(int t)
{
	return stack[t][top[t]--];
}

void shift_stack(int a, int b)
{
	if(top[a]==-1)
		return;
	push(b, pop(a));
	shift_stack(a, b);
}

void enqf(int num)
{
	push(0, num);
}

void enqr(int num)
{
	push(1, num);
}

int deqf()
{
	int ret;
	if(top[0]!=-1)
		return pop(0);
	if(top[1]==-1)
		return inf;

	shift_stack(1, 0);
	ret = pop(0);
	shift_stack(0, 1);
	return ret;
}

int deqr()
{
	int ret;
	if(top[1]!=-1)
		return pop(1);
	if(top[0]==-1)
		return inf;

	shift_stack(0, 1);
	ret = pop(1);
	shift_stack(1, 0);
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