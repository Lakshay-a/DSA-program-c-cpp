#include <stdio.h>

void unsorted(char a[], int len)
{
    int i, count, j;
    for (i = 0; i < len - 1; i++)
    {
        count = 1;
        if (a[i] != 0)
        {
            for (j = i + 1; j < len; j++)
            {
                if (a[i] == a[j])
                {
                    count++;
                    a[j] = 0;
                }
            }
        }
        if (count > 1)
            printf("%c is repeated %d times\n", a[i], count);
    }
}

// USING HASH TABLE
void hash_dup(char a[], int len)
{
    int h[26]={0}, i;
    for (i = 0; i < len; i++)
    {
        h[a[i] - 97]++;
    }
    for (i = 0; i < 26; i++)
    {
        if (h[i] > 1)
            printf("%c is repeated %d times\n", i + 97, h[i]);
    }
}

// USING BITWISE OPERATIONS
void bit(char a[])
{
    int i;
    long int h = 0, x = 0;
    for (i = 0; a[i] != '\0'; i++)
    {
        x = 1;
        x = x << (a[i] - 97);
        if ((x & h) > 0)
            printf("%c is duplicate\n", a[i]);
        else
            h = x | h;
    }
}

int main()
{
    char a[] = "finding";
    int len = sizeof(a) / sizeof(char);
    // unsorted(a,len);
    hash_dup(a,len);
    // bit(a);

    return 0;
}
