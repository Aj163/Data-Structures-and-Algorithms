//Merge Sort

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000

void merge(int arr[], int l, int mid, int r)
{
	int temp[N];
	int i, p1=l, p2=mid+1, p3=l;

	while(p1<=mid && p2<=r)
	{
		if(arr[p1] < arr[p2])
			temp[p3++] = arr[p1++];
		else
			temp[p3++] = arr[p2++];
	}

	while(p1<=mid)
		temp[p3++] = arr[p1++];
	while(p2<=r)
		temp[p3++] = arr[p2++];

	for(i=l; i<=r; i++)
		arr[i] = temp[i];
}

void merge_sort(int arr[], int l, int r)
{
	int mid;

	if(l>=r)
		return;

	mid = (l+r)/2;
	merge_sort(arr, l, mid);
	merge_sort(arr, mid+1, r);
	merge(arr, l, mid, r);
}

int main()
{
	int n, i, j;
	int arr[N];

	printf("\nEnter the number of elements and the array of numbers : ");
	scanf("%d", &n);

	for(i=0; i<n; i++)
		scanf("%d", arr+i);

	merge_sort(arr, 0, n-1);

	printf("\nSorted Array : ");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);

	printf("\n\n");
}

/*

Test Case:
10
63453 -68561 -89898 43 0 6543 -94 68 168 1181

*/