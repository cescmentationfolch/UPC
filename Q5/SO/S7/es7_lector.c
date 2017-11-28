#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
    int num;
    int i = 0;
    read(0, &num, sizeof(int));
    char buf[10];
    sprintf(buf, "%d\n", num);
    write(1, buf, strlen(buf));
}
