#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
} *top = NULL;

void push(char x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop()
{
    struct Node *t;
    char x = -1;
    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
} 

char stackTop(struct Node *t)
{
    if(top==NULL)
        return -1;
    return top->data;
}


void Display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int isBalanced(char *exp)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {
            if (top == NULL)
                return 0;
            pop();
        }
    }
    if (top == NULL)
        return 1;
    else
        return 0;
}

// generalised bracket matching
int bracket(char *exp)
{
    int i;
    char x;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
            push(exp[i]);
        else if (exp[i]==')' || exp[i]==']' || exp[i]=='}')
        {
            x=stackTop(top);
            if (x==-1)
                return 0;
            else if ((x<=45 && exp[i]<=45) && (x>=39 && exp[i]>=39))
                pop();
            else if ((x<=95 && exp[i]<=95) && (x>=90 && exp[i]>=90))
                pop();
            else if ((x<=127 && exp[i]<=127) && (x>=120 && exp[i]>=120))
                pop();
            else
                return -1;
        }
    }
    if (top == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    char *exp = "{[(a+b)*(c-d)}]";
    printf("%d ", bracket(exp));

    return 0;
}