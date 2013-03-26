// exe3.cpp : main project file.

#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"


typedef struct Aluno{
  int cod_aluno;
	char nome_aluno[40];
}TAluno;

typedef struct Notas{
	int fk_cod_aluno;
	float nota;
}TNota;

typedef struct Pilha{
	TAluno alunos[100];
	int topo;
}TPilha;

typedef struct Fila{
	TNota notas[100];
	int tamanho_fila;
}TFila;

int Pesquisa_na_pilha(TPilha *pilha,int pesquisado){
	for(int i =0;i < pilha->topo +1;i++){
		if(pilha->alunos[i].cod_aluno == pesquisado){
		  return i;
		}
	}
	return -1;
}
void LimpaTela(){
	system("cls");
}
void ExibeListas(TPilha *pilha){
	for(int i=0; i < pilha->topo +1;i++){
		printf("\nAluno: %s cod: %d\n",pilha->alunos[i].nome_aluno,pilha->alunos[i].cod_aluno);
	}
	getch();
}

void ExibeListasNotas(TPilha *pilha,TFila *fila_notas){
	for(int i=0; i < pilha->topo +1;i++){
		printf("\n\nAluno: %s cod: %d",pilha->alunos[i].nome_aluno,pilha->alunos[i].cod_aluno);
		for(int j = 0; j < fila_notas->tamanho_fila;j++ ){
			if(pilha->alunos[i].cod_aluno == fila_notas->notas[j].fk_cod_aluno){
				printf("\nNota: %.2f ",fila_notas->notas[j].nota);
			}
		}
	}
	getch();
}

void CadastraAluno(TPilha *pilha,int *sequencia){
	int continua;
	do{
		*sequencia = *sequencia +1;
		pilha->topo++;
		pilha->alunos[pilha->topo].cod_aluno = *sequencia;
		printf("\nDigite o nome aluno: \n");
		fflush(stdin);
		gets(pilha->alunos[pilha->topo].nome_aluno);
		printf("\nAluno cadastrado com sucesso!\n\n");
		printf("Deseja inserir mais alunos 1-Sim 2-Nao: ");
		scanf("%d",&continua);
	}while(continua != 2);
}

void InsereNotas(TPilha *pilha_alunos,TFila *fila_notas){
	int aux_cod, achou,continua;
	//ExibeListas(pilha_alunos);
	do{
		LimpaTela();
		achou = -1;
		printf("\n");
		printf("\n * Digite o codigo do aluno *\n");
		scanf("%d",&aux_cod);
		achou = Pesquisa_na_pilha(pilha_alunos,aux_cod);
		
		//veruificar sealuno estana pilha
		if (achou != -1){
			do{
				printf("\nDigite a nota para o aluno: %s\n",pilha_alunos->alunos[achou].nome_aluno);
				fila_notas->notas[fila_notas->tamanho_fila].fk_cod_aluno = aux_cod;
				fflush(stdin);
				scanf("%f",&fila_notas->notas[fila_notas->tamanho_fila].nota);
				fila_notas->tamanho_fila++;
				printf("Deseja adicionar mais notas p/este aluno: 1 - Sim  2 - Nao");
				scanf("%d",&continua);
			}while(continua != 2);
		}
		else
			printf("Aluno nao encontrado.");

		printf("Deseja adicionar mais notas p/ outro aluno: 1-Sim  2-Nao");
		scanf("%d",&continua);
	}while(continua != 2);

}



void menu(){
	LimpaTela();
	printf("\n* Escolha uma opcao do menu *\n");
	printf("\n1-	Cadastrar aluno");
	printf("\n2-	Cadastrar nota");
	printf("\n3-	Calcular média de um aluno");
	printf("\n4-	Listar os nomes dos alunos sem nota");
	printf("\n5-	Excluir aluno");
	printf("\n6-	Alterar nota");
	printf("\n7-	Exiba lista:");
	printf("\n8-	Exiba lista com notas:");
	printf("\n0-	Sair");//voltar para 7 antes de entregar
}

int main()
{
	int opcao;
	int sequencia = 0;
	TPilha pilha_alunos;
	TFila fila_notas;
	pilha_alunos.topo = -1;
	fila_notas.tamanho_fila = 0;
	
	do{
		menu();
		scanf("%d",&opcao);
		switch(opcao){
			case 1: CadastraAluno(&pilha_alunos,&sequencia);break;
			case 2: InsereNotas(&pilha_alunos,&fila_notas);break;
			case 7: ExibeListas(&pilha_alunos);break;
			case 8: ExibeListasNotas(&pilha_alunos,&fila_notas);break;
			case 0:break;
		}
	}while(opcao != 0);
}

