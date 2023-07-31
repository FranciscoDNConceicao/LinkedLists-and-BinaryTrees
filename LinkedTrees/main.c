#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
#include "functions.h"


int main() {
	LIST linhas[NUM_LINHAS];
	int numeroLinha = 0;
	int opcao, numeroEstacoes;
	ESTACAO *estacaoTeste;


	estacaoTeste = (ESTACAO*)malloc(sizeof(ESTACAO));
	for (int i = 0; i < NUM_LINHAS; i++)
		linhas[i] = NULL;

	while (numeroLinha != 6) {
		printf("\n-----------ESTACAO DE COMBOIOS------------\n");
		printf("1-Linha 1\n");
		printf("2-Linha 2\n");
		printf("3-Linha 3\n");
		printf("4-Linha 4\n");
		printf("5-Linha 5\n");
		printf("6-Sair\n");
		printf("------------------------------------------\n");

		printf("Escolha uma opcao: ");
		(void)scanf("%d", &numeroLinha);
		
		opcao = 0;

		if (numeroLinha >= 6) {
			return 0;
		}
		while (opcao != 9) {
			printf("\n-----------ESTACAO DE COMBOIOS------------\n");
			printf("1-Ler os dados no ficheiro\n");
			printf("2-Mostrar as estacoes\n");
			printf("3-Adicionar uma estacao ao inicio\n");
			printf("4-Adicionar uma estacao ao fim\n");
			printf("5-Custo de uma viagem\n");
			printf("6-Ativar/Desativar estacao\n");
			printf("7-Eliminar uma estacao\n");
			printf("8-Numero da estacao da Linha\n");
			printf("9-Voltar\n");
			printf("------------------------------------------\n");

			printf("Escolha uma opcao: ");
			(void)scanf("%d", &opcao);
			printf("\n");


			switch (opcao) {
			case 1:
				if (ReadFile(&linhas, numeroLinha) == ERROR) {
					printf("\nOcorreu um erro ao ler o ficheiro tente novamente\n");
				}
				else {
					printf("A leitura do ficheiro foi bem sucedida\n");
				}
				break;
			case 2:
				ShowValues(linhas, numeroLinha);
				break;
			case 3:
				UserInput(estacaoTeste);
				InsertIni(&linhas, estacaoTeste, numeroLinha-12);
				break;
			case 4:
				UserInput(estacaoTeste);
				InsertEnd(&linhas, estacaoTeste, numeroLinha);
				break;
			case 5:
				CustoViagem(linhas, numeroLinha);
				break;
			case 6:
				ativarEstacao(linhas, numeroLinha);
				break;
			case 7:
				eliminarEstacao(linhas, numeroLinha);
				break;
			case 8:
				numeroEstacoes = ListSize(&linhas, numeroLinha);
				printf("\nEsta linha contem %d estacoes \n", numeroEstacoes);
				break;
			case 9:
				break;
				break;
			default:
				printf("\nIntroduziu uma opção incorreta\n");
			}
		}
	}
	
}