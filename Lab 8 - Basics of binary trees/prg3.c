//Number of nodes in a perfect binary tree oh height h.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	int h;
	printf("\nEnter height of perfect binary tree : ");
	scanf("%d", &h);

	printf("Number of nodes : %d\n\n", ((1<<(h+1))-1));
}