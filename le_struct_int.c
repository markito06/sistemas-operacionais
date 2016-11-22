#include <stdio.h>
#include <string.h>

typedef struct {
	int a;
	int b;
}struct_inteiros;

int main (int argc, char **argv) {
	FILE *inFile;
	FILE *outFile;
	struct_inteiros buffer;


	//abre arquivo tipo binario apenas para leitura (rb)
	inFile = fopen ( "inteiros.bin" , "rb" );
  	if (inFile==NULL) {
  		fputs ("File error",stderr);
  		return (1);
  	}

  	//abre arquivo saida modo escrita, se exstir sobreescreve (w)
  	outFile = fopen ("inteiros-texto.txt", "w");
  	if (outFile==NULL) {
  		fputs ("File error",stderr);
  		return (1);
  	}

  	while(fread(&buffer, sizeof(struct_inteiros), 1, inFile)){
  		//imprime no terminal
  		printf("int a = %d e int b = %d \n" , buffer.a, buffer.b);

  		//imprime no arquivo
  		fprintf(outFile, "int a = %d e int b = %d \n" , buffer.a, buffer.b);
  	}


	fclose (inFile);
	fclose (outFile);
  	 	
	return 0;
}
