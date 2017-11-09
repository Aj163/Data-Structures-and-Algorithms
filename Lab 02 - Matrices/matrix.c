#include<stdio.h>
#include<stdlib.h>

void main()
{
	int n, **ptr, i, j, f1=0, f2=0, f3=0, f4=0;
	printf("Enter the number of rows, and the square matrix : ");
	scanf("%d", &n);
	
	ptr = (int**)malloc(n*sizeof(int*));
	for(i=0; i<n; i++)
	{
		ptr[i] = (int*)malloc(n*sizeof(int));
		for(j=0; j<n; j++)
			scanf("%d", &ptr[i][j]);
	}
	
	//Lower Triangle
	for(i=1; i<n; i++)
		for(j=0; j<i; j++)
			if(ptr[i][j] != 0)
			{
				f1=1;
				break;
			}
			
	//Lower Triangle
	for(i=1; i<n; i++)
		for(j=n-i; j<n; j++)
			if(ptr[i][j] != 0)
			{
				f3=1;
				break;
			}
		
	//Upper Triangle
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if(ptr[i][j] != 0)
			{
				f2=1;
				break;
			}
			
	//Upper Triangle
	for(i=0; i<n-1; i++)
		for(j=0; j<n-i-1; j++)
			if(ptr[i][j] != 0)
			{
				f4=1;
				break;
			}
		
	if((f2==0 && f1==0) || (f3==0 && f4==0))
		printf("Diagonal matrix.\n");
	else if(f2==0 || f4==0)
		printf("Lower Triangle matrix.\n");
	else if(f1==0 || f3==0)
		printf("Upper Triangle matrix.\n");
	else
		printf("Neither a lower triangle, upper triangle or a diagonal matrix.\n");
}
