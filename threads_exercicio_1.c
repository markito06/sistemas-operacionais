#include <pthread.h>
#include <stdio.h>

/* imprime mensagem */
void *printHello(void * arg)
{
	/*Cria e recebe or argumentos de arg */
	char *message = (char *) arg;
	
	/*id da work thread*/
	pthread_t tid = pthread_self();

	printf("[ %s ] --> [ TID = %u ] \n" , message, (unsigned int)tid);

}

int main(int argc, char **argv)
{

///*Recebe primeiro argumento enviado na execução*/
//int MAX_THREADS = argv [1];

/*Declaração da thread*/
pthread_t thread;

/*Mensagem*/
char *mensagem = "Nova thread criada  :";

/*Criação da thread e execução da função*/
pthread_create(&thread, NULL, printHello, (void *) mensagem);

/*Sincroniza threads*/
pthread_join(thread, NULL);

/*Finaliza execução da thread*/
pthread_exit(NULL);

return 0;

}