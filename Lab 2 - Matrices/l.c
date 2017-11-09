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
		ptr[i] = (int*)malloc(n*sizeof(int));
		for(j=0; j<n; j++)
			scanf("%d", &ptr[i][j]);
	}
	
	for(i=0; i<n-1; i++)
		for(j=1; j<n; j++)
			if(ptr[i][j]!=0)
				f=1;
		
	for(i=0; i<n-1; i++)
		if(ptr[i][0]==0)
			f=1;
			
	for(i=0; i<n; i++)
		if(ptr[n-1][i]==0)
			f=1;
		
	if(f)
	{
		printf("Not a L matrix\n");
		return;
	}
	
	printf("L matrix\n\n");
	
	for(i=0; i<n-1; i++)
	{
		s+=ptr[i][0];
		printf("%d\n", ptr[i][0]);
	}
	
	for(i=0; i<n; i++)
	{
		s+=ptr[n-1][i];
		printf("%d ", ptr[n-1][i]);
	}
	
	printf("\nSum = %d\n", s);
}
