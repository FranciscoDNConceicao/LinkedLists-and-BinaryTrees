#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
#include "functions.h"

int main() {
	BTREE arvore = NULL;
	int idade;
	int numeros[] = {4, -5, 0, 12, -2, 7, 1, -1, 8, 2};

	for (int i = 0; i <= 9; i++) {
		if (insertIntBST(&arvore, &numeros[i]) == OK) {
			continue;
		}
		else {
			break;
		}
	}
	printf("Percorrer a arvore em ordem: ");
	printIntBTreeInOrder(arvore);  

	printf("\n \n Percorrer a arvore em Pre-Ordem: ");
	printIntBtreePreOrder(arvore);

	printf("\n \n Percorrer a arvore em Pos-Ordem: ");
	printIntBTreePosOrder(arvore);

	int o;
	o = CountNodes(arvore);
	printf("\n\nNumero de nodes : %d\n", o);
	
	o = CountSheets(arvore);
	printf("\n\nNumero de folhas : %d\n", o);

	o = 0;
	printf("\nEscolha um numero:");
	scanf("%d", &o);

	if (SearchNode(arvore, o, 0)) {
		printf("Search concluida com sucesso \n");
	}
	else {
		printf("Não foi encontrado esse elemento \n");
	}
	return 0;

}

