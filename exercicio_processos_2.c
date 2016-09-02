#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int processoPai = getpid();
	int count = 0;
	int quantidadeDeFilhos = 4;

	while(getpid() == processoPai && count < quantidadeDeFilhos ){
		count ++;
		pid_t processoFilho = fork();

		if(processoFilho != 0){
				
			printf("O processoPai [ %d ] criou o processoFilho [ %d ] \n", processoPai , processoFilho);	
		}else{
			printf("O processoFilho [ %d ] \n", getpid());	
		}
		

	}



	return 0;
}
