

//Nome: Gabriel Jose da Silva dos Santos Código: 834846


#include <stdio.h>
#include <string.h>

typedef char Tplaca[8];

typedef struct {
	Tplaca placa[6];
	int topo;
}Tpilha;

Tpilha pilhas[6], pilha_aux;

void inicializa(){
	int x, y;
	for(x=0;x<=5;x++){
		pilhas[x].topo=-1;
		for(y=0;y<=5;y++){
		strcpy(pilhas[x].placa[y], "       ");
		strcpy(pilha_aux.placa[x], "       ");
		}
	}
	pilha_aux.topo=-1;
}

int pilha_cheia(int fil){
	return pilhas[fil-1].topo==5;
}

int pilha_vazia(int fil){
	return pilhas[fil-1].topo==-1;
}

int localizar(char placa[8]){
	int x, y;
	for(x=0;x<=5;x++){
		for(y=0;y<=5;y++){
			if(strcmp(placa, pilhas[x].placa[y])==0){
				printf("\nLocalizado em: Fileira %d e na posicao %d\n", x+1, y+1);
				return 1;
			}else{
				return 0;
			}
		}
	}
}

void push(){
	int fil, registro;
	char placanova[8];
	printf("Informe a fileira em que deseja estacionar o veiculo: ");
	scanf("%d", &fil);
	
	if(pilha_cheia(fil)){
		printf("\nA fileira selecionada nao possui vagas livres\n");
	}else{
		printf("Informe a placa do veiculo (exemplo: ABC1234): ");
		scanf("%s", &placanova);
		if(!localizar(placanova)){
			pilhas[fil-1].topo+=1;
			registro=pilhas[fil-1].topo;
			strcpy(pilhas[fil-1].placa[registro], placanova);
			
		}else{
			printf("\nO carro informado ja se encontra estacionado");
		}
	}
		
}

void pop(){
	int pi, pl, fil, escol, registro1, registro_aux;

	printf("Informe a fileira em que deseja retirar o veiculo: ");
	scanf("%d", &fil);
	if(pilha_vazia(fil)){
		printf("\nNao existem veiculos na pilha selecionada");
	}else{
			printf("\nO que deseja fazer com o ultimo veiculo da fila: \n[1] Retirar para recolocar posteriormente \n[0] Levar para o patio principal\n");
			scanf("%d", &escol);
		while(escol==1){
			
			pilha_aux.topo+=1;
			
			strcpy(pilha_aux.placa[pilha_aux.topo], pilhas[fil-1].placa[pilhas[fil-1].topo]);
			strcpy(pilhas[fil-1].placa[pilhas[fil-1].topo], "       ");
			pilhas[fil-1].topo-=1;
			
			
			printf("\n- - - - - - - - - - - - - - ESTACIONAMENTO DA MECANICA - - - - - - - - - - - - - - \n");
			printf("\n          1          2          3          4          5          6         ENTRADA");
			printf("\n     ------------------------------------------------------------------\n");
			for(pi=6;pi>=1;pi--){
				printf("%d    ", pi);
		 		for(pl=0;pl<=5;pl++){
				printf("| %s |", pilhas[pi-1].placa[pl]);
				}
				printf("\n     ------------------------------------------------------------------\n");
			}
			
			printf("\nPilha \nAuxiliar:");
			for(pl=0;pl<=5;pl++){
				printf("| %s |", pilha_aux.placa[pl]);
			}
			printf("\n         ------------------------------------------------------------------\n");
			
			printf("\nO que deseja fazer com o ultimo veiculo da fila: \n[1] Retirar para recolocar posteriormente \n[0] Levar para o patio principal\n");
			scanf("%d", &escol);
		};
		
		strcpy(pilhas[fil-1].placa[pilhas[fil-1].topo], "       ");
		pilhas[fil-1].topo--;
		
		for(pl=pilha_aux.topo;pl>=0;pl--){
			pilhas[fil-1].topo++;
			strcpy(pilhas[fil-1].placa[pilhas[fil-1].topo], pilha_aux.placa[pilha_aux.topo]);
			strcpy(pilha_aux.placa[pilha_aux.topo], "       ");
			pilha_aux.topo--;
		}
		
		}
	}
	
void procura(){
	int x, y,localiza;
	char placaprocura[8];
	printf("\nInforme a placa do veiculo que deseja buscar: ");
	scanf("%s", &placaprocura);
	for(x=0;x<=5;x++){
		for(y=0;y<=5;y++){
			if(strcmp(placaprocura, pilhas[x].placa[y])==0){
				printf("\nLocalizado em: Fileira %d e na posicao %d\n", x+1, y+1);
				localiza=1;
			}
		}
	}
	if(!localiza){
		printf("\nO veiculo informado nao se encontra no estacionamento\n");
	}
}

int vagas(){
	int x, y, vg=0;
	for(x=0;x<=5;x++){
		for(y=0;y<=5;y++){
			if(strcmp(pilhas[x].placa[y], "       ")==0){
			vg+=1;
			}
		}
	}
	return vg;
}

int main(){
	
	int opcao, pi, pl;
	inicializa();
	
	do{
		printf("\n- - - - - - - - - - - - - - ESTACIONAMENTO DA MECANICA - - - - - - - - - - - - - - \n");
		printf("\n          1          2          3          4          5          6         ENTRADA");
		printf("\n     ------------------------------------------------------------------\n");
		for(pi=6;pi>=1;pi--){
			printf("%d    ", pi);
	 		for(pl=0;pl<=5;pl++){
			printf("| %s |", pilhas[pi-1].placa[pl]);
			}
			printf("\n     ------------------------------------------------------------------\n");
		}
		
		printf("\nPilha \nAuxiliar:");
		for(pl=0;pl<=5;pl++){
			printf("| %s |", pilha_aux.placa[pl]);
		}
		printf("\n         ------------------------------------------------------------------\n");
		printf("Vagas Totais: 36 Vagas disponiveis: %d", vagas());
		printf("\n\n[1] Estacionar veiculo");
		printf("\n[2] Retirar veiculo");
		printf("\n[3] Localizar veiculo");
		printf("\n[0] Sair");
		printf("\nEscolha sua opcao: ");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				procura();
				break;
	 		default:
	 			printf("\nO sistema foi encerrado");
	 			break;
		}
	}while(opcao);
	
	
	return 0;
}

		

