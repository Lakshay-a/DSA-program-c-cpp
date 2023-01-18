#include<stdio.h>

struct Array
{
    int a[20];
    int size;
    int length;
};

// FOR 1 ELEMENT
void missing(struct Array arr)
{
    int diff,l,i;
    l=arr.a[0];
    diff=l-0;
    for(i=0;i<arr.length;i++)
    {
        if((arr.a[i]-i)!=diff)
        {
            printf("missing element is %d\n",i+diff);
            break;
        }
    }
}

// FOR MULTIPLE ELEMENTS
void Missing(struct Array arr)
{
    int diff,l,i;
    l=arr.a[0];
    diff=l-0;
    for(i=0;i<arr.length;i++)
    {
        if((arr.a[i]-i)!=diff)
        {
            while(diff<(arr.a[i]-i))
            {
                printf("missing element is %d\n",i+diff);
                diff++;
            }
        }
    }
}

// FOR UNSORTED ARRAY (USING HASH TABLE)
void unsorted(struct Array arr,int l,int h)
{
    struct Array H;
    H.size=20;
    H.length=h+1;
    int i;
    for (i=0;i<H.length;i++)
    {
        H.a[i]=0;
    }
    for (i=0;i<arr.length;i++)
    {
        H.a[arr.a[i]]++;
    }
    for(i=l;i<=h;i++)
    {
        if(H.a[i]==0)
        {
            printf("missing element is %d\n",i);
        }
    }
}

int main()
{
    struct Array arr1={{1,2,3,4,5,6,8,9,10},20,9};
    struct Array arr2={{6,7,8,9,11,12,15,16,17,18,19},20,11};
    struct Array arr3={{3,7,4,9,12,6,1,11,2,10},20,10};
    
    // missing(arr1);
    // Missing(arr2);
    unsorted(arr3,1,12);
    return 0;
}