#include <unistd.h>
#include <string.h>
#include <stdio.h>


main(){
int numero;
char buffer[64];

read(0, &numero, sizeof(n));
write(1, &numero, sizeof(int));
sprintf(buffer,"%d",numero);
write(1, buffer, strlen(buffer));



}
