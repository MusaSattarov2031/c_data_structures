#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void stack_push(stack_node **head, int value){
    stack_node *new = malloc(sizeof(stack_node));
    if (new ==NULL) return;
    new->value = value;
    new->next = *head;
    *head = new;
}