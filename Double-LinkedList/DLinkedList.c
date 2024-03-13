
#include "DLinkedList.h"

void Insert_Node_At_Beginning(struct node **head, unsigned int Data){
    struct node *tempnode=NULL;
    tempnode=(struct node *)malloc(sizeof(struct node));
    if(tempnode){
        tempnode->data=Data;
        if(*head != NULL){
            tempnode->rightnode=*head;
            *head=tempnode;
            (*head)->leftnode=tempnode;
            tempnode->rightnode=NULL;
        }
        else{
            tempnode->leftnode=NULL;
            tempnode->rightnode=NULL;
            *head=tempnode;
        }
    }
    else{
        printf("can not create node\n");
    }
}

void Insert_Node_At_End(struct node **head,unsigned int data){
    struct node *tempnode=NULL;
    struct node *lastnode=NULL;

    tempnode=(struct node *)malloc(sizeof(struct node));
    if(tempnode){
        tempnode->data=data;
        tempnode->rightnode=NULL;
        if(NULL == *head){
            tempnode->leftnode=NULL;
            *head=tempnode;
        }
        else{
            lastnode=*head;
            while(lastnode->rightnode != NULL){
                lastnode=lastnode->rightnode;
            }
            lastnode->rightnode=tempnode;
            tempnode->leftnode=lastnode;
        }
    }
    else{
        printf("can not create node\n");
    }
}

void Insert_Node_After(struct node *head, unsigned int data,unsigned int listposition){
    struct node *tempnode=NULL;
    struct node *listnodecounterone=NULL;
    struct node *listnodecountertwo=NULL;
    unsigned int listlength=0, listcounter=1;

    listlength=get_length(head);
    if(listlength<listposition){
        printf("invalid position!\n");
    }
    else{
        tempnode=(struct node *)malloc(sizeof(struct node));
        if(tempnode){
            tempnode->data=data;
            listnodecounterone=head;
            while(listcounter<listposition){
                listcounter++;
                listnodecounterone=listnodecounterone->rightnode;
            }
            if(listnodecounterone->rightnode == NULL){
                listnodecounterone->rightnode=tempnode;
                tempnode->leftnode=listnodecounterone;
                tempnode->rightnode=NULL;
            }
            else{
                listnodecountertwo=listnodecounterone->rightnode;
                tempnode->rightnode=listnodecountertwo;
                listnodecountertwo->leftnode=tempnode;
                listnodecounterone->rightnode=tempnode;
                tempnode->leftnode=listnodecounterone;
            }
        }
        else{
            printf("can not create node\n");
        }
    }
}

void Insert_Node_Before(struct node **head, unsigned int Data, unsigned int position){
    struct node *tempnode=NULL;
    struct node *nodelistcounterone=NULL;
    struct node *nodelistcountertwo=NULL;
    unsigned int counter=1,length;

    length=get_length(*head);
    if(position>length){
        printf("invalid position\n");
    }
    else{
        tempnode=(struct node *)malloc(sizeof(struct node));
        if(tempnode){
            tempnode->data=Data;
            nodelistcounterone=*head;
            if(position == 1){
                nodelistcounterone->rightnode=tempnode;
                tempnode->leftnode=nodelistcounterone;
                tempnode->rightnode=NULL;
                *head=tempnode;
            }
            else{
                while(counter<position){
                    counter++;
                    nodelistcounterone=nodelistcounterone->rightnode;
                }
                nodelistcountertwo=nodelistcounterone->leftnode;
                nodelistcounterone->leftnode=tempnode;
                nodelistcountertwo->rightnode=tempnode;
                tempnode->rightnode=nodelistcounterone;
                tempnode->leftnode=nodelistcountertwo;
            }
        }
        else{
            printf("can not create node\n");
        }
    }
}

void Display_All_Nodes_Forward(struct node *head){
    struct node *tempnode=NULL;
    if(head == NULL){
        printf("list is empty\n");
    }
    else{
        tempnode=head;
        printf("node data : ");
        while(tempnode->rightnode != NULL){
            printf("->%i ",tempnode->data);
            tempnode=tempnode->rightnode;
        }
        printf("->%i ->NULL\n",tempnode->data);
    }
}

unsigned int get_length(struct node *head){
    struct node *tempnode=head;
    unsigned int counter=1;
    if(tempnode == NULL){
        counter=0;
    }
    else{
        while(tempnode->rightnode != NULL){
            counter++;
            tempnode=tempnode->rightnode;
        }
    }
    return counter;
}

void Display_All_Nodes_Reverse(struct node *head){
    struct node *tempnode=NULL;
    if(head == NULL){
        printf("list is empty\n");
    }
    else{
        tempnode=head;
        while(tempnode->rightnode != NULL){
            tempnode=tempnode->rightnode;
        }
        while(tempnode != head){
            printf("->%i ",tempnode->data);
            tempnode=tempnode->leftnode;
        }
        printf("->%i ->NULL\n",tempnode->data);
    }
}

void Delete_Node_At_Beginning(struct node **head){
    struct node *tempnode=NULL;
    struct node *nodelist=NULL;
    unsigned int length=0;
    if(NULL == *head){
        printf("list is empty\n");
    }
    else{
        length=get_length(*head);
        if(length == 1){
            tempnode=*head;
            free(tempnode);
            *head=NULL;
            tempnode=NULL;
        }
        else{
            tempnode=*head;
            nodelist=tempnode->rightnode;
            nodelist->leftnode=NULL;
            *head=nodelist;
            tempnode->rightnode=NULL;
            free(tempnode);
            tempnode=NULL;
        }
    }
}

void Delete_Node_At_End(struct node *head){
    struct node *tempnode=NULL;
    struct node *nodelist=NULL;
    unsigned int length=0;
    if(NULL == head){
        printf("list is empty\n");
    }
    else{
        length=get_length(head);
        if(length == 1){
            tempnode=head;
            free(tempnode);
            head=NULL;
            tempnode=NULL;
        }
        else{
            tempnode=head;
            while(tempnode->rightnode != NULL){
                tempnode=tempnode->rightnode;
            }
            nodelist=tempnode->leftnode;
            nodelist->rightnode=NULL;
            tempnode->leftnode=NULL;
            free(tempnode);
            tempnode=NULL;
        }
    }
}

void Delete_Node_At_Intermediate(struct node *head, unsigned int position){
    struct node *tempnode=NULL;
    struct node *nodelist=NULL;
    if(NULL == head){
        printf("list is empty\n");
    }
    else{

    }
}
