#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *data;
    int size;
    int capacity;
}vector;

void vector_init (vector* V){
    V->size = 0;
    V->capacity = 4;
    V->data = malloc(V->capacity*sizeof(int));
}

void vector_push (vector* V, int n){
    if (V->size == V->capacity){
        V->capacity *= 2;
        V->data = realloc(V->data, V->capacity*sizeof(int));
    }
    V->data[V->size]=n;
    V->size+=1;
}

void vector_pop(vector* V){
    if (V->size>0){
        V->size-=1;
    }else{
        printf("Is empty");
    }
}

void vector_print(vector *V){
    int i;
    for(i=0; i<V->size; i++){
        printf("%d ", V->data[i]);
    }
    printf("\n");
}

int vector_get(vector* v, int index){
    if (index>=0 && index < v->size){
        return v->data[index];
    }else{
        printf("Invalid index, returning -1");
        return -1;
    }
}

void vector_set(vector *v, int index, int value){
    if (index>=0 && index < v->size){
        v->data[index]=value;
    }else{
        printf("Invalid index");
    }
}

int vector_contains(vector *v, int value){
    for( int i =0; i < v->size; i++){
        if (v->data[i]==value){
            return 1;
        }
    }
    return 0;
}
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