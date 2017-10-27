#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 26


int main(int argc,char *argv[]){
		

	char cadena[MAX_SIZE];
	char buffer[90];
	int i; 
	
	sprintf(buffer, "Esto es una prueba de buffer \n", strlen(buffer));
	write(1, buffer, strlen(buffer));	
	
	for (i = 0; i < MAX_SIZE; i++){
		cadena[i]='a'+i;	
		sprintf(cadena, "En la posicion %d hay %c\n", i, cadena[i]);
		write(1, cadena, strlen(cadena));
	}

	return 0;
}

