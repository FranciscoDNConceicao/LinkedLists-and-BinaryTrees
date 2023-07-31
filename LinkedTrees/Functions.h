#ifndef FOO_DOT_H   
#define FOO_DOT_H

typedef enum _BOOLEAN { TRUE = 1, FALSE = 0 } BOOLEAN;
typedef enum _STATUS { OK, ERROR } STATUS;
typedef enum _LIST_LOCATION { LIST_START, LIST_END } LIST_LOCATION;

#define MAX 20;
#define DATA(node) ((node)->data)
#define NEXT(node) ((node)->next)
#define NUM_LINHAS 5


typedef struct _ESTACAO {
	char design[50];
	float custo;
	BOOLEAN ativa, no;
}ESTACAO;

typedef struct _LIST_NODE {
	void* data;
	struct LIST* next;
}LIST_NODE;

typedef LIST_NODE* LIST;



void initList(LIST* pl);
void ShowValues(LIST list[], int numLinha);
void ativarEstacao(LIST list[], int numeroLinha);
void CustoViagem(LIST list[], int numeroLinha);

int ListSize(LIST list[], int numeroLinha);

BOOLEAN emptyList(LIST L);
void UserInput(ESTACAO* estacao);  

LIST_NODE* newNode(void* data);

STATUS InsertIni(LIST* list, void* data);
STATUS InsertEnd(LIST* list[], void* data, int posicao);
STATUS ReadFile(LIST* list[], int numLinha);
STATUS eliminarEstacao(LIST list[], int numeroLinha);


#endif