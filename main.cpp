#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

/*************************************************
Codigo fonte principal
Autor: Gabriel Jose da Silva dos Santos
Codigo: 834846
*************************************************/

TControle controle;
TMedico medico;
TPlantao plantao;

int main(){
	int opcao;/* armazena a escolha do usuario, responsavel pelo loop dowhile e os casos do switch */
	controle.qtdmedico=-1;
	controle.qtdplantao=-1;
	do{
	opcao = menu();
	
	switch(opcao){
		case 1:
			system("cls");
			medico = getMedico(); /* recebimento dos dados de um novo medico */
			addMedico(&controle, medico); /* cadastro do novo medico na estrutura principal */
			break;
		case 2:
			system("cls");
			plantao = getPlantao(&controle); /* recebimento dos dados de um novo plantao */
			addPlantao(&controle, plantao); /* cadastro do novo plantao na estrutura principal */
			break;
		case 3:
			system("cls");
			int x; /* variavel responsavel pela condicao de parada da funcao recursiva listdata() */
			x=0;
			char data[11]; /* armazena a data para a listagem */
			printf("Informe a data(dia/mes/ano): ");
			scanf("%s", &data);
			printf("\nCRM\t\t  NOME\t\t  DATA\t\t  HR INICIO\t\t  HR FINAL\t\t  ESPECIALIDADE\n");
			listdata(&controle, data, x);
			break;
		case 4:
			system("cls");
			int y; /* variavel responsavel pela condicao de parada da funcao recursiva listdata_especialidade() */
			y=0;
			char data1[11], especialidade[25]; /* armazenam, respectivamente, a data e a especialidade para a listagem */
			printf("Informe a data(dia/mes/ano): ");
			scanf("%s", &data1);
			printf("Informe a especialidade: ");
			scanf("%s", &especialidade);
			printf("\nCRM\t\t  NOME\t\t  DATA\t\t  HR INICIO\t\t  HR FINAL\t\t  ESPECIALIDADE\n");
			listdata_especialidade(&controle, data1, especialidade, y);
			break;
	}
	}while(opcao);
	
	return 0;
}
