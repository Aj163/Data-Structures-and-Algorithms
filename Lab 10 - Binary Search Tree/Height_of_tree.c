//Height of a binary tree with maximum number of nodes.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hp(int a)
{
	int i;
	for(i=0; i<32; i++)
		if(a <= (1<<i))
			return i;
}

void main()
{
	int h;
	printf("\nEnter number of nodes in a binary tree of maximum number of nodes : ");
	scanf("%d", &h);

	printf("Height of tree : %d\n\n", hp(h+1)-1);
}