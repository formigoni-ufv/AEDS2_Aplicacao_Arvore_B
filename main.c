#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "b_tree.h"
#include "registry/registries_generator.h"
#include "statistic.h"
#include "registry/registry.h"

void OPSELECT(int REGISTRYRECOVERYAMMOUNT);

int main(){
	int REGISTRYRECOVERYAMMOUNT = 20;
	int i, op, optout = 0, remove_ammount, search_admission, search_found;
	FILE *name_list, *GEN_output;
	Registry *regs, remove_admission[100], search_return;
	Page_Pointer root;

	regs = (Registry*) malloc(REGISTRYRECOVERYAMMOUNT*sizeof(Registry));

	srand(time(NULL));
	BTREE_INIT(&root);

	STATS_RESET();

	//OPERATION MANAGER
	OPSELECT(REGISTRYRECOVERYAMMOUNT);

	while(!optout){
		printf("OP: ");
		scanf("%d", &op);

		switch(op){
			case 0: optout = 1; break;
			case 1:
				system("cls");

				free(regs);
				printf("Novo valor de X: ");
				scanf("%d", &REGISTRYRECOVERYAMMOUNT);

				system("cls");

				regs = (Registry*) malloc(REGISTRYRECOVERYAMMOUNT*sizeof(Registry));

				OPSELECT(REGISTRYRECOVERYAMMOUNT);
				putchar('\n');
				printf("DONE\n");
				putchar('\n');
				break;
			case 2:
				system("cls");

				OPSELECT(REGISTRYRECOVERYAMMOUNT);

				name_list = fopen("registry/names_database.txt", "r");
				REGEN_GEN(&name_list);
				fclose(name_list);

				GEN_output = fopen("registry/registries_generated.txt", "r");
				REG_FSCAN(&GEN_output, regs, REGISTRYRECOVERYAMMOUNT);
				fclose(GEN_output);

				putchar('\n');
				printf("DONE\n");
				putchar('\n');
				break;
			case 3:
				system("cls");
				for(i=0; i<REGISTRYRECOVERYAMMOUNT; i++){
					REG_PRINT(regs[i]);
					putchar('\n');
				}
				printf("\n");
				OPSELECT(REGISTRYRECOVERYAMMOUNT);
				printf("\n");
				break;
			case 4:
				system("cls");
				OPSELECT(REGISTRYRECOVERYAMMOUNT);
				for(i=0; i<REGISTRYRECOVERYAMMOUNT; i++){
					BTREE_INSERT(regs[i], &root);
				}
				putchar('\n');
				printf("DONE\n");
				putchar('\n');
				break;
			case 5:
				system("cls");
				printf("Digite o numero de admissao: ");
				scanf("%d", &search_admission);
				search_return.admission_number = search_admission;
				BTREE_SEARCH(&search_return, root, &search_found);

				OPSELECT(REGISTRYRECOVERYAMMOUNT);
				putchar('\n');
				if(search_found) REG_PRINT(search_return);
				putchar('\n');
				break;
			case 6:
				system("cls");
				printf("Digite o numero de registros que deseja remover: ");
				scanf("%d", &remove_ammount);
				printf("Digite o(s) registro(s) que deseja remover, separe-os por espacos\nRegistros: ");

				for(i=0; i<remove_ammount; i++){
					scanf("%d", &remove_admission[i].admission_number);
				}

				for(i=0; i<remove_ammount; i++){
					BTREE_REMOVE(remove_admission[i], &root);
				}

				OPSELECT(REGISTRYRECOVERYAMMOUNT);
				putchar('\n');
				printf("DONE\n");
				putchar('\n');
				break;
			case 7:
				system("cls");
				OPSELECT(REGISTRYRECOVERYAMMOUNT);
				putchar('\n');
				printf("Height: %li\n", BTREE_HEIGHT(&root));
				putchar('\n');
				break;
			case 8:
				system("cls");
				OPSELECT(REGISTRYRECOVERYAMMOUNT);
				putchar('\n');
				STATS_PRINT();
				putchar('\n');
				break;
			default:
				system("cls");
				OPSELECT(REGISTRYRECOVERYAMMOUNT);
				printf("Invalid Operation\n\n");
				break;
		}
	}
	system("PAUSE");
	return 0;
}

void OPSELECT(int REGISTRYRECOVERYAMMOUNT){
	printf("Please, select one of the following operations:\n    1. Definir X (Padrao 20)\n    2. Gerar X = %d registros\n    3. Listar X = %d Registros\n    4. Inserir X = %d registros na arvore\n    5. Pesquisar um registro\n    6. Remover registro(s)\n    7. Exibir altura da arvore\n    8. Verificar numero de acessos ao disco e comparacoes\n    0. EXIT\n", REGISTRYRECOVERYAMMOUNT,  REGISTRYRECOVERYAMMOUNT, REGISTRYRECOVERYAMMOUNT);
}