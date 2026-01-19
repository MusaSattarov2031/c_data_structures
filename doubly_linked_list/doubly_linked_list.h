/*doubly_linked_list.h
Doubly linked list implementation for integers
Part of the C_Data_Structures repo
*/

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

/*---- Structure Defenition ----*/

typedef struct dnode{
    int value;
    struct dnode *prev;
    struct dnode *next;
}dnode;

/*Node Lyfecycle*/
dnode* create_dnode(int value);
void dlist_free(dnode **head);

/*Insertion & Altering*/
void dlist_push_front(dnode **head, int value);
void dlist_push_back(dnode **head, int value);
void dlist_insert(dnode **head, int index, int value);
void dlist_set(dnode **head, int index, int value);

/*Deletion*/
void dlist_pop_front(dnode **head);
void dlist_remove(dnode **head, int index);

/*Search & Info*/
int dlist_get(dnode *head, int index);
int dlist_find(dnode *head, int value);
int dlist_size(dnode *head);
int dlist_valid_index(dnode *head, int index);

/*Display*/
void dlist_print(dnode *head);


#endif