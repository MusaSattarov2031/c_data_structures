#include <stdio.h>
#include <stdlib.h>
#include "vector.h"



//Vector initialization functions, needs to be runned to alocate the memory for an array
void vector_init (vector* V){
    V->size = 0;
    V->capacity = 4;
    V->data = malloc(V->capacity*sizeof(int));
}

//Destructor, frees memory after deletion
void vector_free(vector *v){
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

//Helper function for resizing
void vector_resize(vector *v, int new_capacity){
    v->capacity = new_capacity;
    v->data = realloc(v->data, v->capacity*sizeof(int));
}

//MODIFICATIONS
//Placing a value in the end of a vector
void vector_push (vector* V, int n){
    if (V->size == V->capacity){
        vector_resize(V, V->capacity*2);
    }
    V->data[V->size]=n;
    V->size+=1;
}

//Deleting value from an end of a vector
int vector_pop(vector* V){
    if (V->size>0){
        int val = V->data[V->size-1];
        V->size-=1;
        return val;
    }else{
        printf("Is empty");
        return -1;
    }
}

//insertion at an index of the value
void vector_insert(vector *v, int index, int value){
    if (index < 0 || index > v->size) {
        printf("IndexError\n");
        return;
    }
    if (v->size == v->capacity) {
        vector_resize(v, v->capacity * 2);
    }
    for (int i = v->size; i > index; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[index] = value;
    v->size++;
}

//removing based on index
void vector_remove(vector *v, int index){
    if (index<0 || index>=v->size){
        printf("IndexError");
        return;
    }
    while (index<v->size-1){
        v->data[index]=v->data[index+1];
        index++;
    }
    vector_pop(v);
}


//removing all data, but capacity unchaged
void vector_clear(vector *v){
    v->size = 0;
}

//Setting value by index
void vector_set(vector *v, int index, int value){
    if (index>=0 && index < v->size){
        v->data[index]=value;
    }else{
        printf("Invalid index");
    }
}


//INFORMATIONAL
//Accessing value by index
int vector_get(vector* v, int index){
    if (index>=0 && index < v->size){
        return v->data[index];
    }else{
        printf("Invalid index, returning -1");
        return -1;
    }
}

//Check if contains
int vector_contains(vector *v, int value){
    for( int i =0; i < v->size; i++){
        if (v->data[i]==value){
            return 1;
        }
    }
    return 0;
}
//returns size of an array
int vector_size(vector *v){
    return v->size;
}
//return memory alocated for this array
int vector_capacity(vector *v){
    return v->capacity;
}
//returns 1 if array is empty
int vector_is_empty(vector *v){
    if (v->size){
        return 0;
    }else{
        return 1;
    }
}
//DISPLAY
//Printing a vector as row
void vector_print(vector *V){
    int i;
    for(i=0; i<V->size; i++){
        printf("%d ", V->data[i]);
    }
    printf("\n");
}

//Search value, returns first apereance index, -1 if not there
int vector_find(vector *v, int value){
    for (int i = 0; i<vector_size(v); i++){
        if (value == vector_get(v, i)){
            return i;
        }
    }
    return -1;
}