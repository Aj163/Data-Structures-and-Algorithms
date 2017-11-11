//Counting Sort

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000

void counting_sort(int arr[], int n)
{
	int i, j, pos = 0;
	int count[N], temp[N];

	for(i=0; i<N; i++)
		count[i] = 0;

	for(i=0; i<n; i++)
		count[arr[i]]++;

	for(i=0; i<N; i++)
		for(j=0; j<count[i]; j++)
			temp[pos++] = i;

	for(i=0; i<n; i++)
		arr[i] = temp[i];
}

int main()
{
	int n, i, j;
	int arr[N];

	printf("\nEnter the number of elements and the array of non-negative numbers : ");
	scanf("%d", &n);

	for(i=0; i<n; i++)
		scanf("%d", arr+i);

	counting_sort(arr, n);

	printf("\nSorted Array : ");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);

	printf("\n\n");
}

/*

Test Case:
10
6 8 0 1 5 1 7 6 1 6

*/