#include<stdio.h>
typedef int cat;

typedef struct node
{
    int data;
    struct node *next;
}node;

node *create(int x);
node * insert_end(node *head, int x);
node *insert_beg(node *head, int x);
int main()
{
    node *head = NULL;
    head = insert_end(head, 10);
    head = insert_end(head, 20);
    head = insert_end(head, 30);
    display(head);
    head = insert_beg(head, 15);
    display(head);

}
node *create(int x)
{
    node *new = (node *)malloc(sizeof(node));
    new -> data = x;
    new -> next = NULL;
    return new;
}
node * insert_end(node *head, int x)
{
    node *new = create(x);
    node *temp = head;

    if(!head)
    {
        head = new;
        return head;
    }
    while(temp -> next)
    {
        temp = temp -> next;
    }
    temp -> next = new;
    return head;
}

node *insert_beg(node *head, int x)
{
    node *new = create(x);
    new -> next = head;
    head = new;
    return head;
}

void display(node *head)
{
    if(!head)
    {
        printf("No node to display\n");
        return;
    }
    node *temp = head;
    while(temp)
    {
        printf("|%d| -> ", temp -> data);
        temp = temp -> next;
    }
    printf("N\n");
}


