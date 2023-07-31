#pragma once

//utilizar os #include necessários
//-------------------------------------------
#define DATA(node) ((node)->pData)
#define LEFT(node) ((node)->pLeft)
#define RIGHT(node) ((node)->pRight)
#define EMPTY NULL
#define NO_LINK NULL
//-------------------------------------------

typedef enum _STATUS { ERROR = 0, OK = 1 } STATUS;
typedef enum _BOOLEAN { FALSE = 0, TRUE = 1 } BOOLEAN;


typedef struct _BTREE_NODE {
	void* pData;
	struct _BTREE_NODE* pLeft;
	struct _BTREE_NODE* pRight;
} BTREE_NODE;

typedef BTREE_NODE* BTREE;


//-------------------------------------------
//---declaracao de funcoes----------
STATUS initBTree(BTREE*);
BOOLEAN emptyBTree(BTREE);
BOOLEAN isLeaf(BTREE_NODE*);
STATUS createNewBTNode(BTREE_NODE**, void*);
void printIntBTreeInOrder(BTREE);
void printIntBTreePreOrder(BTREE);
void printIntBTreePostOrder(BTREE);
BOOLEAN SearchNode(BTREE BT, int num, int nivel);
STATUS insertIntBST(BTREE*, void*);
STATUS insertBT(BTREE*, void*, void*, void*);
int CountNodes(BTREE BT);
int CountSheets(BTREE BT);
//-------------------------------------------

