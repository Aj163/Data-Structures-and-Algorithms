//General Sorting

#include<stdio.h>

void swap(int *p, int *q)
{
    int t = *p;
    *p = *q;
    *q = t;
}

void ssort(int *p, int n)
{
    int i, j;
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
            if(*(p+i) > *(p+j))
                swap(p+i, p+j);
}

void isort(int *p, int n)
{
    int i, k, j;
    for(i=1; i<n; i++)
    {
        k=i-1;
        j = *(p+i);
        while(k>=0)
        {
            if(*(p+i) < *(p+k))
            {       
                *(p+k+1) = *(p+k);           
                k--;
            }
            else
                break;
        }
        *(p+k+1) = j;
    }
}

int bsearch(int *p, int a, int b, int k)
{
    int mid = (a+b)/2;
    if(a>b)
        return 0;
    if(*(p+mid) > k)
        return bsearch(p, a, mid-1, k);
    else if(*(p+mid) == k)
        return mid+1;
    else
        return bsearch(p, mid+1, b, k);
}

void bsort(int *p, int n)
{
    int flag=1, i;
    while(flag)
    {
        flag=0;
        for(i=0; i<n-1; i++)
            if(*(p+i) > *(p+i+1))
            {
                swap(p+i, p+i+1);
                flag=1;
            }
    }
}

int main()
{
    int n, i, *p, *q, k, *r;
   
    printf("\nEnter the number of elements : ");
    scanf("%d", &n);
    if(n<=0)
    {
        printf("Enter a number greater than 0\n\n");
        return 0;
    }
    p = (int *)malloc(n*sizeof(int));
    q = (int *)malloc(n*sizeof(int));
    r = (int *)malloc(n*sizeof(int));
   
    printf("Enter the elements of the array.\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", p+i);
        *(q+i) = *(p+i);
        *(r+i) = *(p+i);
    }
       
    bsort(p, n);
    ssort(q, n);
    ssort(r, n);
   
    printf("\nThe array after sorting using bubble sort is\n");
    for(i=0; i<n; i++)
        printf("%d ", *(p+i));
   
    printf("\nThe array after sorting using selection sort is\n");
    for(i=0; i<n; i++)
        printf("%d ", *(q+i));   
       
    printf("\nThe array after sorting using insertion sort is\n");
    for(i=0; i<n; i++)
        printf("%d ", *(r+i));   
   
    printf("\n\nEnter the element to search for in the sorted array : ");
    scanf("%d", &k);
    i = bsearch(p, 0, n-1, k);
    if(i)
        printf("Element found at position : %d", i);
    else
        printf("Element not found!");
   
    free(p);
    free(q);
    free(r);
   
    printf("\n\n");     
}