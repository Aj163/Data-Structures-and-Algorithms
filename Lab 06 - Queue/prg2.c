//Revrse a string using stack

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 500

char s[MAX];
int top=-1;

void push(char c)
{
	top++;
	s[top] = c;
}

char pop()
{
	return s[top--];
}

void main()
{
	char s[MAX];
	int l, i;

	printf("\nEnter a string : ");
	scanf("%[^\n]s", s);
	l = strlen(s);

	for(i=0; i<l; i++)
		push(s[i]);

	printf("Reversed string : ");
	for(i=0; i<l; i++)
		printf("%c", pop());
	printf("\n\n");
}