#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    
    int A[5]={2,4,6,8,10};      //STATIC ARRAY CREATED IN STACK

    int *p;
    p=(int *)malloc(5*sizeof(int));     //DYNAMIC ARRAY CREATED IN HEAP
    p[0]=3;
    p[1]=5;
    p[2]=7;
    p[3]=9;
    p[4]=11;

    printf("Printing static array:\n");
    for(i=0;i<5;i++)
    {
        printf("%d ",A[i]);
    }

    printf("\nPrinting dynamic array:\n");
    for(i=0;i<5;i++)
    {
        printf("%d ",p[i]);
    }
    
    return 0;
}