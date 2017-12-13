#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

#define REGION_SIZE		4096

int *p;
void funcion_alarma(int signal)
{
	char buff[256];
	sprintf(buff,"Violación de segmento, el programa sera finalizado signal SIGSEGV \n");
	write(1, buff, strlen(buff) );
	exit(0);
}
int main(int argc, char *argv[])
{
	char buff[256];					
	signal(SIGSEGV,funcion_alarma);
	sprintf( buff, "Addresses:\n");
	write(1, buff, strlen(buff));	
	sprintf( buff, "\tp: %p\n", &p);
	write(1, buff, strlen(buff));	

	*p = 5;

	sprintf( buff, "\tp Address: %p, p value: %p, *p: %d\n", &p, p, *p);
	write(1, buff, strlen(buff));	

	exit(0);

}
