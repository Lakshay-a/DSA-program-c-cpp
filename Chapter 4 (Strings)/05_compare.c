#include <stdio.h>

void compare(char a[],char b[])
{
    int i,j;
    for(i=0,j=0;a[i]!='\0' && b[j]!='\0';i++,j++)
    {
        if (a[i]!=b[j])
            break;
    }
    if(a[i]==b[j])
        printf("equal");
    else if(a[i]<b[j])
        printf("a is smaller");
    else if(a[i]>b[j])
        printf("a is greater");
}

int main()
{
    char a[]="painter";
    char b[]="painting";
    compare(a,b);

    return 0;
}

//! YOU CAN CHECK IF A STRING IS PALINDROME BY PUTTING ITERATOR i AT 0 AND j AT LEN-2 AND THEN DOING i++ AND j-- AND CHECKING 
//! IF a[i]==a[j] ALWAYS OR YOU CAN SIMPLY REVERSE THE STRING AND STORE IT IN ANOTHER ARRAY AND THEN COMPARE THE REVERSED
//! STRING WITH THE ORIGINAL STRING 