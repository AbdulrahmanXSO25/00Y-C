#include "fslib.h"
#include <unistd.h> // open, close, read, write,

int my_open(const char* filename, int flags) {
    int fd = open(filename, flags);
    return (fd == -1) ? -1 : fd;
}

int my_close(int fd) {
    return close(fd);
}

size_t my_read(int fd, void* buf, size_t count) {
    return read(fd, buf, count);
}

size_t my_write(int fd, const void* buf, size_t count) {
    return write(fd, buf, count);
}