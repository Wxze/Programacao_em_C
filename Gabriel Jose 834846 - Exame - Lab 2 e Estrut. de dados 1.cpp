/* 
	Aluno: Gabriel Jose da Silva dos Santos   RA: 834846
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_ANIMAIS = 20; //numero maximo de animais que podem ser cadastrados
const int MAX_PROCEDIMENTOS = 10; //numero maximo de procedimentos cadastrados por cada animal

typedef struct{
	int codigo;
	char desc[40];
	char data[10];
	float valor;
}Tprocedimento; //struct que armazena dados dos procedimentos

typedef struct{
	int registro;
	char raca[20];
	char cor[15];
	int idade;
	char apelido[15];
	char dono[25];
	int qtd_procedimentos = -1;
	Tprocedimento procedimentos[MAX_PROCEDIMENTOS];
}Tanimal; // struct que armazena dados dos animais

typedef struct{
	int qtd_animais = -1;
	Tanimal animais[MAX_ANIMAIS];
}Tcontrole; //struct de controle, contem numero de animais cadastrados

Tanimal get_animal(){ //recebe os dados do animal e os retorna para o main
	
	Tanimal aux; //variavel temporaria que armazena dados do animal
		
	printf("\nNumero de registro: ");
	scanf("%i", &aux.registro);
	fflush(stdin);
	printf("Raca: ");
	scanf("%s", aux.raca);
	fflush(stdin);
	printf("Cor: ");
	scanf("%s", &aux.cor);
	fflush(stdin);
	printf("Idade (em anos - somente numeros inteiros): ");
	scanf("%i", &aux.idade);
	fflush(stdin);
	printf("Apelido: ");
	scanf("%s", &aux.apelido);
	fflush(stdin);
	printf("Nome do dono: ");
	scanf("%s", aux.dono);
	fflush(stdin);
		
	return aux;
	}

void add_animal(Tcontrole *controle, Tanimal animal){ //adiciona os dados de get_animal no vetor principal
	
	controle->qtd_animais += 1;
	controle->animais[controle->qtd_animais] = animal;
	
}

void bubble_sort(Tcontrole *controle){ //metodo de ordenacao bubble sort
	int i, j; //variaveis de controle dos lacos de repeticao
	Tanimal aux; //variavel que auxilia na troca dos valores durante a ordenacao
	
	for(i = 0; i < controle->qtd_animais; i++){
		
		for(j = 0; j < controle->qtd_animais; j++){
			
			if((*controle).animais[j].registro > (*controle).animais[j+1].registro){
				aux = (*controle).animais[j];
				(*controle).animais[j] = (*controle).animais[j+1];
				(*controle).animais[j+1] = aux;
			}
		}
	}
}

int busca_binaria(Tcontrole *controle, int codigo){ //metodo de busca binaria
	int inf = 0; //inferior, utilizada na busca binaria
	int sup = (*controle).qtd_animais - 1; //superior, utilizada na busca binaria
	int meio;
	
	while(inf <= sup){
		
		meio = (inf + sup) / 2;
		
		if(codigo == (*controle).animais[meio].registro){
			
			return meio;
			
		}else if(codigo < (*controle).animais[meio].registro){
			
			sup = meio - 1;
			
		}else{
			inf = meio + 1 ;
		}
	}
}

Tprocedimento get_procedimento(){ //recebe os dados do procedimento e os retorna para o main
	Tprocedimento aux;//variavel temporaria que armazena dados do procedimento
	
	printf("\nCodigo do procedimento: ");
	scanf("%i", &aux.codigo);
	fflush(stdin);
	printf("Descricao: ");
	scanf("%s", &aux.desc);
	fflush(stdin);
	printf("Data (dia/mes/ano): ");
	scanf("%s", &aux.data);
	fflush(stdin);
	printf("Valor: ");
	scanf("%f", &aux.valor);
	fflush(stdin);
	
	
	return aux;	
}

void add_procedimento(Tcontrole *controle, Tprocedimento procedimento, int codigo){ /*adiciona os dados de get_procedimento no vetor principal*/
	
	int indice = busca_binaria(controle, codigo);
	
	(*controle).animais[indice].qtd_procedimentos += 1;
	
	int aux = (*controle).animais[indice].qtd_procedimentos;
	(*controle).animais[indice].procedimentos[aux] = procedimento;
	
}

void listar_animais_procedimentos(Tcontrole *controle){ //listagem dos animais e seus procedimentos
	int x, y;//variaveis de controle dos lacos de repeticao
	
	printf("\n\nListagem de animais e procedimentos\n");
	
	for(x=0; x <= (*controle).qtd_animais; x++){
		
		printf("----------------------------------------------------");
		
		printf("\n- - Apelido: %s - -", (*controle).animais[x].apelido);
		printf("\nNumero de registro: %i \nRaca: %s \nCor: %s %", (*controle).animais[x].registro, (*controle).animais[x].raca, (*controle).animais[x].cor);
		printf("\nIdade (ignorando meses): %i anos \n \nDono: %s %", (*controle).animais[x].idade, (*controle).animais[x].dono);
		printf("\n\n");
		
		for(y=0; y <= (*controle).animais[x].qtd_procedimentos; y++){
			
			printf("------ Procedimento %i ------\n", (y+1));
			printf("Codigo: %i \nDescricao: %s", (*controle).animais[x].procedimentos[y].codigo, (*controle).animais[x].procedimentos[y].desc);
			printf("\nData: %s \nValor: %.2f\n\n", (*controle).animais[x].procedimentos[y].data, (*controle).animais[x].procedimentos[y].valor);
		}
	}
}

