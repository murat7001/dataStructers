#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node_t;

node_t *head=NULL;

int push(int data);
int pop();
int display();

int main(){
    push(1);
    push(2);
    push(9);
    display();
    pop();
    display();
}


int push(int data){
    if(head==NULL){
        node_t *newPtr=malloc(sizeof(node_t));
        newPtr->data=data;
        newPtr->next=NULL;
        head=newPtr;
    }

    else{
        node_t *newPtr=malloc(sizeof(node_t));
        newPtr->data=data;
        newPtr->next=head;
        head=newPtr;
    }
}

int pop(){
    if(head==NULL){
        printf("This list is empty");
    }

    node_t *tempPtr=head;
    head=head->next;
    free(tempPtr);
}

int display(){
    if(head==NULL){
        printf("This list is empty.");
    }

    else{
        node_t *index=head;
        while(index!=NULL){
            printf("%d-",index->data);
            index=index->next;
        }
        printf("\n");
    }
}