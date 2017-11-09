//Infix to Prefix

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 200

char stack[MAX], top=-1;

void push(char a)
{
	if(top==MAX-1)
	{
		printf("Stack Overflow.\n");
		return;
	}
	top++;
	stack[top] = a;
}

char pop()
{
	if(top==-1)
	{
		printf("Stack Empty.\n");
		return;
	}
	return stack[top--];
}

int isoperand(char a)
{
	if(a>='0' && a<='9')
		return 1;
	if(a>='A' && a<='Z')
		return 1;
	if(a>='a' && a<='z')
		return 1;
	return 0;
}

int prec(char a)
{
	if(a=='-' || a=='+')
		return 0;
	if(a=='*' || a=='/')
		return 1;
	if(a=='%')
		return 3;
	if(a=='^' || a=='&' || a=='|')
		return 2;
	return -1;
}

void reverse(char a[])
{
	int i, l = strlen(a);
	char t;
	for(i=0; i<l/2; i++)
	{
		t = a[i];
		a[i] = a[l-i-1];
		a[l-i-1] = t;
	}
}

void main()
{
	char str[500], c, ans[500], p = 0;
	int l, i;

	printf("\nEnter infix expression : ");
	scanf("%s", str);

	l = strlen(str);
	for(i=l-1; i>=0; i--)
	{
		if(isoperand(str[i]))
			ans[p++] = str[i];
		else if(str[i]==')')
			push(str[i]);
		else if(str[i]=='(')
		{
			c = pop();
			while(c!=')')
			{
				ans[p++] = c;
				c = pop();
			}
		}
		else
		{
			while(top!=-1 && prec(stack[top])>prec(str[i]))
				ans[p++] = pop();
			push(str[i]);
		}
	}
	while(top!=-1)
		ans[p++] = pop();

	ans[p] = '\0';
	reverse(ans);

	printf("Prefix expression : %s\n\n", ans);
}