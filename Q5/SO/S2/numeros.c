#include <stdio.h>
#include <string.h>

const int MAX_SIZE = 8;

int esNumero(char *str) {
  if(strlen(str) > MAX_SIZE) return 0;
  for(int i = 0; i < (int) strlen(str); ++i) {
    if(str[i] < '0' || str[i] > '9') return 0;
  }
  return 1;
}

int main(int argc, char *argv[]) {
  char buf[80];
  for (int i=0;i<argc;i++){
		if (esNumero(argv[i])){
			sprintf(buf,"%s es un numero de menos de 8 cifras\n",argv[i]);
		}else{
			sprintf(buf,"%s no es un numero de menos de 8 cifras\n",argv[i]);
		}
		write(1,buf,strlen(buf));
	}
}
