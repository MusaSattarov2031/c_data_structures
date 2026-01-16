#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int value;
    struct node *next;
}node;

void node_init(node *n, int value, node *next_node){
    n->value = value;
    n->next = next_node;
}

int main(){
}