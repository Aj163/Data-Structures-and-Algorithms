//Check for balance of paranthesis in an expression

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

char s[MAX];
int top=-1;

void push(char c)
{
	top++;
	s[top] = c;
}

char pop()
{
	if(top==-1)
		return '!';
	return s[top--];
}

char rev(char c)
{
	if(c==')')
		return '(';
	if(c=='}')
		return '{';
	if(c=='>')
		return '<';
	return '[';
}

void main()
{
	char s[500], c;
	int l, i, flag=1;

	printf("\nEnter a string : ");
	scanf("%[^\n]s", s);
	l = strlen(s);

	for(i=0; i<l; i++)
	{
		if(s[i]=='(' || s[i]=='{' || s[i]=='[' || s[i]=='<')
			push(s[i]);
		else if(s[i]==')' || s[i]=='}' || s[i]==']' || s[i]=='>')
		{
			c = pop();

			if(c != rev(s[i]))
			{
				//printf("%d %d %d\n", c, rev(s[i]), flag);
				flag=0;
				break;
			}
		}
	}

	if(!flag)
		printf("Paranthesis not balanced.\n");
	else
		printf("Paranthesis balanced.\n");
}