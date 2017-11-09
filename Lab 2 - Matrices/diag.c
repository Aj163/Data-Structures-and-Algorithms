#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void main()
{
	int n, **ptr, i, j;
	printf("Enter the number of rows, and the square matrix : ");
	scanf("%d", &n);
	
	ptr = (int**)malloc(n*sizeof(int*));
	for(i=0; i<n; i++)
	{
		ptr[i] = (int*)malloc(n*sizeof(int));
		for(j=0; j<n; j++)
			scanf("%d", &ptr[i][j]);
	}
	
	for(i=0; i<n; i++)
		swap(ptr[i] + i, ptr[i] + n-i-1);
	
	printf("\n");	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%d ", ptr[i][j]);
		printf("\n");
	}
}
