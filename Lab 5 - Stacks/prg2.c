//Evaluating Prefix

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX], top=-1;

void push(int a)
{
	if(top==MAX-1)
	{
		printf("Stack Overflow.\n");
		return;
	}
	top++;
	stack[top] = a;
}

int pop()
{
	if(top==-1)
	{
		printf("Stack Empty.\n");
		return -1;
	}
	return stack[top--];
}

int res(int a, int b, char c)
{
	if(c=='^')
		return a^b;
	if(c=='&')
		return a&b;
	if(c=='|')
		return a|b;
	if(c=='+')
		return a+b;
	if(c=='-')
		return a-b;
	if(c=='*')
		return a*b;
	if(c=='/')
		return a/b;
	if(c=='%')
		return a%b;
}

void main()
{
	char str[500];
	int l, i, n1, n2;

	printf("\nEnter prefix expression : ");
	scanf("%s", str);

	l = strlen(str);
	for(i=l-1; i>=0; i--)
	{
		if(str[i]>='0' && str[i]<='9')
			push(str[i]-'0');
		else
		{
			n1 = pop();
			n2 = pop();
			push(res(n1, n2, str[i]));
		}
	}
	printf("Answer : %d\n\n", pop());
}