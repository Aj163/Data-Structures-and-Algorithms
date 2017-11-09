//Bucket Sort

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct linked_list_node
{
	float data;
	struct linked_list_node *next;
}node;

node *bucket[200];
float a[200];
int n;

void insert_into_bucket(float n, int pos)
{
	node *temp = bucket[pos], *new;
	while(temp != NULL)
	{
		if(temp->next == NULL)
			break;
		if((temp->next)->data > n)
			break;
		temp = temp->next;
	}

	new = (node*)malloc(sizeof(node));
	if(temp == NULL)
	{
		new->next = NULL;
		bucket[pos] = new;
	}
	else
	{
		new->next = temp->next;
		temp->next = new;
	}
	new->data = n;
}

void main()
{
	int i;
	node *temp;

	printf("\nEnter the number of elements : ");
	scanf("%d", &n);

	printf("\nEnter the numbers (between 0 and 1)\n");
	for(i=0; i<n; i++)
	{
		scanf("%f", a+i);
		//inserting into bucket
		insert_into_bucket(a[i], (int)(a[i]*n));
	}

	printf("\nSorted array : ");
	for(i=0; i<n; i++)
	{
		temp = bucket[i];
		while(temp != NULL)
		{
			printf("%f ", temp->data);
			temp = temp->next;
		}
	}
	printf("\n\n");
}

/*

Test Case
6
0.897 0.565 0.656 0.1234 0.665 0.3434

*/