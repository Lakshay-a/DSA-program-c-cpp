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

// FOR UNSORTED ARRAY
void pair(struct Array arr,int k)
{
    int i,j;
    for(i=0;i<arr.length;i++)
    {
        for(j=i+1;j<arr.length;j++)
        {
            if(arr.a[i]+arr.a[j]==k)
            {
                printf("%d+%d=%d\n",arr.a[i],arr.a[j],k);
            }
        }
    }
}

// USING HASH TABLE (HASHING)
void hash(struct Array arr,int max, int k)
{
    int i;
    struct Array h;
    h.size=30;
    h.length=max+1;
    for (i=0;i<h.length;i++)
    {
        h.a[i]=0;
    }
    for (i=0;i<arr.length;i++)
    {
        if(h.a[(k-arr.a[i])]!=0)
        {
            printf("%d+%d=%d\n",arr.a[i],k-arr.a[i],k);
        }
        h.a[arr.a[i]]++;
    }
}

// FOR SORTED ARRAY
void sort_pair(struct Array arr,int k)
{
    int i=0,j=arr.length-1;
    while(i<j)
    {
        if(arr.a[i]+arr.a[j]==k)
        {
            printf("%d + %d = %d\n",arr.a[i],arr.a[j],k);
            i++;
            j--;
        }
        else if(arr.a[i]+arr.a[j]<k)
            i++;
        else
            j--;
    }
}

int main()
{
    struct Array arr1={{6,3,8,10,16,7,5,2,9,14},20,10};
    struct Array arr2={{1,3,4,5,6,8,9,10,12,14},20,10};
    int max=Max(arr1);
    // pair(arr1,10);
    // hash(arr1,max,10);
    sort_pair(arr2,10);

    return 0;
}