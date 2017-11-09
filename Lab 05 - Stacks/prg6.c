//Prefix to Postfix

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 200

char stack[MAX][500], top=-1;

void push(char a[])
{
	if(top==MAX-1)
	{
		printf("Stack Overflow.\n");
		return;
	}
	top++;
	strcpy(stack[top], a);
}

char *pop()
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

void main()
{
	char str[500], *c, *d, arr[500];
	int l, i, l1;

	printf("\nEnter prefix expression : ");
	scanf("%s", str);

	printf("Postfix expression : ");
	l = strlen(str);
	for(i=l-1; i>=0; i--)
	{
		if(isoperand(str[i]))
		{
			arr[0] = str[i];
			arr[1] = '\0';
			push(arr);
		}
		else
		{
			c = pop();
			d = pop();

			strcpy(arr, c);
			strcat(arr, d);
			l1 = strlen(arr);
			arr[l1] = str[i];
			arr[l1+1] = '\0';
			push(arr);
		}
	}
	printf("%s\n\n", pop());
}