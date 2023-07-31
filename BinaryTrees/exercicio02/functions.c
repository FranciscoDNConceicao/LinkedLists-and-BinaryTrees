#include "Functions.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>


/**************************************************************
* Função initBTree(): Inicializa a árvore binária
*
* Parâmetros: pBT – árvore binária (passado por ref)
* Saída: STATUS
***************************************************************/
STATUS initBTree(BTREE* pBT)
{
	*pBT = NULL;
	return OK;
}



/**************************************************************
* Função emptyBTree(): verifica se a árvore binária está vazia
*
* Parâmetros: BT – árvore binária
* Saída: TRUE se a árvore binária estiver vazia, FALSE caso contrário
***************************************************************/
BOOLEAN emptyBTree(BTREE BT)
{
	return (BT == NULL) ? TRUE : FALSE;
}



/**************************************************************
* Função isLeaf(): verifica se adeterminado nó da árvore binária é folha
*
* Parâmetros: pNode – apontador para nó (da árvore binária)
* Saída: TRUE se for uma folha, FALSE caso contrário
***************************************************************/
BOOLEAN isLeaf(BTREE_NODE* pNode)
{
	return ((LEFT(pNode) == NULL) && (RIGHT(pNode) == NULL)) ? TRUE : FALSE;
}



/**************************************************************
* Função printBTree(): apresenta no ecrã os elementos da árvore binária
*
* Parâmetros: BT – árvore binária
* Saída: void
*
* Esta função não é genérica: só funciona para elementos de tipo INT
***************************************************************/
void printIntBTreeInOrder(BTREE BT)
{
	if (emptyBTree(BT) == TRUE) return;
	printIntBTreeInOrder(LEFT(BT));
	printf("%d, ", (*(int*)DATA(BT)));
	printIntBTreeInOrder(RIGHT(BT));
	return;
}
void printIntBTreePosOrder(BTREE BT) {
	if (emptyBTree(BT) == TRUE) return;
	printIntBTreePosOrder(LEFT(BT));
	printIntBTreePosOrder(RIGHT(BT));
	printf("%d, ", *(int*)DATA(BT));
	return;
}
void printIntBtreePreOrder(BTREE BT) {
	if (emptyBTree(BT) == TRUE) return;
	printf("%d, ", *(int*)DATA(BT));
	printIntBtreePreOrder(LEFT(BT));
	printIntBtreePreOrder(RIGHT(BT));
}


/**************************************************************
* Função insertIntBST(): insere um elemento (nó) numa BST
*
* Parâmetros: pBT – BST (passado por ref)
* pData - apontador genérico para os dados a inserir no nó criado
* Saída: OK se o nó foi inserido na BST e ERROR caso contrário
* Esta função não é genérica: só funciona para elementos de tipo INT
***************************************************************/
STATUS insertIntBST(BTREE* pBT, void* pData)
{
	if (emptyBTree(*pBT))
	{
		BTREE_NODE* pNew;
		if (createNewBTNode(&pNew, pData) == ERROR)
			return ERROR;
		*pBT = pNew;
		return OK;
	}
	else if (*(int*)(pData) < *(int*)(DATA(*pBT)))
		insertIntBST(&(LEFT(*pBT)), pData);
	else insertIntBST(&(RIGHT(*pBT)), pData);
	return OK;
}


/**************************************************************
* Função createNewBTNode(): cria um nó da árvore binária
*
* Parâmetros: pData - apontador genérico para os dados a inserir no nó criado
* Saída: apontador para o nó criado ou NULL em caso de erro
***************************************************************/
STATUS createNewBTNode(BTREE_NODE** pNew, void* pData)
{
	BTREE_NODE* pTemp;
	if ((pTemp = (BTREE_NODE*)malloc(sizeof(BTREE_NODE))) == NULL)
		return ERROR;
	*pNew = pTemp;
	DATA(pTemp) = pData;
	LEFT(pTemp) = NULL;
	RIGHT(pTemp) = NULL;
	return OK;
}

int CountNodes(BTREE BT) {
	if (BT == NULL) {
		return 0;
	}
	else {
		return 1 + CountNodes(LEFT(BT)) + CountNodes(RIGHT(BT));
	}
	
}

int CountSheets(BTREE BT) {
	if (LEFT(BT) == NULL && RIGHT(BT) == NULL) {
		return 1;
	}
	else if (BT == NULL) {
		return;
	}

	return CountSheets(RIGHT(BT)) + CountSheets(LEFT(BT));
}

BOOLEAN SearchNode(BTREE BT, int num, int nivel) {
	if ((*(int*)DATA(BT)) == num) {
		printf("%d\n", nivel);
		return TRUE;
	}
	else if ((*(int*)DATA(BT)) > num) {
		SearchNode(LEFT(BT), num, nivel+1);
	}
	else if ((*(int*)DATA(BT)) < num) {
		SearchNode(RIGHT(BT), num, nivel+1);
	}
	else {
		return FALSE;
	}
}