#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

int main(){
    dnode *head = NULL;
    printf("---- Testing Doubly Linked List ----\n");
    printf("Test adding\n");
    //Added 10, 20 ,30, in back 5
    dlist_push_front(&head, 10);
    dlist_push_front(&head, 20);
    dlist_push_front(&head, 30);
    dlist_push_back(&head, 5);
    printf("Result: ");
    dlist_print(head);
    printf("Size: %d\n", dlist_size(head));


    printf("Test Inserting 25\n");
    dlist_insert(&head, 1, 25);
    printf("Current List: ");
    dlist_print(head); 
    printf("\n");

    //Test setting
    printf("Test setting:\n");
    dlist_set(&head, 1, 27);
    dlist_set(&head, 0, 50);
    dlist_set(&head, dlist_size(head)-1, 5);
    printf("Current List: ");
    dlist_print(head); 
    printf("\n");

    //Test removing
    printf("Test: Removing indexes 1, 2, 3\n");
    dlist_remove(&head, 1);
    dlist_remove(&head, 1);
    dlist_remove(&head, 1);
    printf("Current List: ");
    dlist_print(head); 
    printf("\n");



    // 4. Test Information methods
    printf("List Size: %d\n", dlist_size(head));
    printf("Value at index 0: %d\n", dlist_get(head, 0));

    // 5. Test Search
    printf("Test search\n");
    int search_val = 20;
    int index = dlist_find(head, search_val);
    if (index != -1) {
        printf("Value %d found at index %d\n", search_val, index);
    } else {
      printf("Value %d not found\n", search_val);
    }
    dlist_push_back(&head, 20);
    index = dlist_find(head, search_val);
    if (index != -1) {
        printf("Value %d found at index %d\n", search_val, index);
    } else {
      printf("Value %d not found\n", search_val);
    }
    // 6. Test Cleanup (Memory Management)
    printf("\nFreeing memory...\n");
    dlist_free(&head);

    if (head == NULL) {
        printf("Memory freed successfully. Head is now NULL.\n");
    }

    return 0;
}