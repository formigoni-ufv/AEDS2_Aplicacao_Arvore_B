#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "b_tree.h"
#include "registries_generator.h"

int main(){
	int i;
	FILE *name_list, *GEN_output;
	Registry regs[REGSTOBESCANNED];
	Page_Pointer root;

	srand(time(NULL));

	//GERA REGISTROS
	name_list = fopen("names_database.txt", "r");
	REGEN_GEN(&name_list);
	fclose(name_list);

	GEN_output = fopen("registries_generated.txt", "r");
	REG_FSCAN(&GEN_output, regs, REGSTOBESCANNED);

	//B_TREE INSERE
	BTREE_INIT(&root);

	for(i=0; i<REGSTOBESCANNED; i++){
		BTREE_INSERT(regs[i], &root);
	}

	for(i=0; i<REGSTOBESCANNED; i++){
		BTREE_SEARCH(&regs[i], root);
	}

	return 0;
}