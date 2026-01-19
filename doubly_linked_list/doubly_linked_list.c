#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"


dnode* create_dnode(int value){
    dnode* self = malloc(sizeof(dnode));
    if (self == NULL){
        printf("Memory Allocation Error");
        return NULL;
    }
    self->value = value;
    self->next = NULL;
    self->prev = NULL;

    return self;
}

void dlist_free(dnode **head){
    dnode *current = *head;
    dnode *next_node;

    while (current!= NULL){
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head = NULL;
}

void dlist_push_front(dnode **head, int value){
    dnode *new_head = create_dnode(value);
    new_head->next = *head;
    if (*head != NULL){
        (*head)->prev = new_head;
    }
    *head = new_head;
}

void dlist_push_back(dnode **head, int value){
    dnode *current = *head;
    while(current->next != NULL){
        current = current->next;
    }
    dnode *new_node = create_dnode(value);
    new_node->prev = current;
    current->next = new_node;
}

int dlist_size(dnode *head){
    dnode *curr = head;
    int size = 0;
    while (curr!= NULL)
    {
        curr = curr->next;
        size++;
    }
    return size;
}

int dlist_valid_index(dnode * head, int index){
    int size = dlist_size(head); 
    if (index<0 || index>=size){
        printf("Invalid Index: size is %d\n", size);
        return 0;
    }else{
        return 1;
    }
}

void dlist_insert(dnode **head, int index, int value){
    if (!dlist_valid_index(*head, index)){
        return;
    }
    if (index == 0){
        dlist_push_front(head, value);
        return;
    }
    dnode *prev = *head;
    for (int i = 0; i<index-1; i++){
        prev = prev->next;
    }
    dnode *new_node = create_dnode(value);
    new_node->next= prev->next;
    new_node->prev = prev;
    if (prev->next != NULL) {
    prev->next->prev = new_node; 
    }
    prev->next = new_node;
}

void dlist_set(dnode **head, int index, int value){
    if (!dlist_valid_index(*head, index)){
        return;
    }
    dnode *cur = *head;
    for (int i = 0; i<index; i++){
        cur = cur->next;
    }
    cur->value=value;
}

void dlist_print(dnode *head){
    dnode *curr = head;
    while (curr!=NULL){
        printf("%d<->", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

void dlist_pop_front(dnode **head){
    if (*head ==NULL) return;
    dnode *temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void dlist_remove(dnode **head, int index){
    if (!dlist_valid_index(*head, index)) return;
    if (index == 0){
        dlist_pop_front(head);
        return;
    }
    dnode *prev = *head;
    for (int i = 0; i < index - 1; i++) {
        prev = prev->next;
    }
    dnode * to_delete = prev->next;
    prev->next = to_delete->next;
    to_delete->next->prev = prev;
    free(to_delete);
}

int dlist_get(dnode *head, int index){
    if (!dlist_valid_index(head, index)) {
        printf("Invalid index, returning -1\n");
        return -1;
    }
    if (index == 0) return head->value;
    dnode *curr = head;
    for (int i = 0; i<=index; i++){
        curr = curr->next;
    }
    return curr->value;
}

int dlist_find(dnode *head, int value){
    int idx = 0;
    dnode *curr = head;
    while (curr!=NULL){
        if (curr->value == value){
            return idx;
        }
        idx++;
        curr = curr->next;
    }
    return -1;
}