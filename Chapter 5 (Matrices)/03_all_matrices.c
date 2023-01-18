#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a, ch, n, x, i, j;
    printf("Enter dimension ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));   //for diagonal matrix
    do
    {
        printf("choose:\n");
        printf("1) Create\n");
        printf("2) Get\n");
        printf("3) Set\n");
        printf("4) Display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            for (i = 1; i <= n; i++)
            {
                scanf("%d", &a[i - 1]);
            }
            break;

        case 2:
            printf("Enter indices:");
            scanf("%d %d", &i, &j);
            if (i == j)
                printf("%d ", a[i - 1]);
            else
                printf("0 ");

        case 3:
            printf("Enter row, column and element:");
            scanf("%d %d %d", &i, &j, &x);
            if (i == j)
                a[i - 1] = x;
            break;

        case 4:
            for (i = 1; i < n; i++)
            {
                for (j = 1; j < n; j++)
                {
                    if (i == j)
                        printf("%d ", a[i]);
                    else
                        printf("0 ");
                }
                printf("\n");
            }
        }
    } while (1);

    return 0;
}