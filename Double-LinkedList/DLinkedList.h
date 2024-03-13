
#ifndef DLINKED_LIST_H
#define DLINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

struct node{
    unsigned int data;
    struct node *leftnode;
    struct node *rightnode;
};

void Insert_Node_At_Beginning(struct node **head, unsigned int Data);
void Insert_Node_At_End(struct node **head,unsigned int data);
void Insert_Node_After(struct node *head, unsigned int data,unsigned int listposition);
void Insert_Node_Before(struct node **head, unsigned int Data, unsigned int position);
void Display_All_Nodes_Forward(struct node *head);
unsigned int get_length(struct node *head);
void Display_All_Nodes_Reverse(struct node *head);
void Delete_Node_At_Beginning(struct node **head);
void Delete_Node_At_End(struct node *head);
void Delete_Node_At_Intermediate(struct node *head, unsigned int position);

#endif // DLINKED_LIST_H
