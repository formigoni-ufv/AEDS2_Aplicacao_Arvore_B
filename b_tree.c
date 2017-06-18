#include <stdio.h>
#include <stdlib.h>
#include "b_tree.h"
#define TRUE 1
#define FALSE 0

void BTREE_INIT(Page_Pointer* tree){
	*tree = NULL;
}

void BTREE_SEARCH(Registry *data, Page_Pointer tree){
	long i=1;																			//Marcador de posicao na pagina
	if(tree == NULL){
		printf("Registro Ausente\n");
		return;
	}

	while(i < tree->n && data->admission_number > tree->data[i-1].admission_number){	//Enquanto i for menor que o tamanho de registros na pagina
		i++;																			//e enquanto o valor inserido for maior que o valor da posicao
	}																					//atual no vetor, i é incrementado

	if(data->admission_number == tree->data[i-1].admission_number){						//Se for igual, copia registro e retorna
		*data = tree->data[i-1];
		printf("Registro esta na arvore.\n");
		REG_PRINT(*data);
		putchar('\n');
		return;
	}

	if(data->admission_number < tree->data[i-1].admission_number){					//Se for menor do que o i da vez, manda para o filho da esquerda
		BTREE_SEARCH(data, tree->pointers[i-1]);
	}else{																			//Se for maior do que o i da vez, manda para o filho da direita
		BTREE_SEARCH(data, tree->pointers[i]);
	}
}

void BTREE_INSERTONPAGE(Page_Pointer tree, Registry data, Page_Pointer pointer_Right){
	short positionNotFound;
	int k;
	k = tree->n;
	positionNotFound = (k > 0);

	while(positionNotFound){

		if(data.admission_number >= tree->data[k-1].admission_number){
			positionNotFound = FALSE;
			break;
		}

		tree->data[k] = tree->data[k-1];					//Empurra valor para frente, abrindo seu espaco
		tree->pointers[k+1] = tree->pointers[k];

		k--;

		if(k < 1){
			positionNotFound = FALSE;
		}
	}

	tree->data[k] = data;
	tree->pointers[k+1] = pointer_Right;
	tree->n++;

}

void BTREE_INS(Registry data, Page_Pointer tree, short* grew, Registry* returnData, Page_Pointer* returnPointer){
	long i=1;
	long j;
	Page_Pointer pp_temp;

	if(tree == NULL){										//Se a arvore for nula, retorna e cria a página raiz em BTREE_INSERT
		*grew = TRUE;
		(*returnData) = data;
		(*returnPointer) = NULL;
		return;
	}

	while(i < tree->n && data.admission_number > tree->data[i-1].admission_number) i++;

	if(data.admission_number == tree->data[i-1].admission_number){				//Se registro ja esta na arvore, retorna
		printf("Registry already on the tree.\n");
		*grew = FALSE;
		return;
	}

	if(data.admission_number < tree->data[i-1].admission_number){					//Se a chave e menor que a chave do i da vez, mande-a para se filho da esquerda
		i--;
	}

	BTREE_INS(data, tree->pointers[i], grew, returnData, returnPointer);

	if(!*grew) return;										//Se a arvore nao cresceu, retorne

	if(tree->n < MM){										//Se a pagina nao esta cheia, insira a chave nela
		BTREE_INSERTONPAGE(tree, *returnData, *returnPointer);
		*grew = FALSE;
		return;
	}

	/*Daqui pra frente considera-se que a pagina estava cheia*/

	pp_temp = (Page_Pointer) malloc(sizeof(Page));			//Aloca-se uma pagina temporaria
	pp_temp->n = 0;
	pp_temp->pointers[0] = NULL;

	if(i < M + 1){
		BTREE_INSERTONPAGE(pp_temp, tree->data[MM-1], tree->pointers[MM]);
		tree->n--;
		BTREE_INSERTONPAGE(tree, *returnData, *returnPointer);
	}else{
		BTREE_INSERTONPAGE(pp_temp, *returnData, *returnPointer);
	}

	for(j = M+2; j<=MM; j++){
		BTREE_INSERTONPAGE(pp_temp, tree->data[j-1], tree->pointers[j]);
	}

	tree->n = M;
	pp_temp->pointers[0] = tree->pointers[M+1];
	*returnData = tree->data[M];
	*returnPointer = pp_temp;
}

void BTREE_INSERT(Registry data, Page_Pointer* tree){
	short grew;
	Registry returnData;
	Page_Pointer returnPointer, tempPointer;
	BTREE_INS(data, *tree, &grew, &returnData, &returnPointer);
	if(grew){
		tempPointer = (Page_Pointer) malloc(sizeof(Page));
		tempPointer->n = 1;
		tempPointer->data[0] = returnData;
		tempPointer->pointers[1] = returnPointer;
		tempPointer->pointers[0] = *tree;
		*tree = tempPointer;
	}
}
