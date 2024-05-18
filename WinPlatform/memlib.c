#include "memlib.h"
#include <windows.h>

void* my_malloc(size_t size) {
    void* ptr = NULL;

    ptr = VirtualAlloc(NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (ptr == NULL) {
        return NULL;
    }
    
    return ptr;
}

void my_free(void* ptr, size_t size) {
    if (ptr == NULL) {
        return;
    }
    
    VirtualFree(ptr, 0, MEM_RELEASE);
}