void listar_procedimentos_por_animal(Tcontrole *controle){ //listagem dos procedimentos por animal
	
		int x, y, codigo; /*x y sao variaveis de controle dos lacos de repeticao, codigo armazena o registro do animal que tera seus procedimentos listados*/
		
		printf("\nInforme o codigo do animal: ");
		scanf("%i", &codigo);
		
		x = busca_binaria(controle, codigo); //armazena a posicao do elemento buscado;
		
		printf("\n- - Apelido: %s - -", (*controle).animais[x].apelido);
		printf("\nNumero de registro: %i \nRaca: %s \nCor: %s %", (*controle).animais[x].registro, (*controle).animais[x].raca, (*controle).animais[x].cor);
		printf("\nIdade: %i \n \nDono: %s %", (*controle).animais[x].idade, (*controle).animais[x].dono);
		printf("\n\n");
		
		for(y=0; y <= (*controle).animais[x].qtd_procedimentos; y++){
			
			printf("------ Procedimento %i ------\n", (y+1));
			printf("Codigo: %i \nDescricao: %s", (*controle).animais[x].procedimentos[y].codigo, (*controle).animais[x].procedimentos[y].desc);
			printf("\nData: %s \nValor: %.2f\n\n", (*controle).animais[x].procedimentos[y].data, (*controle).animais[x].procedimentos[y].valor);
			
		}
}

void remover_procedimento(Tcontrole *controle){ //tem como objetivo remover um procedimento
	int cod_animal, cod_procedimento, indice_animal, indice_procedimento=-1, x, y; /*x e y, variaveis de controle dos lacos de repeticao*/
	/*registro do animal, codigo do procedimento, posicao do animal e do procedimento que deseja remover, respectivamente */
	
	printf("Informe o codigo do animal: ");
	scanf("%i", &cod_animal);
	printf("Informe o codigo do procedimento: ");
	scanf("%i", &cod_procedimento);
	
	indice_animal = busca_binaria(controle, cod_animal);
	 
	for(x = 0; x <= (*controle).animais[indice_animal].qtd_procedimentos; x++){
		if(cod_procedimento == (*controle).animais[indice_animal].procedimentos[x].codigo){
			indice_procedimento = x;
		}
	}
	
	if(indice_procedimento > -1 && indice_procedimento <= (*controle).animais[indice_animal].qtd_procedimentos){
		
		if(indice_procedimento == (*controle).animais[indice_animal].qtd_procedimentos){
			
			(*controle).animais[indice_animal].qtd_procedimentos -= 1;
			printf("\n- - Procedimento removido - -\n");
			
		}else{
			
			for(y = indice_procedimento ; y < (*controle).animais[indice_animal].qtd_procedimentos; y++){
				
				(*controle).animais[indice_animal].procedimentos[y] = (*controle).animais[indice_animal].procedimentos[y+1];
				
			}
			
			(*controle).animais[indice_animal].qtd_procedimentos -= 1;
			printf("\n- - Procedimento removido - -\n");
		}
		
	}else{
		printf("\nOs codigos informados nao foram encontrados na base de dados\n");
	}
}

void remover_animal(Tcontrole *controle){ // remoção de um animal da base de dados
	int cod_animal, indice_animal, y; /*respectivamente, codigo do animal a ser removido, armazena a posicao retornada pela busca binaria, variavel de controle do laco de repeticao*/
	
	printf("Informe o codigo do animal: ");
	scanf("%i", &cod_animal);
	
	indice_animal = busca_binaria(controle, cod_animal);
	
	if(indice_animal > -1 && indice_animal <= (*controle).qtd_animais){
		if(indice_animal == (*controle).qtd_animais){
			
			(*controle).qtd_animais -= 1;
			printf("\n- - Animal removido - -\n");
			
		}else{
			
			for(y = indice_animal; y < (*controle).qtd_animais; y++){
				
				(*controle).animais[y] = (*controle).animais[y+1];
				
			}
			(*controle).qtd_animais -= 1;
			printf("\n- - Animal removido - -\n");
		}
		
	}else{
		printf("\nOs codigos informados nao foram encontrados na base de dados\n");
	}
}

int main(){ 
	
	int op=0;
	Tcontrole controle;
	Tanimal animal;
	Tprocedimento procedimento;
	
	do{
		
		printf("\n - - - - - - - - - FICHA CADASTRAL - PETSHOP - - - - - - - - - \n");
		printf("[1] Incluir animal\n");
		printf("[2] Incluir procedimento\n");
		printf("[3] Listar animais e procedimentos\n");
		printf("[4] Listar procedimentos por animal\n");
		printf("[5] Remover procedimento\n");
		printf("[6] Remover animal\n");
		printf("[0] Sair\n");
		printf("\nInsira a opcao desejada: ");
		scanf("%i", &op);
		
		switch(op){
			case 1:
				
				animal = get_animal();
				add_animal(&controle, animal);
				bubble_sort(&controle);
				break;
				
			case 2:
				
				int codigo_animal;
				
				procedimento = get_procedimento();
				
				printf("\nCodigo do animal: ");
				scanf("%i", &codigo_animal);
				
				add_procedimento(&controle, procedimento, codigo_animal);
				break;
				
			case 3:
				
				listar_animais_procedimentos(&controle);
				break;
				
			case 4:
				
				listar_procedimentos_por_animal(&controle);
				break;
				
			case 5:
				
				remover_procedimento(&controle);
				break;
			case 6:
				
				remover_animal(&controle);
		}
	}while(op);
}
