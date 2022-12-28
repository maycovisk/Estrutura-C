#include <stdio.h>
#include <stdlib.h>
#define SM_STR_LEN 30
#define SM_MAX_TRA 10  //NUMERO DE TRANSICOES
#define SM_MAX_EST 30  //NUMERO MAXIMO DE ESTADO
#ifdef DEBUG
	#define DPRINTF(fmt, args...) fprintf(stderr,"%s %s " fmt,__FILE__, __FUNCTION__, ##args )
#else
#define DPRINTF(fmt, args...)
#endif
#define MAXDIM 10
#define MINDIM 2

enum
{
	ST_PARADO, //ESTADO
	ST_ANDANDO, //ESTADO
	ST_CORRENDO,  //ESTADO
};


typedef void TFunc1(int);

struct Transition   //A TRANSICAO É UMA FUNCAO QUE FAZ O ESTADO MUDAR DE ESTADO 1 PARA ESTADO 2 SE TIVER DEFINIDA PARA AQUEL ESTADO
{                           //CASO CONTRARIO ELA NAO FAZ NADA
	char nome[SM_STR_LEN];
	int  to_state;
	TFunc1 *OnExecute;
};

typedef struct Transition Transition;

struct State
{
	char nome[SM_STR_LEN];
	TFunc1 *OnEnter;  //ENTRA NO ESTADO
	TFunc1 *OnExit;   //SAI DO ESTADO
	Transition  transitions[SM_MAX_TRA];   //PRA CADA ESTADO TEM UM VETOR DE TRANSIÇÃO
	int  qtd_transitions;
};

typedef struct State State;

struct StateMachine   //ESTRUTURA QUE REPRESENTA A MAQUINA DE ESTADO
{
	State states[SM_MAX_EST];  //VETOR DE ESTADO
	TFunc1 *OnChangeState;
	TFunc1 *OnErrorState;
	int qtd_state;
	int cur_state;
	int old_state;
};

typedef struct StateMachine StateMachine;



void ExecTransition( StateMachine *sm , char *name )   //EXECUTA A FUNCAO PELO NOME
{
	int i, id;                      //PROCURA SE EXISTE ALGUMA TRANSICAO COM ESSE NOME, SE ENCONTRAR VAI MUDAR DE ESTADO
                                    //VAI EXECUTAR O ONEXIT DO ESTADO QUE ESTAVA E VAI EXECUTAR O ONENTER DO ESTADO ATUAL
	for ( i=0; i<sm->states[sm->cur_state].qtd_transitions; i++ )
	if (  ! strcmp(name, sm->states[sm->cur_state].transitions[i].nome ) )
	{
		id = sm->states[sm->cur_state ].transitions[i].to_state;

		if ( sm->states[sm->cur_state ].OnExit )
		{
			sm->states[sm->cur_state ].OnExit(0);
		}

		sm->old_state = sm->cur_state;
		sm->cur_state = id;

		printf("%s ==> %s\n",sm->states[sm->old_state].nome, sm->states[sm->cur_state].nome );

		if ( sm->OnChangeState )
		{
			sm->OnChangeState(id);
		}

		if ( sm->states[sm->cur_state ].OnEnter )
		{
			sm->states[sm->cur_state ].OnEnter(0);
		}

		return;
	}

	if ( sm->OnErrorState )
	{
		sm->OnErrorState(0);
		exit(0);
	}

}

void ParadoOnEnter(int num)
{
	DPRINTF("\n");
}

void ParadoOnExit(int num)
{
	DPRINTF("\n");
}

void AndandoOnEnter(int num)
{
	DPRINTF("\n");
}

void AndandoOnExit(int num)
{
	DPRINTF("\n");
}

void CorrendoOnEnter(int num)
{
	DPRINTF("\n");
}

void CorrendoOnExit(int num)
{
	DPRINTF("\n");
}

void AceleraExecuta(int num)
{
	printf("Acelerando...\n");
}

void DiminuiExecuta(int num)
{
	printf("Diminuindo...\n");
}

void AddState( StateMachine *sm , unsigned int state_id, char *state_str, TFunc1 *OnEnter, TFunc1 *OnExit )
{               //PARA ADICIOR ESTADO

	strncpy(sm->states[state_id].nome,state_str,SM_STR_LEN);
	sm->states[state_id].OnEnter = OnEnter;
	sm->states[state_id].OnExit  = OnExit;
	sm->states[state_id].qtd_transitions=0;
	sm->qtd_state++;

}

void AddTransition( StateMachine *sm, unsigned int state_id, unsigned int to_state, char *tran_str, TFunc1 *OnExecute )
{               //PARA ADICIONAR TRANSICAO
	int idx;

	idx=sm->states[state_id].qtd_transitions;

	strncpy(sm->states[state_id].transitions[idx].nome, tran_str,SM_STR_LEN );
	sm->states[state_id].transitions[idx].to_state=to_state;
	sm->states[state_id].transitions[idx].OnExecute = OnExecute;
	sm->states[state_id].qtd_transitions++;

}

void ConfiguraEstados( StateMachine *sm )
{
            //CONFIGURAR A MAQUINA DE ESTADO ~~ PARA CADA ESTADO ELE ADICIONA UMA TRANSICAO
	AddState(sm,ST_PARADO,"PARADO",ParadoOnEnter,ParadoOnExit);
	AddTransition(sm,ST_PARADO,ST_ANDANDO,"ACELERA",AceleraExecuta);

	AddState(sm,ST_ANDANDO,"ANDANDO",AndandoOnEnter,AndandoOnExit);
	AddTransition(sm,ST_ANDANDO,ST_CORRENDO,"ACELERA",AceleraExecuta);
	AddTransition(sm,ST_ANDANDO,ST_PARADO,"DIMINUI",DiminuiExecuta);

	AddState(sm,ST_CORRENDO,"CORRENDO",CorrendoOnEnter,CorrendoOnExit);
	AddTransition(sm,ST_CORRENDO,ST_ANDANDO,"DIMINUI",DiminuiExecuta);


	sm->cur_state = sm->old_state = 0;
}

int main()
{
	static StateMachine sm; //DEFINE A VARIAVEL ~~ INICIA COM 0

	ConfiguraEstados(&sm);  //PARA COLOCAR OS ESTADOS E TRANSICOES

	ExecTransition(&sm,"ACELERA");
	ExecTransition(&sm,"ACELERA");
	ExecTransition(&sm,"DIMINUI");
	ExecTransition(&sm,"DIMINUI");

	return 0;
}
