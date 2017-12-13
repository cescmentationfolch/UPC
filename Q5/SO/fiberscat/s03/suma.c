#include "mis_funciones.h"


//gcc -c mis_funciones.c
//gcc -o suma suma.c mis_funciones.o

int main(int argc,char *argv[]){
		
	char cadena[40];
	char buff[90];
	int i, r=0; 
	char c='0';

	for (i = 1; i < argc && argv[i]!='\0'; i++){
		if((esNumero(argv[i]))==1){
			r+=mi_atoi(argv[i]); 
			sprintf(buff, "cadena correcta, la suma es %d \n", r);	
		}else sprintf(buff, "cadena inapropiada \n"); 	
	}
	write(1, buff, strlen(buff)); 
	return 0;
}











