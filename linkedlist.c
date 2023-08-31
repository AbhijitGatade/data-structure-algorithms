/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
void add_node_at_end();//Prototyping
void display_all_nodes();
void add_node_at_position();
void count_nodes();

struct node{
    int data;
    struct node *next;
};

struct node *head;
int length = 0;

int main()
{
    int ch;
    while(1){
        printf("\n1. To add node at end");
        printf("\n2. To display all nodes");
        printf("\n3. To add node at position");
        printf("\n4. To search node in list");
        printf("\n0. Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        if(ch == 1){
            add_node_at_end();
        }
        else if(ch == 2){
            display_all_nodes();
        }
        else if(ch == 3){
            add_node_at_position();
        }
        else{
            break;
        }
    }

    return 0;
}

void add_node_at_end(){
    int data;
    struct node *ptr, *tmp;
    
    printf("Enter value of node:");
    scanf("%d", &data);
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    if(head == NULL){
        head = ptr;
    }
    else{
        tmp = head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = ptr;
    }
    printf("Node added");
}

void display_all_nodes(){
    struct node *tmp;
    int count = 1;
    tmp = head;
    if(tmp == NULL){
        printf("List is empty");
    }
    else{
        while(tmp->next != NULL){
            printf("\nValue at %d is %d", count, tmp->data);
            tmp = tmp->next;
            count++;
        }
        printf("\nValue at %d is %d", count, tmp->data);
    }
}

void add_node_at_position(){
    int pos, data, count = 0;
    struct node *ptr, *tmp;
    printf("Enter position to insert node:");
    scanf("%d", &pos);
    count_nodes();
    if(pos > length){
        printf("Sorry, length is less than position.");
    }
    else{
        printf("Enter value for node:");
        scanf("%d", &data);
        ptr = (struct node*)malloc(sizeof(struct node));
        ptr->data = data;
        tmp = head;
        count = 1;
        while(tmp->next != NULL){
            count++;
            if(pos == count){
                ptr->next = tmp->next;
                tmp->next = ptr;
                break;
            }
            tmp = tmp->next;
        }
        printf("Node added");
    }
}


void count_nodes(){
    length = 0;
    struct node *tmp;
    if(head != NULL){
        tmp = head;
        length++;
        while(tmp->next != NULL){
            tmp = tmp->next;
            length++;
        }
    }
}
