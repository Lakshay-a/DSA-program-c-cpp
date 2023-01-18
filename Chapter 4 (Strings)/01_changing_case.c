#include <stdio.h>

int main()
{
    char A[]="wElCOme";
    int i;
    for (i=0;A[i]!='\0';i++)
    {
        if(A[i]>=65 && A[i]<=90)      //can also write (A[i]>='A' && A[i]<='Z')
            A[i]+=32;
        else if(A[i]>=97 && A[i]<=122)
            A[i]-=32;
    }
    printf("String is %s",A);

    return 0;
}

/* 
LOOK UP SOME OF THE BASIC STRING CODES WRITTEN EARLIER LIKE CALCULATING LENGTH OF A STRING, CHECKING FOR VOWELS OR 
CONSONANTS IN A STRING
*/