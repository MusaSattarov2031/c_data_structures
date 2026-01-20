/*stach.h*/

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

/*----structure----*/
typedef struct stack_node{
    int value;
    struct stack_node *next;
}stack_node;



void stack_push(stack_node **head, int value);
int stack_pop(stack_node **head, int value);
int stack_peek(stack_node *head);
int stack_isEmpty(stack_node *head);

#endif