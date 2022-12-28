
//Exercicio2
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int cont=1;
void ctrl_c(int sigc)
{
	char decisao;
	printf("Foi executado %d tentativa(s) de encerrar o processo\n",cont);
	cont++;
	if(cont == 6)
	  {
	      alarm(5);
	      printf("Deseja sair (S/N)?\n");
	      //fflush(stdin);
	      scanf("%c",&decisao);
	      if(decisao == 's' || decisao == 'S')
		exit(0);
	      if(decisao == 'n' || decisao == 'N')
	      {
		alarm(0);
		cont = 1;
		getchar();
	      }
	  }
}

void ctrl_z(int sigz)
{
	printf("Foi executado %d vezes o SIGINT\n",cont-1);
	sleep(1);
	exit(0);
}

int main()
{
	int i;
	signal(SIGINT,ctrl_c);
	signal(SIGTSTP,ctrl_z);
	printf("Processo inicializado aperte CTRL+C para encerrar\n");
	for(i=0;;i++)
	{
	  printf("Em execucao... \n");
	  sleep(1);
	}
	return 0;
}
