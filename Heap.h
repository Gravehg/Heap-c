#ifndef HEAP_H
#define HEAP_H
#include <stdlib.h>
#include <stdio.h>

typedef enum
{
    MINHEAP,
    MAXHEAP,
} TYPE_HEAP;

typedef struct Heap
{
    TYPE_HEAP type;
    int *heap_elements;
    int max_size;
    int size;
} Heap;

Heap *get_heap(TYPE_HEAP selected_type, int max_size);
int get_max(Heap *heap);
int get_min(Heap *heap);
int right_child_heap(int i);
int left_child_heap(int i);
int parent_heap(int i);
int greater_child_heap(Heap *heap, int i);
void insert_heap(Heap *heap, int element);
int remove_heap_by_pos(Heap *heap, int pos);
int is_leaf_heap(Heap *heap, int i);
int get_size_heap(Heap *heap);
int is_empty_heap(Heap *heap);
void sift_down_heap(Heap *heap, int i);
int sift_up_heap(Heap *heap, int i);
int remove_root(Heap *heap);
void swap_heap_elements(Heap *heap, int pos1, int pos2);

#endif