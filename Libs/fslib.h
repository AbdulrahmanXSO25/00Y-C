#ifndef FSLIB_H
#define FSLIB_H
#include <fcntl.h> 
#include <stddef.h>

// Function to open a file
int my_open(const char* filename, int flags);

// Function to close a file
int my_close(int fd);

// Function to read from a file
size_t my_read(int fd, void* buf, size_t count);

// Function to write to a file
size_t my_write(int fd, const void* buf, size_t count);

#endif // FSIB_H