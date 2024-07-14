#include "Heap.h"


Heap *get_heap(TYPE_HEAP selected_type, int max_size){
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    if(heap == NULL){
        printf("%s\n", "There was an error allocating memory for the heap structure!");
        return NULL;
    }
    heap->heap_elements = (int *)malloc(sizeof(int) * max_size);
    if(heap->heap_elements == NULL){
        printf("%s\n", "There was an error allocating memory for the elements of the heap structure");
        free(heap);
        return NULL;
    }
    heap->max_size = max_size;
    heap->size = 0;
    heap->type = selected_type;
    return heap;
}

int get_max(Heap *heap){
    if(heap->size == 0){
        printf("%s\n", "Can't get max element from empty heap structure!");
        exit(EXIT_FAILURE);
    }
    if(heap->type == MINHEAP){
        printf("%s\n", "Can't get max element on min-heap!");
        exit(EXIT_FAILURE);
    }
    return heap->heap_elements[0];
}

int get_min(Heap *heap){
    if(heap->size == 0){
        printf("%s\n", "Can't get min element from empty heap structure");
        exit(EXIT_FAILURE);
    }
    if(heap->type == MAXHEAP){
        printf("%s\n", "Can't get min element on max-heap!");
        exit(EXIT_FAILURE);
    }
    return heap->heap_elements[0];
}
