//? SUM OF N NATURAL NUMBERS USING RECURSION AND LOOP
#include <stdio.h>

int sum(int n)              //USING RECURSION
{
    if(n==0)
        return 0;
    return sum(n-1)+n;
}

int Lsum(int n)             //USING LOOP
{
    int i,s=0;
    for(i=1;i<=n;i++)
    {
        s+=i;
    }
    return s;
}

int main()
{
    int r;
    r=sum(5);
    printf("%d",r);
    return 0;
}


//? FACTORIAL OF A GIVEN NUMBER USING RECURSION AND LOOP

// int fact(int n)                 //USING RECURSION
// {
//     if (n == 0)
//         return 1;
//     return fact(n - 1) * n;
// }

// int Lfact(int n)                //USING LOOP
// {
//     int f = 1, i;
//     for (i = 1; i <= n; i++)
//         f = f * i;
//     return f;
// }

// int main()
// {
//     int r = fact(5);
//     printf("%d ", r);
//     return 0;
// }