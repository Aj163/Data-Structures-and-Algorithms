//Student Records

#include<stdio.h>

struct student
{
    char name[50];
    int r, m1, m2, m3;
    double avg;
};

void swap(struct student *p, struct student *q)
{
    struct student t;

    t.r = p->r;
    t.m1 = p->m1;
    t.m2 = p->m2;
    t.m3 = p->m3;
    t.avg = p->avg;
    strcpy(t.name, p->name);
   
    p->r = q->r;
    p->m1 = q->m1;
    p->m2 = q->m2;
    p->m3 = q->m3;
    p->avg = q->avg;
    strcpy(p->name, q->name);
   
    q->r = t.r;
    q->m1 = t.m1;
    q->m2 = t.m2;
    q->m3 = t.m3;
    q->avg = t.avg;
    strcpy(q->name, t.name);
}

int bsearch(struct student *p, int a, int b, char k[])
{
    int mid = (a+b)/2;
    if(a>b)
        return 0;
    if(strcmp((p+mid)->name, k) > 0)
        return bsearch(p, a, mid-1, k);
    else if(strcmp((p+mid)->name, k) == 0)
        return mid+1;
    else
        return bsearch(p, mid+1, b, k);
}

void bsort(struct student *p, int n)
{
    int flag=1, i;
    while(flag)
    {
        flag=0;
        for(i=0; i<n-1; i++)
            if(strcmp((p+i)->name, (p+i+1)->name) > 0)
            {
                swap(p+i, p+i+1);
                flag=1;
            }
    }
}

void update(struct student *p, int i, int c)
{
    char str[50];
    int a;
    switch(c)
    {
        case 1:
            printf("Enter name : ");
            scanf("%s", str);
            strcpy((p+i)->name, str);
            break;
        case 2:
            printf("Enter the updated marks of the corresponding subject : ");
            scanf("%d", &a);
            (p+i)->m1 = a;
            break;
        case 3:
            printf("Enter the updated marks of the corresponding subject : ");
            scanf("%d", &a);
            (p+i)->m2 = a;
            break;
        case 4:
            printf("Enter the updated marks of the corresponding subject : ");
            scanf("%d", &a);
            (p+i)->m3 = a;
            break;
        case 5:
            printf("Enter the updated roll no : ");
            scanf("%d", &a);
            (p+i)->r = a;
            break;
    }
    if(c>=1 && c<=5)
    {
        (p+i)->avg = ((p+i)->m1 + (p+i)->m2 + (p+i)->m3)*1.0/3;
       
        printf("\n\nUpdated Record");
        printf("\nName : %s", (p+i)->name);
        printf("\nRoll no : %d", (p+i)->r);
        printf("\nMarks : %d %d %d", (p+i)->m1, (p+i)->m2, (p+i)->m3);
        printf("\nAverage : %lf", (p+i)->avg);
    }
}

void sort(struct student *p, int n)
{
    int i, j;
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
            if((p+i)->avg > (p+j)->avg)
                swap(p+i, p+j);
}

int main()
{
    int n, i, c;
    struct student *p;
    char k[50];
   
    printf("\nEnter the number of records : ");
    scanf("%d", &n);
    if(n<=0)
    {
        printf("Enter a number greater than 0\n\n");
        return 0;
    }
    p = (struct student *)malloc(n*sizeof(struct student));
   
    printf("Enter the record details (Name, Roll no, 3 marks).");
    for(i=0; i<n; i++)
    {
        printf("\nRecord %d\n", i+1);
        scanf("%s", (p+i)->name);
        scanf("%d", &(*(p+i)).r);
        scanf("%d%d%d", &(*(p+i)).m1, &(*(p+i)).m2, &(*(p+i)).m3);
        (p+i)->avg = ((p+i)->m1 + (p+i)->m2 + (p+i)->m3)*1.0/3;
    }
       
    printf("Sort by name(1) or average marks(2) ? ");
    scanf("%d", &c);
    if(c==1)
        bsort(p, n);
    else if(c==2)
        sort(p, n);
    else
        return 0;
   
    printf("\nThe records after sorting is");
    for(i=0; i<n; i++)
    {
        printf("\n\nRecord %d", i+1);
        printf("\nName : %s", (p+i)->name);
        printf("\nRoll no : %d", (p+i)->r);
        printf("\nMarks : %d %d %d", (p+i)->m1, (p+i)->m2, (p+i)->m3);
        printf("\nAverage : %lf", (p+i)->avg);
    }
       
    printf("\n\nEnter the name to search for in the records : ");
    scanf("%s", k);
    i = bsearch(p, 0, n-1, k);
    if(i)
        printf("Element found at position : %d", i);
    else
    {
        printf("Element not found!");\
        return 0;
    }
   
    printf("\n\n1. Update name\n2. Update marks of subject 1");
    printf("\n3. Update marks of subject 2\n4. Update marks of subject 3\n5. Update roll no");
    printf("\nAny other number to exit.\nEnter your choice : ");
    scanf("%d", &c);
   
    update(p, i-1, c);
           
    printf("\n\n");     
}