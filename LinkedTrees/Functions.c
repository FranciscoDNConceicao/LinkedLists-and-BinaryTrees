#include "Functions.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>

void initList(LIST* pl) { //Inicia a lista
	*pl = NULL;
}
BOOLEAN emptyList(LIST L) {		//Verifica se a lista está vazia ou não
	return ((L == NULL) ? TRUE : FALSE);
}


LIST_NODE* newNode(void* data) {							//Cria uma nova nó
	LIST_NODE* new;											//Inicializa o nó
	new = (LIST*)malloc(sizeof(LIST));						//Adiciona um espaço na memória para o novo nó
	if (new != NULL) {										//Verifica se o nó está vazio
		DATA(new) = data;									//Coloca os dados da Estação no nó que criamos
		NEXT(new) = NULL;									//Coloca o next 
	}
	return (new);
}


int ListSize(LIST list[], int numLinha) {
	LIST aux = list[numLinha];
	int tam = 0;
	while (aux != NULL) {
		tam++;
		aux = NEXT(aux);
	}
	return tam;
}

void ShowValues(LIST list[], int numLinha) {
	LIST aux = list[numLinha - 1];
	char ativa[20];
	if (emptyList(aux) == TRUE) {
		printf("\nLista Vazia\n");
	}
	printf("\n\nLISTA\n");
	while (aux != NULL)
	{
		if (((ESTACAO*)DATA(aux))->ativa == TRUE) {
			strcpy(ativa, "Ativa");
		}
		else if (((ESTACAO*)DATA(aux))->ativa == FALSE) {
			strcpy(ativa, "Desativada");
		}
		printf("-%s ---> %.2f ---> %s\n", ((ESTACAO*)DATA(aux))->design, ((ESTACAO*)DATA(aux))->custo, ativa);
		aux = NEXT(aux);

	}
	printf(" FIM\n\n");
}

STATUS InsertEnd(LIST* list[], void* data, int posicao) {
	LIST_NODE* new_node, * temp;
	if ((new_node = newNode(data)) != NULL)
	{
		if ((*list)[posicao] == NULL)
			(*list)[posicao] = new_node;
		else
		{
			temp = (*list)[posicao];
			while (NEXT(temp) != NULL) {
				temp = NEXT(temp);
			}
			NEXT(temp) = new_node;
		}
		return(OK);
	}
	return(ERROR);
}

STATUS InsertIni(LIST* list[], void* data, int posicao) {    //Insere uma lista no inicio da lista encadeada
	LIST_NODE* new;
 
	if ((new = newNode(data)) != NULL) { //Cria um novo no na lista

		if ((*list)[posicao] == NULL) {	 //Verifica se a lista é vazia
			(*list)[posicao] = new;
		}
		else {
			//Coloca o seguinte do no new a apontar para o nó de inicio antigo
			NEXT(new) = (* list)[posicao];
			//Coloca o new como nó de inicio
			(* list)[posicao] = new;
		}
		return OK;
	}
	return ERROR;
}
void ativarEstacao(LIST list[], int numeroLinha) {
	LIST curr = list[numeroLinha - 1];
	char nome[50];
	printf("\nNome da Estacao: ");
	(void)scanf(" %[^\n]s", &nome);
	while (curr != NULL) {
		if (strcmp(nome, ((ESTACAO*)DATA(curr))->design) == 0) {
			if (((ESTACAO*)DATA(curr))->ativa == 0) {
				((ESTACAO*)DATA(curr))->ativa = TRUE;
			}else if (((ESTACAO*)DATA(curr))->ativa == TRUE) {
				((ESTACAO*)DATA(curr))->ativa = FALSE;
			}
			printf("\nEstacao mudada com sucesso\n");
		}
		curr = curr->next;
	}
	return;
}

STATUS ReadFile(LIST* list[], int numLinha) {
	FILE* fpointer;
	ESTACAO* estacao;
	int aux, aux1;

	switch (numLinha)
	{
	case 1:
		fpointer = fopen("linha1.txt", "r");
		break;
	case 2:
		fpointer = fopen("linha2.txt", "r");
		break;
	case 3:
		fpointer = fopen("linha3.txt", "r");
		break;
	case 4:
		fpointer = fopen("linha4.txt", "r");
		break;
	case 5:
		fpointer = fopen("linha5.txt", "r");
		break;
	default:
		return ERROR;
		break;
	}


	while (!feof(fpointer)) {
		estacao = (ESTACAO*)malloc(sizeof(ESTACAO));
		fscanf(fpointer, "%[^;];%f;%d;%d;\n", estacao->design, &estacao->custo, &aux, &aux1);
		if (aux == 1) {
			estacao->ativa = TRUE;
		}
		else
		{
			estacao->ativa = FALSE;
		}
		if (aux1 == 1) {
			estacao->no = TRUE;
		}
		else {
			estacao->no = FALSE;
		}
		if (InsertEnd(&list, estacao, numLinha - 1) == OK) {
			continue;
		}
		else {
			printf("Erro na introdução da estação \n");
		}
	}
	return OK;

	fclose(fpointer);
}

STATUS eliminarEstacao(LIST list[], int numeroLinha) {
	LIST aux = list[numeroLinha-1];
	char nome[50];

	printf("\nNome da Estacao: ");
	(void)scanf(" %[^\n]s", nome);
	printf("%s", nome);
	while (aux != NULL) {					
		LIST seguinte = aux->next;				
		if (strcmp(nome, ((ESTACAO*)DATA(seguinte))->design) == 0) {
			NEXT(aux) = NEXT(seguinte);
			free(DATA(seguinte));
			free(seguinte);
			return OK;
		}
		aux = aux->next;
	}
	return ERROR;
}

void CustoViagem(LIST list[], int numeroLinha) {
	LIST aux = list[numeroLinha - 1];
	char partida[50], chegada[50];
	float custo = 0;
	int verificacao = 0;

	printf("\nInsira o nome da estacao de partida: ");
	(void)scanf(" %[^\n]s", &partida);
	printf("\nInsira o nome da estacao de chegada: ");
	(void)scanf(" %[^\n]s", &chegada);

	while (aux != NULL) {
		custo += ((ESTACAO*)DATA(aux))->custo;
		if (strcmp(partida, ((ESTACAO*)DATA(aux))->design) == 0){
			verificacao += 1;
			custo = 0;
		}
		else if (strcmp(chegada, ((ESTACAO*)DATA(aux))->design) == 0) {
			verificacao += 1;
			break;
		}
		aux = aux->next;
	}
	if (verificacao == 2) {
		printf("O custo da viagem foi de %.2f\n", custo);
	}
	else if (verificacao == 1) {
		printf("Uma das estacoes nao existe na linha\n");
	}
	else {
		printf("As duas estacoes nao existem na linha \n");
	}
}

void UserInput(ESTACAO* estacao) {
	char aux1, aux2;
	float custo;

	printf("\nInserir dados da estacao");
	printf("\nInsira nome da estacao: ");
	(void)scanf(" %[^\n]s", estacao->design);
	printf("\nCusto da estação: ");
	(void)scanf(" %f", &custo);
	estacao->custo = custo;

	printf("\nEstacao está ativa (s/n): ");
	(void)scanf(" %c", &aux1);
	printf("\nE uma estacao entre linhas? (s/N): ");
	(void)scanf(" %c", &aux2);

	if (aux1 == 's') {
		estacao->ativa = TRUE;
	}
	else if (aux1 == "n") {
		estacao->ativa = FALSE;
	}

	if (aux2 == 's') {
		estacao->no = TRUE;
	}
	else if (aux2 == 'n') {
		estacao->no = FALSE;
	}
}