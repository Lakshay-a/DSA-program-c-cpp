// CHECKING IF STRING CONSISTS OF ONLY LOWERCASE OR UPPERCASE LETTERS AND NUMBERS
#include <stdio.h>

int valid(char *str)
{
    int i=0;
    while(*str!='\0')
    {
        if (!(*str>=65 && *str<=90) && !(*str>=97 && *str<=122) && !(*str>=48 && *str<=57))
            return 0;
        str++;
    }
    return 1;
}

int main()
{
    char *name="Lakshay995";
    if (valid(name))
        printf("This is a valid username");
    else
        printf("This is not a valid username");

    return 0;
}