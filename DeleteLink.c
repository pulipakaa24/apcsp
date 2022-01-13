#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// create a struct to create our linked list
typedef struct node
{
    int data;
    struct node * next;
}node;

node * createLnkList(int n);
int searchLink(node * head, int target);
void displayList(node * head);
node * deleteLink(node * head, int target);
void addLink(node * head, int addition);

int main()
{
    int n = 0;
    node * HEAD = NULL;
    printf("\n How many links or nodes ? ");
    scanf(" %d", &n);
    HEAD= createLnkList(n);
    displayList(HEAD);
    printf("\nEnter a value to search for, and the position will be returned, beginning with position 0.\n");
    scanf(" %d", &n);
    printf("Position: %i\n", searchLink(HEAD, n));
    printf("Enter a value to delete, and the remaining list will be printed.\n");
    scanf(" %d", &n);
    HEAD = deleteLink(HEAD, n);
    displayList(HEAD);
    printf("\nEnter a value to be added to the end of the linked list.\n");
    scanf(" %d", &n);
    addLink(HEAD, n);
    displayList(HEAD);
}

node * createLnkList(int n)
{
    node * head= NULL;
    node * temp= NULL;
    node * p= NULL;
    for(int i=0; i <n; i++)
    {
        temp= (node*)malloc(sizeof(node));
        printf("\n Enter the data for node number %i: ", i+1);
        scanf(" %d", &(temp->data));
        temp->next=NULL;

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            p= head;
            while(p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
    }
    return head;
}

int searchLink(node * head, int target)
{
    node * p = head;
    int i = 0;
    while (p != NULL)
    {
        if (p->data == target)
        {
            return i;
        }
        p = p->next;
        i++;
    }
    return -1;
}

void displayList(node * head)
{
    node * p = head;
    while(p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
}

node * deleteLink(node * head, int target)
{
    node * p0 = head;
    node * p1;

    if (p0 != NULL)
    {
        p1 = p0->next;
    }

    if (p0->data == target)
    {
        head = p0->next;
        free(p0);
        return head;
    }

    while (p1 != NULL)
    {
        if (p1->data == target)
        {
            p0->next = p1->next;
            free(p1);
            return head;
        }
        p0 = p1;
        p1 = p1->next;
    }
    return head;
}

void addLink(node * head, int addition)
{
    node * p0 = head;
    while (p0->next != NULL)
    {
        p0 = p0->next;
    }
    node * p1 = (node *)malloc(sizeof(node));
    p1->data = addition;
    p0->next = p1;
}