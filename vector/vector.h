/* * vector.h
 * A dynamic array implementation for integers.
 * Part of the C_Data_Structures repository.
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>

/* --- Structure Definition --- */

typedef struct {
    int *data;      // Pointer to the heap-allocated array
    int size;       // Current number of elements
    int capacity;   // Total allocated space
} vector;

/* --- Lifecycle Management --- */

/**
 * Initializes the vector with a default capacity.
 * Must be called before any other vector operations.
 */
void vector_init(vector* V);

/**
 * Releases all heap memory used by the vector.
 * Set pointers to NULL to prevent dangling pointers.
 */
void vector_free(vector *v);

/**
 * Internal helper to resize the underlying array.
 */
void vector_resize(vector *v, int new_capacity);

/* --- Modifications --- */

/**
 * Adds a value to the end of the vector.
 * Automatically resizes if capacity is reached.
 */
void vector_push(vector* V, int n);

/**
 * Removes and returns the last value from the vector.
 * Returns -1 if the vector is empty.
 */
int vector_pop(vector* V);

/**
 * Inserts a value at a specific index, shifting subsequent elements right.
 */
void vector_insert(vector *v, int index, int value);

/**
 * Removes the element at a specific index, shifting subsequent elements left.
 */
void vector_remove(vector *v, int index);

/**
 * Resets the size to 0 without freeing the allocated capacity.
 */
void vector_clear(vector *v);

/**
 * Overwrites the value at a specific index.
 */
void vector_set(vector *v, int index, int value);

/* --- Informational & Search --- */

/**
 * Returns the value at a specific index.
 */
int vector_get(vector* v, int index);

/**
 * Returns the index of the first occurrence of 'value', or -1 if not found.
 */
int vector_find(vector *v, int value);

/**
 * Returns 1 (true) if the value is in the vector, 0 (false) otherwise.
 */
int vector_contains(vector *v, int value);

/**
 * Returns the number of elements currently stored.
 */
int vector_size(vector *v);

/**
 * Returns the total capacity currently allocated.
 */
int vector_capacity(vector *v);

/**
 * Returns 1 if empty, 0 otherwise.
 */
int vector_is_empty(vector *v);

/* --- Display --- */

/**
 * Prints the vector elements in a single line.
 */
void vector_print(vector *V);

#endif /* VECTOR_H */