#include<stdio.h>

void hash(char a[],char b[])
{
    int i,h[26]={0};
    for(i=0;a[i]!='\0';i++)
        h[a[i]-97]++;
    for(i=0;b[i]!='\0';i++)
    {
        h[a[i]-97]--;
        if(h[a[i]-97]<0)
        {
            printf("not anagram");
            break;
        }
    }
    if(b[i]=='\0')
        printf("its anagram");
}

int main()
{
    char a[]="decimal";
    char b[]="medical";
    hash(a,b);

    return 0;
}