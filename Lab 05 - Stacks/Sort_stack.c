//Sort a stack using recursion

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
		if(p<e)
		{
			insert(t-1, p);
			push(e);
		}
		else
		{
			push(e);
			push(p);
		}
	}
}

void sort(int t)
{
	int p;
	if(t==-1)
		return;
	p = pop();
	sort(t-1);
	insert(t-1, p);
}

void main()
{
	int n, i, p;

	printf("Enter number of elements in stack (>0) : ");
	scanf("%d", &n);

	printf("Enter the elements\n");
	for(i=0; i<n; i++)
	{
		scanf("%d", &p);
		push(p);
	}

	sort(top);
	printf("\nSorted stack\n");
	for (i = 0; i < n; ++i)
	{
		printf("%d ", s[i]);
	}

	printf("\n\n");
}