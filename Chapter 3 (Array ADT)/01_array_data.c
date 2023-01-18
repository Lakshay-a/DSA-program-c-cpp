#include <stdio.h>
#include <stdlib.h>

struct array
{
    int *a;
    int size;
    int length;
};

void display(struct array arr)
{
    int i;
    printf("Elements are: \n");
    for (i=0;i<arr.length;i++)
    {
        printf("%d \n",arr.a[i]);
    }
}

int main()
{
    struct array arr;
    int n,i;

    printf("Enter size of array: ");
    scanf("%d",&arr.size);
    arr.a=(int *)malloc(arr.size*sizeof(int));
    arr.length=0;

    printf("Enter the no of elements required: ");
    scanf("%d",&n);

    printf("Enter all the elements: ");
    for (i=0;i<n;i++)
    {
        scanf("%d",&arr.a[i]);
    }
    arr.length=n;

    display(arr);

    return 0;
}