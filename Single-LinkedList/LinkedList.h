
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

struct node{
    unsigned int data;
    struct node *nodelink;
};

void NodeAtBegining(struct node **head);
void NodeAtEnd(struct node **head);
void NodeAfter(struct node *head);
unsigned int get_length(struct node *head);
void DeleteNodeBegining(struct node **head);
void deletenode(struct node *head);
void displaynodes(struct node *head);

#endif // LINKED_LIST_H
