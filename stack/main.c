#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    stack_node *head = NULL;

    printf("----Testing Stack----\n");
    printf("Adding 10, 20, 30\n");

    stack_push(&head, 10);
    stack_push(&head, 20);
    stack_push(&head, 30);

}