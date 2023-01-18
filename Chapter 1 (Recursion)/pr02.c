//? EVALUATING A GIVEN NUMBER "m" RAISED TO THE POWER "n"
#include <stdio.h>

int power(int m, int n)             //Usual way
{
    if (n == 0)
        return 1;
    return power(m, n - 1) * m;
}

int power1(int m, int n)            //More efficient or faster way
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return power1(m * m, n/2);
    else
        return m * power1(m * m, (n - 1) / 2);
}

int main()
{
    int r = power1(9, 3);
    printf("%d ", r);
    return 0;
}