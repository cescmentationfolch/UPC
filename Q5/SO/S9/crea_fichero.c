#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd = creat("./salida.txt", S_IRUSR | S_IWUSR);
    write(fd, "ABCD", 4);
}
