#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};typedef struct Node node;

node *create_node(int data,node *next){
    node * New = (node*)malloc(sizeof(node));
    New->data = data;
    New->next=next;
}

node *add_tail(node *head,int data){
    node * current = head;
    while (current->next!=NULL)
    {
        current = current->next;
    }
    current->next = create_node(data,NULL);
    return head;
}

node *add_head(node *head,int data){
    head = create_node(data,head);
    return head;
}

void print_list(node *head){
    node * current = head;
    printf("[");
    while(current->next!=NULL)
    {
        printf("%d,",current->data);
        current = current->next;
    }
    printf("%d]",current->data);
}

node *add_pos(node *head,int pos,int data){
    if(head==NULL){
        return create_node(data,NULL);
    }
    if(pos==0){
        head = add_head(head,data);
        return head;
    }
    node * current = head;
    node * precurrent = head;
    int i = 0;
    while (i<pos && current!=NULL)
    {
        i++;
        precurrent = current;
        current=current->next;
    }
    if(current==NULL){
        head = add_tail(head,data);
    }
    else{
        precurrent->next = create_node(data,precurrent->next);
    }
    return head;
}