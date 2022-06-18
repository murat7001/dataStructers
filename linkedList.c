#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student{
    int id;
    char name[21];
    struct Student *next;
}student_t;

student_t *head=NULL;

int addStudent(int id, char *name);
int instruction();
int deleteStudent(int id);
int display();


int main(){
    int choice=0;
    int x=0;
    char name[21];
    while(choice!=4){
        instruction();
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Please enter the id of the student:");
                scanf("%d",&x);
                printf("Please enter the name of the student:");
                scanf("%s",name);
                addStudent(x,name);
                break;
            case 2:
                printf("Please enter student id: ");
                scanf("%d",&x);
                deleteStudent(x);
                break;
            case 3:
                display();
                break;
            case 4:
                break;
        }
    }
    

}

int instruction(){
    printf("\nPlease enter 1 to add a student.\nPlease enter 2 to remove a student.\nPlease enter 3 to print list.\nPlease enter 4 to exit.\nYour answer:");
    return 0;
}

int addStudent(int id, char *name){
    if(head ==NULL){
        student_t *newStudent = malloc(sizeof(student_t));
        newStudent->id = id;
        strcpy(newStudent->name, name);
        newStudent->next=NULL;
        head=newStudent;
    }

    else{
        student_t *index = head;
        student_t *prev=NULL;
        while(index!=NULL && id>index->id){
            prev = index;
            index = index->next;
        }

        if(prev==NULL){
            student_t *newStudent = malloc(sizeof(student_t));
            newStudent->id = id;
            strcpy(newStudent->name, name);
            newStudent->next=head;
            head=newStudent;
        }

        else
        {
            student_t *newStudent = malloc(sizeof(student_t));
            newStudent->id = id;
            strcpy(newStudent->name, name);
            newStudent->next=NULL;
            prev->next=newStudent;
            newStudent->next=index;
        }
    }
}

int deleteStudent(int id){
    if(head ==NULL){
        printf("This list is empty.\n");
    }

    if(head->id==id){
        student_t *temp=head;
        head=head->next;
        free(temp);
    }

    else{
        student_t *prev=NULL;
        student_t *index= head;
        while(index!=NULL && id!=index->id){
            prev=index;
            index=index->next;
        }

        if(index ==NULL){
            printf("This data is not found.");
        }

        prev->next=index->next;

        free(index);
    }
    return 0;
}

int display(){
    if(head==NULL){
        printf("This list is empty.\n");
    }

    else{
        student_t *index = head;
        printf("\n-----List of students-----\n");
        while(index!=NULL)
        {
            printf("Id:%d ", index->id);
            printf("Name:%s\n", index->name);
            index = index->next;
        }
        printf("\n");
    }
}
