/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
void add_node_at_end();//Prototype
void display_all_nodes();

struct node{
  int data;
  struct node *next;
};

struct node *head;


int main()
{
    int ch;
    while(1){
        printf("\n1. Insert node at end");
        printf("\n2. Display all nodes");
        printf("\n0. Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        if(ch == 1){
            add_node_at_end();
        }
        else if(ch == 2){
            display_all_nodes();
        }
        else if(ch == 0){
            break;
        }
    }

    return 0;
}


//Function to add node at end
void add_node_at_end(){
    int val;
    struct node *ptr, *temp;
    
    printf("Enter value:");
    scanf("%d", &val);
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = val;
    //Check if its first node
    if(head == NULL){
        ptr->next = NULL;
        head = ptr;
    }
    else{
        //Take first node in consideration
        temp = head;
        //Try to find last node
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = NULL;
    }
    printf("Node inserted");
}

void display_all_nodes(){
    struct node *ptr;
    int count = 0;
    ptr = head;
    if(head == NULL){
        printf("No node in list");
    }
    else{
        while(ptr->next != NULL){
            printf("\nNode at %d is %d", count, ptr->data);
            ptr = ptr->next;
            count++;
        }
        printf("\nNode at %d is %d", count, ptr->data);
    }
}


