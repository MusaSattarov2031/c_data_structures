#include <stdio.h>
#include "vector.h"

int main() {
    vector my_list;
    
    // 1. Test Initialization
    vector_init(&my_list);
    printf("--- Initialized Vector ---\n");
    fflush(stdout);
    printf("Size: %d, Capacity: %d\n\n", vector_size(&my_list), vector_capacity(&my_list));

    // 2. Test Pushing (Triggering a resize)
    printf("--- Testing Push (Triggering Resize) ---\n");
    for (int i = 1; i <= 5; i++) {
        vector_push(&my_list, i * 10);
    }
    vector_print(&my_list);
    printf("New Capacity: %d\n\n", vector_capacity(&my_list));

    // 3. Test Insert and Remove
    printf("--- Testing Insert at index 2 (Value 99) ---\n");
    vector_insert(&my_list, 2, 99);
    vector_print(&my_list);

    printf("--- Testing Remove at index 0 ---\n");
    vector_remove(&my_list, 0);
    vector_print(&my_list);
    printf("\n");

    // 4. Test Search Functions
    printf("--- Testing Search ---\n");
    int find_99 = vector_find(&my_list, 99);
    printf("Index of 99: %d\n", find_99);
    printf("Contains 50? %s\n\n", vector_contains(&my_list, 50) ? "Yes" : "No");

    // 5. Test Pop and Clear
    printf("--- Testing Pop ---\n");
    int popped = vector_pop(&my_list);
    printf("Popped value: %d, New Size: %d\n", popped, vector_size(&my_list));

    printf("--- Testing Clear ---\n");
    vector_clear(&my_list);
    printf("Size after clear: %d, Capacity still: %d\n\n", vector_size(&my_list), vector_capacity(&my_list));

    // 6. Test Cleanup
    vector_free(&my_list);
    printf("Vector memory freed successfully.\n");

    return 0;
}