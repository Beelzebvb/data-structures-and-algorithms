//
//  node.h
//  data structures and algorithms
//
//  Created by Abdoulaye Dia on 21/11/2021.
//

#ifndef node_h
#define node_h

#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node{
    int data;
    node* next;
};

void insert_at_begining(node** head, int data);
void insert_at_end(node** head, int data);
void insert_at(node** head, int n, int data);
void insert_at_middle(node** head, int data);

int remove_value(node** head, int value);
int remove_values(node** head, int value);

void clear_linked_list(node* head);
void fill_linked_list(node* head, int value);

void print_linked_list(node* head);

void free_linked_list(node** head);


#endif /* node_h */
