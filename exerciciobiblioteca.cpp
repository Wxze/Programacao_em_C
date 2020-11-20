#include <stdio.h>
#include <stdlib.h>

typedef int t_ano, t_volume, t_quantidadePaginas;
typedef char t_cidade[50], t_editora[50], t_isbn[15], t_descricao[100], t_autor[100];

typedef struct  {
    t_ano ano;
    t_volume volume;
    t_cidade cidade;
    t_editora editora;
} t_publicacao;


typedef struct  {
    t_isbn isbn;
    t_descricao descricao;
    t_autor autor;
    t_quantidadePaginas quantidadePaginas;
    t_publicacao publicacao;
} t_titulo;


t_titulo vetorTitulos [100];
t_titulo novoTitulo;

void menu();
void incluir_titulo();
void consultar_titulo();
void listar_titulo();

int continuar = 1;
int ultimoTitulo = -1;
int indice = -1;

int main() {

    do
    {
        menu();

        switch(continuar)
        {
            case 1:
				incluir_titulo();
                break;

            case 2:
                consultar_titulo();
                break;

            case 3:
               listar_titulo();
                break;

            case 0:
                printf("Ate mais...\n");
                break;

            default:
                printf("Digite uma opcao valida\n");
        }
    } while(continuar);
    
    return 0;
}
    
    void menu(){
    	printf("\n\t======== Biblioteca UNAERP ========\n\n");
        printf("1. Incluir Titulo\n");
        printf("2. Consultar Titulo\n");
        printf("3. Lista Titulos\n");
        printf("0. Sair\n");

        scanf("%d", &continuar);
	}
    
    void incluir_titulo(){
    	printf("Digite o nome do autor: ");
        scanf("%s", novoTitulo.autor);

        printf("Digite a descricao do titulo: ");
        scanf("%s", novoTitulo.descricao);

        printf("Digite a editora da publicacao: ");
        scanf("%s", novoTitulo.publicacao.editora);

        ultimoTitulo++;

        vetorTitulos[ultimoTitulo] = novoTitulo;
	}
	
	void consultar_titulo(){
   		printf("\nQual indice do titulo: ");
    	scanf("%d", &indice);

    	if (indice < 0 || indice > ultimoTitulo){
       		printf("Indice invalido. ");
    	} else {
        	printf("###########\n Titulo %d \n Autor %s \n Descricao %s \n Editora %s",indice, vetorTitulos[indice].autor, vetorTitulos[indice].descricao, vetorTitulos[indice].publicacao.editora);
    	}	
	}
    
    void listar_titulo(){
    	for (int i = 0; i <= ultimoTitulo; ++i) {
        printf("###########\n Titulo %d \n Autor %s \n Descricao %s \n Editora %s",i, vetorTitulos[i].autor, vetorTitulos[i].descricao, vetorTitulos[i].publicacao.editora);
        }
	}
    

