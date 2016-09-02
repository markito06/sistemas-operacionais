#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


int contador_global = 0;

/* imprime mensagem */
void *printHello(void * arg)
{
	/*Cria e recebe or argumentos de arg */
	char *message = (char *) arg;
	
	/*id da work thread*/
	pthread_t tid = pthread_self();

	int i;
	for(i =0 ; i < 100 ; i++){
		contador_global ++;
	}


	/*Finaliza execução da thread*/
	pthread_exit(NULL);

}

int main(int argc, char **argv)
{

/*Recebe primeiro argumento enviado na execução*/
int MAX_THREADS = atoi(argv [1]);

/*Declaração da thread*/
pthread_t threads [MAX_THREADS] ;

/*Mensagem*/
char *mensagem = "Nova thread criada  :";

int i = 0;
/*Laço para criação de multiplas threads*/
for(i=0 ; i < MAX_THREADS; i++){
	pthread_t thread;
		
		/*Criação da thread e execução da função*/
		pthread_create(&thread, NULL, printHello, (void *) mensagem);	

	threads [i] = thread;
}

int j = 0;
for(j = 0 ; j < MAX_THREADS; j++){
	/*Sincroniza threads*/
	pthread_join(threads[j], NULL);	
}

printf("contador_global = %d\n", contador_global);

return 0;

}