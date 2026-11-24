/*
 * Experiment 2: File Copy using UNIX System Calls
 * Aim: Copy content of one file to another using read(), write(), open(), close().
 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char source[100], destination[100], buffer[1024];
    int src_fd, dest_fd, bytes_read, bytes_written;

    printf("Enter source file path: ");
    scanf("%99s", source);
    printf("Enter destination file path: ");
    scanf("%99s", destination);

    src_fd = open(source, O_RDONLY);
    if (src_fd == -1) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    dest_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Error opening/creating destination file");
        close(src_fd);
        exit(EXIT_FAILURE);
    }

    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Write error");
            close(src_fd);
            close(dest_fd);
            exit(EXIT_FAILURE);
        }
    }

    close(src_fd);
    close(dest_fd);
    printf("File copied successfully\n");
    return 0;
}
