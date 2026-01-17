#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main() {
    // 1. Initialize the head as NULL
    node *head = NULL;
    printf("--- Testing Linked List ---\n");

    // 2. Test Push Front (Should be: 30 -> 20 -> 10 -> NULL)
    printf("Adding 10, 20, 30 to front...\n");
    list_push_front(&head, 10);
    list_push_front(&head, 20);
    list_push_front(&head, 30);
    
    
    //3. Display the result
    printf("Current List: ");
    list_print(head); 
    printf("\n");
    printf("Test Inserting 25\n");
    list_insert(&head, 1, 25);
    printf("Current List: ");
    list_print(head); 
    printf("\n");

    printf("Test setting:\n");
    list_set(&head, 1, 27);
    list_set(&head, 0, 50);
    list_set(&head, list_size(head)-1, 5);
    printf("Current List: ");
    list_print(head); 
    printf("\n");



    // 4. Test Information methods
    printf("List Size: %d\n", list_size(head));
    //printf("Value at index 1: %d\n", list_get(head, 1));

    // 5. Test Search
    //int search_val = 20;
    //int index = list_find(head, search_val);
    //if (index != -1) {
    //    printf("Value %d found at index %d\n", search_val, index);
    //} else {
    //  printf("Value %d not found\n", search_val);
    //}
    
    // 6. Test Cleanup (Memory Management)
    printf("\nFreeing memory...\n");
    list_free(&head);

    if (head == NULL) {
        printf("Memory freed successfully. Head is now NULL.\n");
    }

    return 0;
}