#include<stdio.h>

struct Array
{
    int a[20];
    int size;
    int length;
};

void scan(struct Array arr)
{
    int max=arr.a[0],i,min=arr.a[0];
    for(i=1;i<arr.length;i++)
    {
        if(arr.a[i]<min)
            min=arr.a[i];
        else if(arr.a[i]>max)
            max=arr.a[i];
    }
    printf("max is %d and min is %d",max,min);
}

int main()
{
    struct Array arr1={{5,8,3,9,6,2,10,7,-1,4},20,10};
    scan(arr1);

    return 0;
}