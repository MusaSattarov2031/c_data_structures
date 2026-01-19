/* * linked_list.h
 * A singly linked list implementation for integers.
 * Part of the C_Data_Structures repository.
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
/* ---- Structure Definition ---- */

/**
 * Self-referential structure for a list node.
 * We must use 'struct node' inside to allow the 'next' pointer.
 */
typedef struct node{
    int value;
    struct node *next;
}node;

/*Node && lyfecycle management*/
node* create_node(int value);//Done
void list_free(node **head);//Done

/*Insertion & Altering*/
void list_push_front(node **head, int value);//Done
void list_push_back(node **head, int value);//Done
void list_insert(node **head, int index, int value);//Done
void list_set(node **head, int index, int value);//Done

/*Deletion*/
void list_pop_front(node **head);//Done
void list_remove(node **head, int index);//Done

/*Search & Info*/
int list_get(node *head, int index);//Done
int list_find(node *head, int value);//Done
int list_size(node *head);//Done
int list_valid_index(node *head, int index);//Done

/*Display*/
void list_print(node *head);//Done

#endif