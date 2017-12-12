#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char buffer[1024];
    int fd = open("./salida.txt", O_RDWR);
    int x = read(fd, buffer, sizeof(buffer));
    char c = buffer[x - 1];
    buffer[x-1] = 'X';
    lseek(fd, 0, SEEK_SET);
    write(fd, buffer, x);
    write(fd, &c, 1);
}
