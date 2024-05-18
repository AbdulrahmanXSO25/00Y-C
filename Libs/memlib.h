#ifndef MEMLIB_H
#define MEMLIB_H

#include <stddef.h>

// Function to allocate memory
void* my_malloc(size_t size);

// Function to free memory
void my_free(void* ptr, size_t size);

#endif // MEMLIB_H