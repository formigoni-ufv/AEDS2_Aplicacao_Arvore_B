#include <stdio.h>
#include <stdlib.h>
#include "statistic.h"
#include "b_tree.h"
#include "registry/registry.h"

#define TRUE 1
#define FALSE 0

void BTREE_INIT(Page_Pointer* tree){
	*tree = NULL;
}

/*****************************************PESQUISA***********************************************/
void BTREE_SEARCH(Registry *data, Page_Pointer tree, int* found){
	long i=1;																			//Marcador de posicao na pagina
	if(tree == NULL){
		*found = FALSE;
		printf("Registro Ausente\n");
		return;
	}

	while(i < tree->n && data->admission_number > tree->data[i-1].admission_number){	//Enquanto i for menor que o tamanho de registros na pagina
		i++;																			//e enquanto o valor inserido for maior que o valor da posicao
	}																					//atual no vetor, i é incrementado

	if(data->admission_number == tree->data[i-1].admission_number){						//Se for igual, copia registro e retorna
		*data = tree->data[i-1];
		*found = TRUE;
		printf("Registro esta na arvore.\n");
		putchar('\n');
		return;
	}

	if(data->admission_number < tree->data[i-1].admission_number){					//Se for menor do que o i da vez, manda para o filho da esquerda
		BTREE_SEARCH(data, tree->pointers[i-1], found);
	}else{																			//Se for maior do que o i da vez, manda para o filho da direita
		BTREE_SEARCH(data, tree->pointers[i], found);
	}
}


/***********************************INSERCAO DE REGISTROS*****************************************/
void BTREE_INSERTONPAGE(Page_Pointer tree, Registry data, Page_Pointer pointer_Right){
	short positionNotFound;
	int k;
	k = tree->n;
	positionNotFound = (k > 0);								//Se a pagina for vazia, somente e necessario inserir

	while(positionNotFound){								//A pagina nao e vazia, e necessario procurar uma posicao vazia na mesma

		if(data.admission_number >= tree->data[k-1].admission_number){	//Se o registro inserido tiver uma chave maior que os registros da arvore, posicao encontrada
			positionNotFound = FALSE;
			break;
		}
		STATS_COMPARISON();

		tree->data[k] = tree->data[k-1];					//Empurra valor para frente, abrindo seu espaco
		tree->pointers[k+1] = tree->pointers[k];			//Ajusta ponteiros

		k--;

		if(k < 1){
			positionNotFound = FALSE;
		}
		STATS_COMPARISON();
	}

	tree->data[k] = data;
	tree->pointers[k+1] = pointer_Right;
	tree->n++;

}

void BTREE_INS(Registry data, Page_Pointer tree, short* grew, Registry* returnData, Page_Pointer* returnPointer, int* recursivelevel){
	long i=1;
	long j;
	Page_Pointer pp_temp;

	if(tree == NULL){											//Se a arvore for nula, retorna e cria a página raiz em BTREE_INSERT
		*grew = TRUE;
		(*returnData) = data;
		(*returnPointer) = NULL;
		return;
	}
	STATS_COMPARISON();

	if(*recursivelevel > 0){									//Nao Nativo
		STATS_DISKREAD();										//Novo acesso ao disco toda vez que é acessada uma nova página, exceto raiz
	}

	while(i < tree->n && data.admission_number > tree->data[i-1].admission_number) i++;

	if(data.admission_number == tree->data[i-1].admission_number){				//Se registro ja esta na arvore, retorna
		printf("Registry already on the tree.\n");
		*grew = FALSE;
		return;
	}
	STATS_COMPARISON();

	if(data.admission_number < tree->data[i-1].admission_number){				//Ajusta o i para ir para o filho da esquerda caso a chave do registro inserido seja menor que do i da vez
		i--;
	}
	STATS_COMPARISON();

	if(tree->pointers[i] != NULL){							//Nao Nativo
		(*recursivelevel)++;
	}

	BTREE_INS(data, tree->pointers[i], grew, returnData, returnPointer, recursivelevel);

	if(!*grew) return;										//Se a arvore nao cresceu, retorne
	STATS_COMPARISON();

	if(tree->n < MM){										//Pagina tem espaco
		BTREE_INSERTONPAGE(tree, *returnData, *returnPointer);
		*grew = FALSE;
		return;
	}
	STATS_COMPARISON();

	/*Daqui pra frente considera-se que a pagina estava cheia*/

	pp_temp = (Page_Pointer) malloc(sizeof(Page));			//Aloca-se uma pagina temporaria
	pp_temp->n = 0;
	pp_temp->pointers[0] = NULL;

	if(i < M + 1){
		BTREE_INSERTONPAGE(pp_temp, tree->data[MM-1], tree->pointers[MM]);
		tree->n--;
		BTREE_INSERTONPAGE(tree, *returnData, *returnPointer);

		STATS_DISKWRITE();	//Escreve pp_temp no disco
		STATS_DISKWRITE();	//Escreve tree que agora está no disco
		STATS_DISKWRITE();  //Contabilizando o for abaixo acesso à pp_temp após ter acessado tree
	}else{
		BTREE_INSERTONPAGE(pp_temp, *returnData, *returnPointer);

		STATS_DISKWRITE();	//Escreve pp_temp no disco
	}
	STATS_COMPARISON();

	for(j = M+2; j<=MM; j++){
		BTREE_INSERTONPAGE(pp_temp, tree->data[j-1], tree->pointers[j]);
	}

	STATS_DISKWRITE();

	tree->n = M;
	pp_temp->pointers[0] = tree->pointers[M+1];
	*returnData = tree->data[M];
	*returnPointer = pp_temp;

}

