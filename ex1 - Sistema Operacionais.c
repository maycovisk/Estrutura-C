//Exercicio1
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int cont = 1;
void ctrl_z(int sig)
{
        printf("Foi executado %d tentativas de suspender o processo\n",cont);
        cont++;
        if(cont==5)
          exit(0);
}

void ctrl_c(int sigc)
{
	printf("Voce aperto ctrl + c\n");
}

int main()
{
        int i;
        signal(SIGTSTP,ctrl_z);
	signal(SIGINT,ctrl_c);
        printf("Processo inicializado, aperte CTRL+Z para suspender\n");
        for(i=0;;i++)
        {
          printf("Em execucao...\n");
          sleep(1);
	}
	return 0;
}
