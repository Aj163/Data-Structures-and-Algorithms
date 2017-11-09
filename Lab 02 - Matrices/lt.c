#include<stdio.h>
#include<stdlib.h>

void main()
{
	int n, **ptr, i, j, f=0, s=0;
	printf("Enter the number of rows, and the square matrix : ");
	scanf("%d", &n);
	
	ptr = (int**)malloc(n*sizeof(int*));
	for(i=0; i<n; i++)
	{
		ptr[i] = (int*)malloc((i+1)*sizeof(int));
		for(j=0; j<=i; j++)
			scanf("%d", &ptr[i][j]);
		for(j=i+1; j<n; j++)
			scanf("%d", &f);
	}
	
	printf("\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<=i; j++)
			printf("%d ", ptr[i][j]);
		for(j=i+1; j<n; j++)
			printf("0 ");
		printf("\n");
	}
	
}
