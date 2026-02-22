#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(const int argc, char *argv[]) {
    printf("File to read: %s\n", argv[1]);

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) return -1;

    printf("File opened correctly :)\n");

    char buffer[64];

    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead == -1) return -1;

    printf("The size of the read bytes is: %zd \n", bytesRead);

    buffer[bytesRead] = '\0';

    printf("The input data was --> %s", buffer);

    printf("\n");

    return 0;
}
