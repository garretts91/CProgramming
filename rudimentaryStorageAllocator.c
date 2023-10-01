#include <stdio.h>
#include <stdlib.h>

// this created a SEGFAULT!!! TODO: Fix <----

#define MAX_MEMORY 1024 // Maximum memory size

typedef struct Block {
    size_t size;          // Size of the memory block
    struct Block *next;   // Pointer to the next block
} Block;

// Initial free memory block
Block *free_block = NULL;

// Function to initialize the memory allocator
void initialize_allocator() {
    if (free_block == NULL) {
        free_block = (Block *)malloc(MAX_MEMORY);
        free_block->size = MAX_MEMORY;
        free_block->next = NULL;
    }
}

// Function to allocate memory
void *allocate(size_t size) {
    if (size <= 0) {
        return NULL;
    }

    Block *current = free_block;
    Block *prev = NULL;

    while (current) {
        if (current->size >= size) {
            if (current->size > size) {
                Block *new_block = (Block *)((char *)current + size);
                new_block->size = current->size - size;
                new_block->next = current->next;
                if (prev) {
                    prev->next = new_block;
                } else {
                    free_block = new_block;
                }
            } else {
                if (prev) {
                    prev->next = current->next;
                } else {
                    free_block = current->next;
                }
            }

            return (void *)current;
        }
        prev = current;
        current = current->next;
    }

    return NULL; // Memory allocation failed
}

// Function to deallocate memory
void deallocate(void *ptr) {
    if (ptr) {
        Block *block = (Block *)ptr;
        block->next = free_block;
        free_block = block;
    }
}

// Function to print free memory blocks
void print_free_memory() {
    Block *current = free_block;
    while (current) {
        printf("Free block: size=%lu\n", current->size);
        current = current->next;
    }
}

int main() {
    initialize_allocator();

    int *int_ptr = (int *)allocate(sizeof(int));
    if (int_ptr) {
        *int_ptr = 42;
        printf("Allocated integer: %d\n", *int_ptr);
        deallocate(int_ptr);
    } else {
        printf("Memory allocation failed\n");
    }

    print_free_memory();

    return 0;
}
