//Implement 2 stacks in one array

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 200

int s[MAX];
int top1=-1, top2 = MAX;

void push1(int c)
{
	if(top1 != top2-1)
	{
		top1++;
		s[top1] = c;
	}
	else
		printf("Stack Overflow\n");
}

void push2(int c)
{
	if(top2 != top1+1)
	{
		top2--;
		s[top2] = c;
	}
	else
		printf("Stack Overflow\n");
}

void pop1()
{
	if(top1!=-1)
		printf("Popped element : %d\n", s[top1--]);
	else
		printf("Stack Empty\n");
}

void pop2()
{
	if(top2!=MAX)
		printf("Popped element : %d\n", s[top2++]);
	else
		printf("Stack Empty\n");
}


void main()
{
	int n, ch, t;

	do
	{
		printf("\nEnter your choice <push(1)/pop(2) stack_number(1/2)> : ");
		scanf("%d%d", &ch, &t);

		if(ch==1)
		{
			printf("\nEnter data : ");
			scanf("%d", &n);

			if(t==1)
				push1(n);
			else
				push2(n);
		}
		else if(ch==2)
		{
			if(t==1)
				pop1();
			else
				pop2();
		}
	}while(ch==1 || ch==2);
}