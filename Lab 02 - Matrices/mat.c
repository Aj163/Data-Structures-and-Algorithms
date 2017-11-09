#include<stdio.h>
#include<stdlib.h>

void main()
{
	int n, **ptr, i, j, f=0;
	printf("Enter the number of rows, and the square matrix : ");
	scanf("%d", &n);
	
	ptr = (int**)malloc(n*sizeof(int*));
	for(i=0; i<n; i++)
	{
		ptr[i] = (int*)malloc(n*sizeof(int));
		for(j=0; j<n; j++)
			scanf("%d", &ptr[i][j]);
	}
	
	for(i=1; i<n-1; i++)
		for(j=0; j<n-i-1; j++)
			if(ptr[i][j]!=0)
				f=1;
	
	for(i=1; i<n-1; i++)
		for(j=n-i+1; j<n; j++)
			if(ptr[i][j]!=0)
				f=1;
		
	for(i=0; i<n; i++)
		if(ptr[0][i]==0)
			f=1;
	for(i=1; i<n-1; i++)
		if(ptr[i][n-i-1]==0)
			f=1;
	for(i=0; i<n; i++)
		if(ptr[n-1][i]==0)
			f=1;
		
	if(f)
	{
		printf("Not a Z matrix\n");
		return;
	}
	
	printf("Z matrix\n\n");
	for(i=0; i<n; i++)
		printf("%d ", ptr[0][i]);
	printf("\n");
	for(i=1; i<n-1; i++)
	{
		for(j=0; j<n-i-1; j++)
			printf("  ");
		printf("%d\n", ptr[i][n-i-1]);
	}
	for(i=0; i<n; i++)
		printf("%d ", ptr[n-1][i]);
}