void BTREE_INSERT(Registry data, Page_Pointer* tree){
	short grew;
	int recursivelevel = 0;
	Registry returnData;
	Page_Pointer returnPointer, tempPointer;

	BTREE_INS(data, *tree, &grew, &returnData, &returnPointer, &recursivelevel);
	if(grew){
		tempPointer = (Page_Pointer) malloc(sizeof(Page));	//Write
		tempPointer->n = 1;
		tempPointer->data[0] = returnData;
		tempPointer->pointers[1] = returnPointer;
		tempPointer->pointers[0] = *tree;					//Read
		*tree = tempPointer;

		STATS_COMPARISON();
	}
}



/***********************************REMOCAO DE REGISTROS*****************************************/
void BTREE_RECONSTITUTE(Page_Pointer ApPag, Page_Pointer ApPai, int PosPai, short* Diminuiu){
	Page_Pointer aux;
	long DispAux, j;

	if(PosPai < ApPai->n){
		aux = ApPai->pointers[PosPai+1];
		DispAux = (aux->n - M + 1) / 2;
		ApPag->data[ApPag->n]  = ApPai->data[PosPai];
		ApPag->pointers[ApPag->n + 1] = aux->pointers[0];
		ApPag->n++;

		if(DispAux > 0){
			for(j=1; j<DispAux; j++){
				BTREE_INSERTONPAGE(ApPag, aux->data[j-1], aux->pointers[j]);
			}
			ApPai->data[PosPai] = aux->data[DispAux-1];
			aux->n -= DispAux;
			for(j=0; j<aux->n; j++) aux->data[j] = aux->data[j+DispAux];
			for(j=0; j<=aux->n; j++) aux->pointers[j] = aux->pointers[j+DispAux];
			*Diminuiu = FALSE;
		}else{	// Fusao, RÁ
			for(j=1; j<=M; j++) BTREE_INSERTONPAGE(ApPag, aux->data[j-1], aux->pointers[j]);
			free(aux);
			for(j=PosPai+1; j<ApPai->n; j++){
				ApPai->data[j-1] = ApPai->data[j];
				ApPai->pointers[j] = ApPai->pointers[j+1];
			}
			ApPai->n--;
			if(ApPai->n >= M) *Diminuiu = FALSE;
		}
	}else{
		aux = ApPai->pointers[PosPai-1];
		DispAux = (aux->n - M + 1) / 2;

		for(j = ApPag->n; j>=1; j--){
			ApPag->data[j] = ApPag->data[j-1];
		}

		ApPag->data[0] = ApPai->data[PosPai-1];

		for(j = ApPag->n; j>=0; j--){
			ApPag->pointers[j+1] = ApPag->pointers[j];
		}

		ApPag->n++;

		if(DispAux > 0){
			for(j = 1; j<DispAux; j++){
				BTREE_INSERTONPAGE(ApPag, aux->data[aux->n - j], aux->pointers[aux->n - j + 1]);
			}
			ApPag->pointers[0] = aux->pointers[aux->n - DispAux + 1];
			ApPai->data[PosPai-1] = aux->data[aux->n - DispAux];
			aux->n -= DispAux;
			*Diminuiu = FALSE;
		}else{
			for(j=1; j<=M; j++){
				BTREE_INSERTONPAGE(aux, ApPag->data[j-1], ApPag->pointers[j]);
			}
			free(ApPag);
			ApPai->n--;
			if(ApPai->n >= M) *Diminuiu = FALSE;
		}
	}
}

