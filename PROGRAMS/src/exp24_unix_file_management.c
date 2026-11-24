/*
 * Experiment 24: UNIX System Calls for File Management
 * Aim: Design a C program to demonstrate UNIX system calls for file management (creat, open, read, write, close).
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char buffer[100];
    int fd = creat("sample.txt", 0644);
    if (fd == -1) {
        perror("creat");
        exit(1);
    }
    printf("File 'sample.txt' created successfully (fd = %d)\n", fd);
    close(fd);

    fd = open("sample.txt", O_WRONLY | O_APPEND);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    printf("File opened for appending.\n");

    const char *text = "Operating Systems Lab 2026\n";
    write(fd, text, 27);
    printf("Wrote %d bytes to file.\n", 27);
    close(fd);

    fd = open("sample.txt", O_RDONLY);
    int bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    buffer[bytesRead] = '\0';
    printf("Read %d bytes: %s", bytesRead, buffer);
    close(fd);

    printf("File operations completed and file closed.\n");
    return 0;
}
