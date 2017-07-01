#ifndef AEDS2_APLICACAO_ARVORE_B_B_TREE_H
#define AEDS2_APLICACAO_ARVORE_B_B_TREE_H
#include"registry/registry.h"
#define M 2
#define MM M*2

typedef struct Page* Page_Pointer;
typedef struct Page{
	short n;						//Numero de registros na pagina
	Registry data[MM];				//Vetor contendo os registros da pagina
	Page_Pointer pointers[MM+1];	//Vetor contendo os ponteiros para os filhos da pagina
}Page;

//MAIN OPERATIONS
void BTREE_INIT(Page_Pointer* tree);

/*****************************************PESQUISA***********************************************/
void BTREE_SEARCH(Registry *data, Page_Pointer tree, int* found);

/***********************************INSERCAO DE REGISTROS*****************************************/
void BTREE_INSERTONPAGE(Page_Pointer tree, Registry data, Page_Pointer pointer_Right);
void BTREE_INS(Registry data, Page_Pointer tree, short* grew, Registry* returnData, Page_Pointer* returnPointer, int* recursivelevel);
void BTREE_INSERT(Registry data, Page_Pointer* tree);

/***********************************REMOCAO DE REGISTROS*****************************************/
void BTREE_RECONSTITUTE(Page_Pointer ApPag, Page_Pointer ApPai, int PosPai, short* Diminuiu);
void BTREE_PREDECESSOR(Page_Pointer Ap, int lnd, Page_Pointer ApPai, short *Diminuiu);
void BTREE_REM(Registry Ch, Page_Pointer *Ap, short *Diminuiu, int* recursivelevel);
void BTREE_REMOVE(Registry Ch, Page_Pointer *Ap);

/*****************************************ALTURA***********************************************/
void BTREE_HHEIGHT(Page_Pointer* tree, long* i);
long BTREE_HEIGHT(Page_Pointer* tree);

#endif //AEDS2_APLICACAO_ARVORE_B_B_TREE_H