void BTREE_PREDECESSOR(Page_Pointer Ap, int lnd, Page_Pointer ApPai, short *Diminuiu){
	if(ApPai->pointers[ApPai->n] != NULL){
		BTREE_PREDECESSOR(Ap, lnd, ApPai->pointers[ApPai->n], Diminuiu);
		if(*Diminuiu){
			BTREE_RECONSTITUTE(ApPai->pointers[ApPai->n], ApPai, (long) ApPai->n, Diminuiu);
		}
		return;
	}
	Ap->data[lnd-1] = ApPai->data[(ApPai->n)-1];
	ApPai->n--;
	*Diminuiu = (ApPai->n < M);
}

void BTREE_REM(Registry Ch, Page_Pointer *Ap, short *Diminuiu, int* recursivelevel){
	long j, lnd = 1;
	Page_Pointer Pag;

	if(*Ap == NULL){
		printf("Erro: registro nao esta na arvore\n");
		*Diminuiu = FALSE;
		return;
	}

	if(recursivelevel > 0){
		STATS_DISKREAD();
	}

	Pag = *Ap;

	while(lnd < Pag->n && Ch.admission_number > Pag->data[lnd-1].admission_number){
		lnd++;
		STATS_COMPARISON();
	}

	if(Ch.admission_number == Pag->data[lnd-1].admission_number){
		if(Pag->pointers[lnd-1] == NULL){
			Pag->n--;
			*Diminuiu = (Pag->n < M);
			for(j = lnd; j <= Pag->n; j++){
				Pag->data[j-1] = Pag->data[j];
				Pag->pointers[j] = Pag->pointers[j+1];
			}

			STATS_DISKWRITE();
			return;
		}STATS_COMPARISON();


		BTREE_PREDECESSOR(*Ap, lnd, Pag->pointers[lnd-1], Diminuiu);

		if(*Diminuiu){
			BTREE_RECONSTITUTE(Pag->pointers[lnd-1], *Ap, lnd-1, Diminuiu);
		}STATS_COMPARISON();

		return;
	}STATS_COMPARISON();

	if(Ch.admission_number > Pag->data[lnd-1].admission_number){
		lnd++;
	}
	BTREE_REM(Ch, &Pag->pointers[lnd-1], Diminuiu);
	if(*Diminuiu){
		BTREE_RECONSTITUTE(Pag->pointers[lnd-1], *Ap, lnd-1, Diminuiu);
	}
}

void BTREE_REMOVE(Registry Ch, Page_Pointer *Ap){
	int recursivelevel = 0;
	short Diminuiu;
	Page_Pointer Aux;

	BTREE_REM(Ch, Ap, &Diminuiu, &recursivelevel);
	if(Diminuiu && (*Ap)->n == 0){	//Arvore Diminui Altura
		Aux = *Ap;
		*Ap = Aux->pointers[0];
		free(Aux);
	}
}

/*****************************************ALTURA***********************************************/
void BTREE_HHEIGHT(Page_Pointer* tree, long* i){
	if(*tree != NULL){
		BTREE_HHEIGHT(&(*tree)->pointers[0], i);
		(*i)++;
	}
	return;
}

long BTREE_HEIGHT(Page_Pointer* tree){
	long i=0;
	BTREE_HHEIGHT(tree, &i);
	return i;
}