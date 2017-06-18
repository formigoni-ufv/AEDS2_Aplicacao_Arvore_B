#ifndef AEDS2_APLICACAO_ARVORE_B_B_TREE_H
#define AEDS2_APLICACAO_ARVORE_B_B_TREE_H
#include"registry.h"
#define M 20
#define MM M*2

typedef struct Page* Page_Pointer;
typedef struct Page{
	short n;						//Numero de registros na pagina
	Registry data[MM];				//Vetor contendo os registros da pagina
	Page_Pointer pointers[MM+1];	//Vetor contendo os ponteiros para os filhos da pagina
}Page;

void BTREE_INIT(Page_Pointer* tree);
void BTREE_SEARCH(Registry *data, Page_Pointer tree);
void BTREE_INSERTONPAGE(Page_Pointer tree, Registry data, Page_Pointer pointer_Right);
void BTREE_INS(Registry data, Page_Pointer tree, short* grew, Registry* returnData, Page_Pointer* returnPointer);
void BTREE_INSERT(Registry data, Page_Pointer* tree);

#endif //AEDS2_APLICACAO_ARVORE_B_B_TREE_H
