//Prefix to Postfix

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 200

int stack1[MAX], top1=-1;

void push1(int a)
{
	if(top1==MAX-1)
	{
		printf("Stack Overflow.\n");
		return;
	}
	top1++;
	stack1[top1] = a;
}

int pop1()
{
	if(top1==-1)
	{
		printf("Stack Empty.\n");
		return -1;
	}
	return stack1[top1--];
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
	char str[500], *c, *d, arr[500], ans[500], z;
	int l, i, l1, n1, n2;
	int exists[26], val[26], ctr=0;

	for(i=0; i<26; i++)
		exists[i]=0;

	printf("\nEnter prefix expression : ");
	scanf("%s", str);

	printf("Postfix expression : ");
	l = strlen(str);
	for(i=l-1; i>=0; i--)
	{
		if(isoperand(str[i]))
		{
			if(exists[str[i]-'a']==0)
			{
				exists[str[i]-'a']=1;
				ctr++;
			}

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
	strcpy(str, pop());
	printf("%s\n\n", str);

	printf("Enter values of all variables (variable_name value).\n");
	for(i=0; i<ctr; i++)
	{
		getchar();
		scanf("%c", &z);
		getchar();
		scanf("%d", &l1);
		val[z-'a'] = l1;
	}

	for(i=0; i<l; i++)
	{
		if(isoperand(str[i]))
			push1(val[str[i]-'a']);
		else
		{
			n1 = pop1();
			n2 = pop1();
			push1(res(n2, n1, str[i]));
		}
	}
	printf("Answer : %d\n\n", pop1());
}