//Check for palindrome using stack

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stack[500];
int top;


void push(char a)
{
	top++;
	stack[top] = a;
}

char pop()
{
	return stack[top--];
}

void main()
{
	char str[500], c;
	int l, i, flag=1;

	printf("Enter a string : ");
	scanf("%s", str);

	l = strlen(str);
	for(i=0; i<l/2; i++)
		push(str[i]);

	for(i=l-l/2; i<l; i++)
	{
		c = pop();
		if(c != str[i])
		{
			flag=0;
			break;
		}
	}
	if(flag)
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");
}