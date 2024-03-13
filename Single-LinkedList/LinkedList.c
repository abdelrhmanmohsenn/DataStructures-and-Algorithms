
#include "LinkedList.h"

void NodeAtBegining(struct node **head){
    struct node *tempnode=NULL;
    tempnode=(struct node *)malloc(sizeof(struct node));
    if(tempnode){
        printf("enter node data :");
        scanf("%i",&tempnode->data);
        if(NULL != *head){
            tempnode->nodelink=*head;
            *head=tempnode;
        }
        else{
            *head=tempnode;
            tempnode->nodelink=NULL;
        }
    }
    else{
        printf("can not create node !\n");
    }
}

void NodeAtEnd(struct node **head){
    struct node *tempnode=NULL;
    struct node *lastnode=NULL;
    tempnode=(struct node *)malloc(sizeof(struct node));
    if(tempnode){
        printf("enter node data :");
        scanf("%i",&tempnode->data);
        tempnode->nodelink=NULL;
        if(NULL == *head){
            *head=tempnode;
        }
        else{
            lastnode=*head;
            while(lastnode->nodelink != NULL){
                lastnode=lastnode->nodelink;
            }
            lastnode->nodelink=tempnode;
        }
    }
    else{
        printf("can not create node !\n");
    }
}

void NodeAfter(struct node *head){
    struct node *tempnode=NULL;
    struct node *listcounternode=NULL;
    unsigned int listlength=0, nodepostion=0, listcounter=1;

    printf("enter the postion of the node :");
    scanf("%i",&nodepostion);
    listlength=get_length(head);
    if(nodepostion>listlength){
        printf("invalid position !!\n");
    }
    else{
        tempnode=(struct node *)malloc(sizeof(struct node));
        if(tempnode){
            printf("enter node data :");
            scanf("%i",&tempnode->data);
            listcounternode=head;
            while(listcounter<nodepostion){
                listcounter++;
                listcounternode=listcounternode->nodelink;
            }
            tempnode->nodelink=listcounternode->nodelink;
            listcounternode->nodelink=tempnode;
        }
        else{
            printf("can not create node !\n");
        }
    }
}

unsigned int get_length(struct node *head){
    unsigned int counter=1;
    struct node *tempnode=head;
    while(NULL != tempnode->nodelink){
        tempnode=tempnode->nodelink;
        counter++;
    }

    return counter;
}

void DeleteNodeBegining(struct node **head){
    struct node *tempnode=*head;
    unsigned int length=0;
    length=get_length(*head);
    if(length == 0){
        printf("list is empty !!\n");
    }
    else{
        *head=tempnode->nodelink;
        free(tempnode);
        tempnode=NULL;
    }
}

void deletenode(struct node *head){
    struct node *tempnode=NULL;
    struct node *listcounternode=NULL;
    unsigned int nodepostion=0,listlength=0,listcounter=1;
    printf("enter node position :");
    scanf("%i",&nodepostion);
    listlength=get_length(head);
    if(nodepostion>listlength || listlength == 1){
        printf("invalid position\n");
    }
    else{
        listcounternode=head;
        while(listcounter<(nodepostion-1)){
            listcounternode=listcounternode->nodelink;
            listcounter++;
        }
        tempnode=listcounternode->nodelink;
        listcounternode->nodelink=tempnode->nodelink;
        tempnode->nodelink=NULL;
        free(tempnode);
        tempnode=NULL;
    }
}

void displaynodes(struct node *head){
    struct node *tempnode=head;
    printf("all nodes data :");
    while(tempnode->nodelink != NULL){
        printf("->%i ",tempnode->data);
        tempnode=tempnode->nodelink;
    }
    printf("->%i ->NULL\n",tempnode->data);
}
