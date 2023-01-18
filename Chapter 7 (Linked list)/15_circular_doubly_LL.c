#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *first = NULL;

void create(int a[],int n)
{
    struct node *t,*last;
    int i;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=first->prev=first;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void display(struct node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != first);
    printf("\n");
}

void insert(struct node *p, int index, int x)
{

}

int main()
{
    int a[]={2,4,6,8,10};
    create(a,5);

    // insert(first,2,3);
    display(first);

    return 0;
}