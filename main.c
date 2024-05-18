#include <stdio.h> // prtinf, fprintf, scanf, stderr
#include <string.h> // strcpy
#include "fslib.h"
#include "memlib.h"

// Constants for buffer size and maximum name length
#define IO_MAX_BUFFER 1024
#define NAME_MAX 20

int main() {

    // Allocate memory for storing the user's name
    char* name = (char*)my_malloc(NAME_MAX * sizeof(char));
    if (name == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter Your name: ");
    scanf("%s", name);

    // Open the source file for reading
    int fd_read = my_open("E:\\Projects\\00Y-C\\readTo.txt", O_RDONLY);
    if (fd_read < 0) {
        fprintf(stderr, "Failed to open readTo.txt for reading\n");
        my_free(name, NAME_MAX * sizeof(char));
        return 1;
    }

    // Open the destination file for writing, creating it if it doesn't exist
    int fd_write = my_open("E:\\Projects\\00Y-C\\writeTo.txt", O_WRONLY | O_CREAT);
    if (fd_write < 0) {
        fprintf(stderr, "Failed to open writeTo.txt for writing\n");
        my_close(fd_read);
        my_free(name, NAME_MAX * sizeof(char));
        return 1;
    }

    // Buffer to store the data read from the source file
    char buffer[IO_MAX_BUFFER];

    // Read data from the source file
    size_t bytes_read = my_read(fd_read, buffer, sizeof(buffer) - NAME_MAX - 2);
    if (bytes_read < 0) {
        fprintf(stderr, "Failed to read from readTo.txt\n");
    } else {
        // Log data we read
        printf("Data has been read from file: %.*s\n", (int)bytes_read, buffer);

        buffer[bytes_read] = ' '; // Append a space after the read data
        int nameLength = strlen(name); // Get the length of the user's name

        // Append the user's name to the buffer
        for(int i = 0; i < nameLength; i++) {
            buffer[++bytes_read] = name[i];
        }

        buffer[++bytes_read] = '\0'; // Null-terminate the string

        // Free the memory allocated for the name
        my_free(name, NAME_MAX * sizeof(char));
        
        // Write the new version of data to the destination file
        size_t bytes_written = my_write(fd_write, buffer, bytes_read);
        if (bytes_written < 0) {
            fprintf(stderr, "Failed to write to writeTo.txt\n");
        } else {
            printf("Successfull write operation!\n");
        }
    }

    // Cleaning up resources
    my_close(fd_read);
    my_close(fd_write);

    return 0;
}












// #ifdef _WIN32
//     // Windows file paths
//     #define READ_FILE_PATH "E:\\Projects\\00Y-C\\readTo.txt"
//     #define WRITE_FILE_PATH "E:\\Projects\\00Y-C\\writeTo.txt"
// #else
//     // POSIX file paths
//     #define READ_FILE_PATH "/home/abdulrahman/Desktop/00Y-C/readTo.txt"
//     #define WRITE_FILE_PATH "/home/abdulrahman/Desktop/00Y-C/writeTo.txt"
// #endif