#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*************************************************
Biblioteca
Autor: Gabriel Jose da Silva dos Santos
Codigo: 834846
*************************************************/

typedef struct{
	char crm[9];
	char nome[30];
	char especialidade[25];
}TMedico;

typedef struct{
	char data[11];
	char hinicio[6];
	char hfinal[6];
	TMedico medico;
}TPlantao;

typedef struct{
	int qtdmedico;
	int qtdplantao;
	TMedico cadmedico[100];
	TPlantao cadplantao[100];
}TControle;	

int menu(){ /* funcao menu, coleta a escolha do usuario */
	int escolha;
	printf("\n--------- MENU ---------\n");
	printf("[1] Incluir medico\n");
	printf("[2] Incluir plantao\n");
	printf("[3] Listar plantao por data\n");
	printf("[4] Listar plantao por especialidade e data\n");
	printf("[0] Sair\n");
	printf("Escolha sua opcao: ");
	scanf("%d", &escolha);
	
	return escolha;
}

TMedico getMedico(){ /* funcao que coleta dados de um novo medico */
	
	TMedico mediconovo;
	
	printf("Informe o CRM: ");
	scanf("%s", &mediconovo.crm);
	printf("Informe o primeiro nome: ");
	scanf("%s", &mediconovo.nome);
	printf("Informe a especialidade: ");
	scanf("%s", &mediconovo.especialidade);
	
	return mediconovo;
}

void addMedico(TControle *controle, TMedico medico){ /* funcao que cadastra na estrutura principal o medico informado na getMedico()*/
	
	controle->qtdmedico += 1;
	controle->cadmedico[controle->qtdmedico] = medico;
	
}

TPlantao getPlantao(TControle *controle){ /* funcao que coleta os dados de um novo plantao */
	
	int x, medico_escolhido;
	TPlantao plantaonovo;
	
	printf("Informe a data (dia/mes/ano):  ");
	scanf("%s", &plantaonovo.data);
	printf("Informe a hora de inicio do plantao (Ex 00:00): ");
	scanf("%s", &plantaonovo.hinicio);
	printf("Informe a hora de termino do plantao (Ex 00:00): ");
	scanf("%s", &plantaonovo.hfinal);
	
	if(controle->qtdmedico > -1){
		
		printf("\nLista de medicos cadastrados\n");
		
		for(x=0;x<=controle->qtdmedico;x++){
			printf("-- [ %i ] %s\n", x, (*controle).cadmedico[x].nome);
		}
		
		printf("\n Da lista acima, escolha o numero do medico a ser alocado neste plantao:  ");
		scanf("%i", &medico_escolhido);
		
		plantaonovo.medico = (*controle).cadmedico[medico_escolhido];
		
	}else{
		printf("\nNao existem medicos cadastrados, realize o cadastro de medicos primeiro para aloca-los em plantoes\n");
	}
	
	return plantaonovo;
}

void addPlantao(TControle *controle, TPlantao plantao){ /* funcao que cadastra na estrutura principal o plantao informado na getPlantao()*/
	
	controle->qtdplantao += 1;
	controle->cadplantao[controle->qtdplantao] = plantao;
	printf("%i", controle->qtdplantao);
	
}

int listdata(TControle *controle, char data[11], int x){ /* funcao de listagem dos plantoes por data*/
	
	if( x <= (*controle).qtdplantao ){
		
		if((strcmp((*controle).cadplantao[x].data, data) == 0)){
			
			printf("\n%s\t  %s\t %s\t   %s\t\t  %s\t\t\t %s\n ", (*controle).cadplantao[x].medico.crm, (*controle).cadplantao[x].medico.nome, (*controle).cadplantao[x].data, (*controle).cadplantao[x].hinicio, (*controle).cadplantao[x].hfinal, (*controle).cadplantao[x].medico.especialidade);
		}
		
		x++;
		return listdata(&(*controle), data, x);
		
	}else{
		return 0;
	}
}

int listdata_especialidade(TControle *controle, char data1[11], char especialidade[25], int y){ /* funcao de listagem dos plantoes por data e especialidade*/
	
	if( y <= (*controle).qtdplantao ){
		
		if((strcmp((*controle).cadplantao[y].data, data1) == 0) && (strcmp((*controle).cadplantao[y].medico.especialidade, especialidade) == 0 )){
			
			printf("\n%s\t  %s\t %s\t   %s\t\t  %s\t\t\t %s\n ", (*controle).cadplantao[y].medico.crm, (*controle).cadplantao[y].medico.nome, (*controle).cadplantao[y].data, (*controle).cadplantao[y].hinicio, (*controle).cadplantao[y].hfinal, (*controle).cadplantao[y].medico.especialidade);
		}
		
		y++;
		return listdata_especialidade(&(*controle), data1, especialidade, y);
		
	}else{
		return 0;
	}
}
