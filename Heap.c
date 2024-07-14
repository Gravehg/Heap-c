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


int right_child_heap(int i){
    return 2 * i + 2;
}
int left_child_heap(int i){
    return 2 * i + 1;
}

int parent_heap(int i){
    return (i - 1) / 2;
}

int greater_child_heap(Heap *heap, int i){
    if(i <0 || i>= heap->size){
        printf("%s\n", "Can't get greater child of invalid position inside of heap!");
        exit(EXIT_FAILURE);
    }
    if(heap->type == MINHEAP){
        if(right_child_heap(i) >= heap->size || heap->heap_elements[left_child_heap(i)] < heap->heap_elements[right_child_heap(i)]){
            return left_child_heap(i);
        }
        return right_child_heap(i);
    }
    if(heap->type ==MAXHEAP){
        if(right_child_heap(i) >= heap->size || heap->heap_elements[left_child_heap(i)] > heap->heap_elements[right_child_heap(i)]){
            return left_child_heap(i);
        }
        return right_child_heap(i);
    }
}