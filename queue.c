#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node_t;

int enqueue(int data);
int dequeue();
int print();


node_t *head=NULL;
node_t *tail=NULL;


int main()
{
    enqueue(5);
    enqueue(8);
    print();
    dequeue();
    print();
    enqueue(7);
    print();
    dequeue();
    print();
}

int enqueue(int data)
{
    if (head==NULL)
    {
        node_t *newPtr=malloc(sizeof(node_t));
        newPtr->data=data;
        newPtr->next=NULL;
        head=tail=newPtr;
    }

    else
    {
        node_t *newPtr=malloc(sizeof(node_t));
        newPtr->data=data;
        newPtr->next=NULL;
        tail->next=newPtr;
        tail=newPtr;
    }
    
}

int dequeue()
{
    if (head==NULL)
    {
        printf("This list is empty.");
    }

    node_t *temp=head;
    head=head->next;
    free(temp);
    return 0;
}

int print()
{
    if(head==NULL)
    {
        printf("This list is empty.");
    }

    else
    {
        printf("Queue: ");
        node_t *index=head;
        while (index!=NULL)
        {
            printf("%d-",index->data);
            index=index->next;
        }
        printf("\n");
    }
}