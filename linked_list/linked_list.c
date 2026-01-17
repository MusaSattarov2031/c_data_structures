#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


node* create_node(int value){
    node *res = malloc(sizeof(node));
    if (res == NULL){
        printf("Memory Allocation Failed");
        return NULL;
    }
    res->value = value;
    res->next = NULL;

    return res;
}

void list_free(node **head){
    node *current = *head;
    node *next_node;

    while (current!= NULL){
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head = NULL;
}

void list_push_front(node **head, int value){
    node *new_head = create_node(value);
    new_head->next = *head;
    *head = new_head;
}

void list_push_back(node **head, int value){
    node *current = *head;
    while(current->next != NULL){
        current = current->next;
    }
    node *new_node = create_node(value);
    current->next = new_node;
}

int list_size(node *head){
    node *curr = head;
    int size = 0;
    while (curr!= NULL)
    {
        curr = curr->next;
        size++;
    }
    return size;
}

int list_valid_index(node * head, int index){
    int size = list_size(head); 
    if (index<0 || index>=size){
        printf("Invalid Index: size is %d\n", size);
        return 0;
    }else{
        return 1;
    }
}

void list_insert(node **head, int index, int value){
    if (!list_valid_index(*head, index)){
        return;
    }
    if (index == 0){
        list_push_front(head, value);
        return;
    }
    node *prev = *head;
    for (int i = 0; i<index-1; i++){
        prev = prev->next;
    }
    node *new_node = create_node(value);
    new_node->next= prev->next;
    prev->next = new_node;
}

void list_set(node **head, int index, int value){
    if (!list_valid_index(*head, index)){
        return;
    }
    node *cur = *head;
    for (int i = 0; i<index; i++){
        cur = cur->next;
    }
    cur->value=value;
}

void list_print(node *head){
    node *curr = head;
    while (curr!=NULL){
        printf("%d->", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

void list_pop_front(node **head){
    if (*head ==NULL) return;
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void list_remove(node **head, int index){
    if (!list_valid_index(*head, index)) return;
    if (index == 0){
        list_pop_front(head);
        return;
    }
    node *prev = *head;
    for (int i = 0; i < index - 1; i++) {
        prev = prev->next;
    }
    node * to_delete = prev->next;
    prev->next = to_delete->next;
    free(to_delete);
}

int list_get(node *head, int index){
    if (!list_valid_index(head, index)) {
        printf("Invalid index, returning -1\n");
        return -1;
    }
    if (index == 0) return head->value;
    node *curr = head;
    for (int i = 0; i<=index; i++){
        curr = curr->next;
    }
    return curr->value;
}

int list_find(node *head, int value){
    int idx = 0;
    node *curr = head;
    while (curr!=NULL){
        if (curr->value == value){
            return idx;
        }
        idx++;
        curr = curr->next;
    }
    return -1;
}