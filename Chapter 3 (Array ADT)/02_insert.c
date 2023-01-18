#include <stdio.h>

void insert(int a[], int in, int x, int *l)
{
    int i;
    if (in >= 0 && in <= *l)
    {
        for (i = *l; i > in; i--)
        {
            a[i] = a[i - 1];
        }
        a[in] = x;
        (*l)++;
    }
}

void display(int a[], int l)
{
    int i;
    printf("Elements are: \n");
    for (i = 0; i < l; i++)
    {
        printf("%d \n", a[i]);
    }
}

int main()
{
    int a[10] = {4, 5, 7, 8, 9};
    int l = 5, i;
    insert(a, 2, 6, &l);
    display(a, l);
    return 0;
}