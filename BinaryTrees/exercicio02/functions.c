#include "Functions.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>


/**************************************************************
* Fun��o initBTree(): Inicializa a �rvore bin�ria
*
* Par�metros: pBT � �rvore bin�ria (passado por ref)
* Sa�da: STATUS
***************************************************************/
STATUS initBTree(BTREE* pBT)
{
	*pBT = NULL;
	return OK;
}



/**************************************************************
* Fun��o emptyBTree(): verifica se a �rvore bin�ria est� vazia
*
* Par�metros: BT � �rvore bin�ria
* Sa�da: TRUE se a �rvore bin�ria estiver vazia, FALSE caso contr�rio
***************************************************************/
BOOLEAN emptyBTree(BTREE BT)
{
	return (BT == NULL) ? TRUE : FALSE;
}



/**************************************************************
* Fun��o isLeaf(): verifica se adeterminado n� da �rvore bin�ria � folha
*
* Par�metros: pNode � apontador para n� (da �rvore bin�ria)
* Sa�da: TRUE se for uma folha, FALSE caso contr�rio
***************************************************************/
BOOLEAN isLeaf(BTREE_NODE* pNode)
{
	return ((LEFT(pNode) == NULL) && (RIGHT(pNode) == NULL)) ? TRUE : FALSE;
}



/**************************************************************
* Fun��o printBTree(): apresenta no ecr� os elementos da �rvore bin�ria
*
* Par�metros: BT � �rvore bin�ria
* Sa�da: void
*
* Esta fun��o n�o � gen�rica: s� funciona para elementos de tipo INT
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
* Fun��o insertIntBST(): insere um elemento (n�) numa BST
*
* Par�metros: pBT � BST (passado por ref)
* pData - apontador gen�rico para os dados a inserir no n� criado
* Sa�da: OK se o n� foi inserido na BST e ERROR caso contr�rio
* Esta fun��o n�o � gen�rica: s� funciona para elementos de tipo INT
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
* Fun��o createNewBTNode(): cria um n� da �rvore bin�ria
*
* Par�metros: pData - apontador gen�rico para os dados a inserir no n� criado
* Sa�da: apontador para o n� criado ou NULL em caso de erro
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