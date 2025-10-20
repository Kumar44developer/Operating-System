#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
    int fd;
    char buffer[100];

    fd = open("sample.txt", O_CREAT | O_RDWR, 0777);
    write(fd, "Operating Systems Concepts\n", 28);

    lseek(fd, 0, SEEK_SET);
    read(fd, buffer, 28);

    printf("File Content: %s\n", buffer);
    close(fd);
    return 0;
}

