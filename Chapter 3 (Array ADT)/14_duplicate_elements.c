#include<stdio.h>

struct Array
{
    int a[20];
    int size;
    int length;
};

int Max(struct Array arr)
{
    int max = arr.a[0];
    int i;
    for (i = 1; i < arr.length; i++)
    {
        if (arr.a[i] > max)
            max = arr.a[i];
    }
    return max;
}

// FOR SORTED ARRAY
void dup(struct Array arr)
{
    int lastdup=0,i;
    for (i=0;i<arr.length;i++)
    {
        if((arr.a[i]==arr.a[i+1]) && (arr.a[i]!=lastdup))
        {
            printf("%d is a duplicate element\n",arr.a[i]);
            lastdup=arr.a[i];
        }
    }
}

void countdup(struct Array arr)
{
    int i,j;
    for(i=0;i<arr.length;i++)
    {
        if(arr.a[i]==arr.a[i+1])
        {
            j=i+1;
            while(arr.a[j]==arr.a[i])
                j++;
            printf("%d appearing %d times\n",arr.a[i],j-i);
            i=j-1;
        }
    }
}

// FOR SORTED OR UNSORTED ARRAY (USING HASHING)
void hash_dup(struct Array arr,int max)
{
    struct Array h;
    h.size=30;
    h.length=max+1;
    int i;
    for (i=0;i<h.length;i++)
    {
        h.a[i]=0;
    }
    for (i=0;i<arr.length;i++)
    {
        h.a[arr.a[i]]++;
    }
    for(i=0;i<=max;i++)
    {
        if(h.a[i]>1)
            printf("%d is repeated %d times\n",i,h.a[i]);
    }
}

// FOR UNSORTED ARRAY
void unsorted(struct Array arr)
{
    int i,count,j;
    for(i=0;i<arr.length-1;i++)
    {
        count=1;
        if(arr.a[i]!=-1)
        {
            for(j=i+1;j<arr.length;j++)
            {
                if(arr.a[i]==arr.a[j])
                {
                    count++;
                    arr.a[j]=-1;
                }
            }
        }
        if (count>1)
            printf("%d is repeated %d times\n",arr.a[i],count);
    }
}

int main()
{
    struct Array arr1={{3,6,8,8,10,12,15,15,15,20},20,10};
    struct Array arr2={{8,3,6,4,6,5,6,8,2,7},20,10};
    int max1=Max(arr1);
    int max2=Max(arr2);
    // dup(arr1);
    // countdup(arr1);
    // hash_dup(arr1,max1);
    // unsorted(arr2);
    hash_dup(arr2,max2);

    return 0;
}