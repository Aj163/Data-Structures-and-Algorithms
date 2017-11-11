//Merge Sort

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000

void swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(int arr[], int l, int r)
{
	int pos = l, i;

	//Pivot - Last element (arr[r]).
	for(i=l; i<r; i++)
		if(arr[i] < arr[r])
		{
			swap(arr, i, pos);
			pos++;
		}

	swap(arr, pos, r);
	return pos;
}

void quick_sort(int arr[], int l, int r)
{
	int pos;

	if(l>=r)
		return;

	pos = partition(arr, l, r);
	quick_sort(arr, l, pos-1);
	quick_sort(arr, pos+1, r);
}

int main()
{
	int n, i, j;
	int arr[N];

	printf("\nEnter the number of elements and the array of numbers : ");
	scanf("%d", &n);

	for(i=0; i<n; i++)
		scanf("%d", arr+i);

	quick_sort(arr, 0, n-1);

	printf("\nSorted Array : ");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);

	printf("\n\n");
}

/*

Test Case:
10
63453 -68561 -89898 43 0 6543 -94 6 5 6

*/