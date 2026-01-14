#include <stdio.h>
#include <stdlib.h>



//Declaring a structure vector
typedef struct{
    int *data;
    int size;
    int capacity;
}vector;

//Vector initialization functions, needs to be runned to alocate the memory for an array
void vector_init (vector* V){
    V->size = 0;
    V->capacity = 4;
    V->data = malloc(V->capacity*sizeof(int));
}

//Placing a value in the end of a vector
void vector_push (vector* V, int n){
    if (V->size == V->capacity){
        V->capacity *= 2;
        V->data = realloc(V->data, V->capacity*sizeof(int));
    }
    V->data[V->size]=n;
    V->size+=1;
}

//Deleting value from an end of a vector
void vector_pop(vector* V){
    if (V->size>0){
        V->size-=1;
    }else{
        printf("Is empty");
    }
}


//Printing a vector as row
void vector_print(vector *V){
    int i;
    for(i=0; i<V->size; i++){
        printf("%d ", V->data[i]);
    }
    printf("\n");
}

//Accessing value by index
int vector_get(vector* v, int index){
    if (index>=0 && index < v->size){
        return v->data[index];
    }else{
        printf("Invalid index, returning -1");
        return -1;
    }
}

//Setting value by index
void vector_set(vector *v, int index, int value){
    if (index>=0 && index < v->size){
        v->data[index]=value;
    }else{
        printf("Invalid index");
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
//To complete
void vector_insert(vector *v, int index, int value){
    return;
}
void vector_delete_at_index (vector *v, int index){
    return;
}
//Destructor, frees memory after deletion
void vector_free(vector *v){
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

int main() {
    vector list;
    vector_init(&list);

    // 1. Fill it up
    for(int i = 0; i < 10; i++) vector_push(&list, i * 10);
    
    // 2. Test functions
    vector_print(&list);
    printf("Contains 50? %s\n", vector_contains(&list, 50) ? "Yes" : "No");
    
    // 3. Cleanup (Crucial!)
    vector_free(&list); 
    
    return 0;
}