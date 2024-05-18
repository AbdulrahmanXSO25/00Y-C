#include "fslib.h"
#include <io.h> // _open, _close, _read, _write,

int my_open(const char* filename, int flags) {
    int fd = _open(filename, flags);
    return (fd == -1) ? -1 : fd;
}

int my_close(int fd) {
    return _close(fd);
}

size_t my_read(int fd, void* buf, size_t count) {
    return _read(fd, buf, (unsigned int)count);
}

size_t my_write(int fd, const void* buf, size_t count) {
    return _write(fd, buf, (unsigned int)count);
}