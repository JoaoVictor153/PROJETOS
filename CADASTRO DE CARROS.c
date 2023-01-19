#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define TAM 2

typedef struct carro	
{
	char marca[10];
	char modelo[10];
	int ano;
	char lplaca[3];
	int nplaca;	
}carro;

carro cad[TAM];
 

void PesquisaCar(carro* Pesquisa);
void ListaDados(carro* lista);
void CadastroCar(carro* cadastro);


int main (){
	int op;
	system("cls");
    printf(">> MENU DE OPCOES <<\n");
    printf("\n[1] - CADASTRAR");
    printf("\n[2] - LISTAR");
	printf("\n[3] - PESQUISAR");	
    printf("\n[4] - SAIR");
    printf("\n\nESCOLHA UMA OPCAO: ");
	
	scanf("%d",&op);
	switch (op){
		case 1:
			CadastroCar(cad);
			break;
		case 2:
			ListaDados(cad);
			break;
		case 3:
			PesquisaCar(cad);
			break;
		case 4:
			system("exit");
			printf("\nSAINDO DO SISTEMA!!\n");
			exit(0);
		default:
			printf("\nOPCAO INVALIDA!!\nSAINDO DO SISTEMA");
			exit(0);
	}

return 0;	
}


void CadastroCar(carro* cadastro)
{
	int i;
	for (i=0; i<TAM; i++){
		printf("\n\n\n ---------- Insira um novo carro ----------\n");
		printf("\n\nMarca do carro -----------: ");
		fflush(stdin);
		scanf("%s",cad[i].marca);
	
		printf("Modelo do carro ----------: ");
		fflush(stdin);
		scanf("%s",cad[i].modelo);
		
		printf("Ano do carro -------------: ");
		fflush(stdin);
		scanf("%d",&cad[i].ano);
	
		if ((cad[i].ano>=1900)&&(cad[i].ano<= 2021)){
			printf("Digite as letras da placa : ");
			fflush(stdin);
			scanf("%s",cad[i].lplaca);
				
			printf("Digite os numeros da placa: ");
			fflush(stdin);
			scanf("%d",&cad[i].nplaca);
		
			if ((cad[i].nplaca>=1)&&(cad[i].nplaca<=9999))	{		
			}else{
				printf("\nERRO!! PLACA NO FORMATO ERRADO");				
			}	
		}else{
			printf("\nERRO!! ANO DE FABRICACAO DIVERGENTE");	
		}
	}
	int compararAno (const void *x, const void *y) {
    int pri = ((struct carro *)x)->ano;
    int seg = ((struct carro *)y)->ano;
    return (pri - seg);
	}
    qsort(cad, 2, sizeof(struct carro), compararAno);
	printf("\n\nCADASTRO EFETUADO COM SUCESSO!");
    printf("\n\nPRESSIONE <ENTER> PARA VOLTAR AO MENU...");
    fflush(stdin);
    getchar();
    main();
}

void ListaDados(carro* lista)
{
	system("cls");
	printf("\n\n---------- Dados dos carros ----------\n\n");
	int i;
    for (i=0; i<TAM; i++){
    	printf("\n\t-------------------\n\
                \r  %d%c\tMarca -----: %s    \n\
                \r\tModelo ----: %s    \n\
                \r\tAno -------: %d    \n\
                \r\tPlaca -----: %s-%d \n",
                i + 1 , 167,  cad[i].marca,
                cad[i].modelo, cad[i].ano ,
                cad[i].lplaca,cad[i].nplaca);
	}
	printf("\n\n\n\nPRESSIONE <ENTER> PARA VOLTAR AO MENU...");
    fflush(stdin);
    getchar();
    main();
}

void PesquisaCar(carro* Pesquisa)
{
	int i,z,j;
	int op;
	char aux[10];
	int pesquisa;
	printf("\nDIGITE >1< PARA PESQUISAR POR ANO E >2< PARA PESQUISAR POR MODELO:  ");
	scanf("%d",&op);
	if (op==1)	{
		system("cls");
		printf("\nDIGITE O ANO A SER PESQUISADO: ");
		scanf("%d",&pesquisa);	
		for (i=0; i<TAM; i++)
			if (pesquisa==cad[i].ano){
				printf("\nMarca-: %s\nModelo: %s\nAno---: %d\nPlaca-: %s-%d",cad[i].marca,cad[i].modelo,cad[i].ano,cad[i].lplaca,cad[i].nplaca);
				j++;
			}else if (j == 0)
			{
				printf("\nNAO FOI ENCONTRADO O ANO: %d \n",pesquisa);
			}else{
				j = 0;
			}
	}else{
		system("cls");
		printf("\nDIGITE O MODELO A SER PESQUISADO: ");
		scanf("%s",&aux);
		for (i=0; i<TAM; i++){
			if (strcmp(cad[i].modelo, strlwr(aux)) == 0)  {
                printf("\nMarca-: %s\nModelo: %s\nAno---: %d\nPlaca-: %s-%d",cad[i].marca,cad[i].modelo,cad[i].ano,cad[i].lplaca,cad[i].nplaca);
                z++;
            }
			else if (z == 0)
			{
                printf("\nNAO FOI ENCONTRADO O MODELO: %s \n",aux);
            }
            else{
                z = 0;
            }
        }
	}
    printf("\n\nPRESSIONE <ENTER> PARA VOLTAR AO MENU...");
    fflush(stdin);
    getchar();
    main();
}

