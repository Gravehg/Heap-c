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

void insert_heap(Heap *heap, int element){
    if(heap->size == heap->max_size){
        printf("%s\n", "Reached maximum number of elements on this heap");
    }
    heap->heap_elements[heap->size] = element;
    sift_up_heap(heap, heap->size);
    heap->size++;
}

int sift_up_heap(Heap *heap, int i){
    if(heap->type == MINHEAP){
        while(i > 0 && heap->heap_elements[i] < heap->heap_elements[parent_heap(i)]){
            swap_heap_elements(heap, i, parent_heap(i));
            i = parent_heap(i);
        }
    }
    if(heap->type == MAXHEAP){
        while(i > 0 && heap->heap_elements[i] > heap->heap_elements[parent_heap(i)]){
            swap_heap_elements(heap, i, parent_heap(i));
            i = parent_heap(i);
        }
    }
}

void swap_heap_elements(Heap *heap, int pos1, int pos2){
    int temp = heap->heap_elements[pos1];
    heap->heap_elements[pos1] = heap->heap_elements[pos2];
    heap->heap_elements[pos2] = temp;
}

int is_leaf_heap(Heap *heap, int i){
    return left_child_heap(i) >= heap->size;
}

int remove_heap_by_pos(Heap *heap, int pos){
    if(heap->size == 0){
        printf("%s\n", "Can't remove element from empty heap!");
        exit(EXIT_FAILURE);
    }
    if(pos < 0 || pos >= heap->size){
        printf("%s\n", "Can't remove element from invalid position");
        exit(EXIT_FAILURE);
    }
    swap_heap_elements(heap, pos, heap->size - 1);
    heap->size--;
    if(heap->size  > 1)
        sift_down_heap(heap, pos);
    return heap->heap_elements[heap->size];
}

void sift_down_heap(Heap *heap, int i){
    if(heap->type == MINHEAP){
        while(!is_leaf_heap(heap,i) && heap->heap_elements[i] > heap->heap_elements[greater_child_heap(heap,i)]){
            int gChild = greater_child_heap(heap, i);
            swap_heap_elements(heap, i, gChild);
            i = gChild;
        }
    }
    if(heap->type == MAXHEAP){
        while(!is_leaf_heap(heap,i) && heap->heap_elements[i] < heap->heap_elements[greater_child_heap(heap,i)]){
            int gChild = greater_child_heap(heap, i);
            swap_heap_elements(heap, i, gChild);
            i = gChild;
        }
    }
}

int get_size_heap(Heap *heap){
    return heap->size;
}

int is_empty_heap(Heap *heap){
    return heap->size == 0;
}

int remove_root(Heap *heap){
    return remove_heap_by_pos(heap, 0);
}