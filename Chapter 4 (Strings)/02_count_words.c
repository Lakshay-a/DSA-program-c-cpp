#include <stdio.h>

int main()
{
    char a[]="How are you";
    int i,word=1;
    for (i=0;a[i]!='\0';i++)
    {
        if(a[i]==' ' && a[i-1]!=' ')
        {
            word++;
        }
    }
    printf("There are %d words in the statement",word);

    return 0;
}