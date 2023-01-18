#include <stdio.h>

void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void perm(char s[],int k)
{
    static int a[10]={0};
    static char r[10];
    int i;
    if(s[k]=='\0')
    {
        r[k]='\0';
        printf("%s\n",r);
    }
    else
    {
        for (i=0;s[i]!='\0';i++)
        {
            if(a[i]==0)
            {
                r[k]=s[i];
                a[i]=1;
                perm(s,k+1);
                a[i]=0;
            }
        }
    }
}

void swap_perm(char s[],int l,int h)
{
    int i;
    if(l==h)
        printf("%s\n",s);
    else
    {
        for (i=l;i<=h;i++)
        {
            swap(&s[l],&s[i]);
            swap_perm(s,l+1,h);
            swap(&s[l],&s[i]);

        }
    }
}

int main()
{
    char s[]="ABC";
    int len = sizeof(s) / sizeof(char);
    perm(s,0);
    // swap_perm(s,0,len-2);

    return 0;
}