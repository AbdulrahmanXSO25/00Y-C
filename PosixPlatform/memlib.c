#include "memlib.h"
#include <sys/mman.h>
#include <unistd.h>

void* my_malloc(size_t size) {
    void* ptr = NULL;

    ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) {
        return NULL;
    }

    return ptr;
}

void my_free(void* ptr, size_t size) {
    if (ptr == NULL) {
        return;
    }
    munmap(ptr, size);
}