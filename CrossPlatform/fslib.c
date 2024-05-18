#include "fslib.h"
#if defined(_WIN32) || defined(_WIN64)
#include <io.h> // _open, _close, _read, _write,
#else
#include <unistd.h> // open, close, read, write,
#endif

int my_open(const char* filename, int flags) {
#if defined(_WIN32) || defined(_WIN64)
    int fd = _open(filename, flags);
    return (fd == -1) ? -1 : fd;
#else
    int fd = open(filename, flags);
    return (fd == -1) ? -1 : fd;
#endif
}

int my_close(int fd) {
#if defined(_WIN32) || defined(_WIN64)
    return _close(fd);
#else
    return close(fd);
#endif
}

size_t my_read(int fd, void* buf, size_t count) {
#if defined(_WIN32) || defined(_WIN64)
    return _read(fd, buf, (unsigned int)count);
#else
    return read(fd, buf, count);
#endif
}

size_t my_write(int fd, const void* buf, size_t count) {
#if defined(_WIN32) || defined(_WIN64)
    return _write(fd, buf, (unsigned int)count);
#else
    return write(fd, buf, count);
#endif
}