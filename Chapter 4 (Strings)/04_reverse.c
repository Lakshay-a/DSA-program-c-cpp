#include <stdio.h>

void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

// REVERSING USING AN EXTRA ARRAY
void Ereverse(char a[],int len)
{
    char b[len];
    int i=0,j;
    while(a[i]!='\0')
    {
        i++;
    }
    i--;
    for(j=0;i>=0;i--,j++)
    {
        b[j]=a[i];
    }
    b[j]='\0';
    printf("%s",b);
}

// REVERSING USING SWAPPING ELEMENTS
void Sreverse(char a[],int len)
{
    int i,j;
    for(i=0,j=len-2;i<j;i++,j--)    // if don't want to use len, iterate j to the end and then do j-- like done in the  
    {                               // above function
        swap(&a[i],&a[j]);
    }
    printf("%s",a);
}

int main()
{
    char a[]="python";
    int len=sizeof(a)/sizeof(char);
    // Ereverse(a,len);
    Sreverse(a,len);

    return 0;
}