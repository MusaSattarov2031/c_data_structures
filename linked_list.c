#import <stdio.h>
#import <stdlib.h>


typedef struct{
    int value;
    struct node *next;
}node;

void node_init(node *n, int value, node *next_node){
    n->value = value;
    n->next = next_node;
}