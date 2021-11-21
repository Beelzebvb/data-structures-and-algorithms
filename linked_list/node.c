//
//  node.c
//  data structures and algorithms
//
//  Created by Abdoulaye Dia on 21/11/2021.
//

#include "node.h"

void insert_at_begining(node** head, int data)
{
    node* newNode = (node*)(malloc(sizeof(node)));
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL)
    {
        *head = newNode;
    }else{
        newNode->next = *head;
        *head = newNode;
    }
}

void insert_at_end(node** head, int data)
{
    node* newNode = (node*)(malloc(sizeof(node)));
    newNode->data = data;
    newNode->next = NULL;
    
    node* temp = *head;
    
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = newNode;
}

void insert_at(node** head, int n, int data)
{
    if(n == 0)
    {
        insert_at_begining(head, data);
        return;
    }
    
    node* temp = *head;
    for (int i = 0; i < n -1 && temp != NULL; ++i) {
        temp = temp->next;
    }
    
    if(temp != NULL)
    {
        node* newNode = (node*)(malloc(sizeof(node)));
        newNode->data = data;
        newNode->next = temp->next;
        
        temp->next = newNode;
    }
}

void insert_at_middle(node** head, int data)
{
    int size = 0;
    
    node* temp = *head;
    while(temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    
    insert_at(head, size/2, data);
}

int remove_value(node** head, int value)
{

    node* temp = *head;
    while (temp->next != NULL) {
        
        if(temp->next->data == value){
            node* freeNode = temp->next;
            temp->next = temp->next->next;
            free(freeNode);
            return 1;
        }
        temp = temp->next;
    }
    
    return 0;
}

int remove_values(node** head, int value)
{
    if((*head)->data == value)
    {
        node* freeNode = *head;
        *head = (*head)->next;
        free(freeNode);
    }
    
    node* temp = *head;
    while(temp->next != NULL)
    {
        if(temp->data == value)
        {
            node* freeNode = temp;
            temp = temp->next;
            free(freeNode);
        }
        else if(temp->next->data == value)
        {
            node* freeNode = temp->next;
            temp->next = temp->next->next;
            free(freeNode);
        }
        temp = temp->next;
    }
    return 0;
}


void clear_linked_list(node* head)
{
    fill_linked_list(head, 0);
}

void fill_linked_list(node* head, int value)
{
    while(head != NULL)
    {
        head->data = value;
        head = head->next;
    }
}

void print_linked_list(node* head)
{
    while (head != NULL) {
        if(head->next != NULL)
            printf("%d --> ", head->data);
        else
            printf("%d --> END\n", head->data);
        head = head->next;
    }
}


void free_linked_list(node** head)
{
    while (*head != NULL) {
        node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

