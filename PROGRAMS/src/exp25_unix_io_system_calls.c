/*
 * Experiment 25: UNIX I/O System Calls (fcntl, open, errno, perror)
 * Aim: Construct a C program to implement the I/O system calls of UNIX (fcntl, open, error handling).
 */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int fd = open("foo.txt", O_RDWR | O_CREAT, 0644);
    printf("File descriptor returned by open(): %d\n", fd);

    if (fd != -1) {
        int flags = fcntl(fd, F_GETFL);
        printf("fcntl() F_GETFL access mode flags: %d (O_RDWR)\n", flags & O_ACCMODE);
        close(fd);
    }

    printf("\nAttempting to open non-existent read-only file:\n");
    int bad_fd = open("/nonexistent_directory/file.dat", O_RDONLY);
    if (bad_fd == -1) {
        printf("Error Number (errno): %d\n", errno);
        perror("Program Error Diagnostics");
    }
    return 0;
}
