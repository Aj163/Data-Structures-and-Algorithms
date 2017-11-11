//Radix Sort

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000

void counting_sort(int arr[], int n, int pos)
{
	int i, j, p1=0, p2=0;
	int count[2] = {0, 0}, temp[N];

	for(i=0; i<n; i++)
		count[(arr[i] & (1<<pos)) > 0]++;

	p2 = count[0];
	for(i=0; i<n; i++)
	{
		if((arr[i] & (1<<pos)) > 0)
			temp[p2++] = arr[i];
		else
			temp[p1++] = arr[i];
	}

	for(i=0; i<n; i++)
		arr[i] = temp[i];
}

void radix_sort(int arr[], int n)
{
	int i;
	for(i=0; i<32; i++)
		counting_sort(arr, n, i);
}

int main()
{
	int n, i, j;
	int arr[N];

	printf("\nEnter the number of elements and the array of non-negative numbers : ");
	scanf("%d", &n);

	for(i=0; i<n; i++)
		scanf("%d", arr+i);

	radix_sort(arr, n);

	printf("\nSorted Array : ");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);

	printf("\n\n");
}

/*

Test Case:
10
63453 68561 8 43 84 6543 4 68 168 1181

*/