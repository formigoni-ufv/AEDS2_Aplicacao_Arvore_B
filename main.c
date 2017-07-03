/*****************************************
Alunos: Ruan Evangelista Formigoni - 2661
        Matheus da Silva Alves - 2649
******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "b_tree.h"
#include "graph/graph_generator.h"
#include "registry/registries_generator.h"
#include "statistic.h"
#include "registry/registry.h"

void OPSELECT(int REGISTRYRECOVERYAMMOUNT);

int main(){
	int *admission_number_vector = NULL;
	int REGISTRYRECOVERYAMOUNT = 10000;
	int reg_counter = 0, search_counter = 0;
	int i, op, optout = 0, remove_ammount, search_amount, search_buffer, search_found;
	FILE *name_list, *GEN_output;
	Registry *regs, remove_admission[10000], search_admission[10000], search_return;
	Page_Pointer root;

	regs = (Registry*) malloc(REGISTRYRECOVERYAMOUNT*sizeof(Registry));

	srand(time(NULL));
	BTREE_INIT(&root);

	GRAPH_DATA_RESET();
	STATS_RESET();

	//OPERATION MANAGER
	OPSELECT(REGISTRYRECOVERYAMOUNT);

	while(!optout){
		printf("OP: ");
		scanf("%d", &op);

		switch(op){
			case 0: optout = 1; break;
			case 1:
				system("cls");

				free(regs);
				printf("Novo valor de X: ");
				scanf("%d", &REGISTRYRECOVERYAMOUNT);

				system("cls");

				regs = (Registry*) malloc(REGISTRYRECOVERYAMOUNT*sizeof(Registry));

				OPSELECT(REGISTRYRECOVERYAMOUNT);
				putchar('\n');
				printf("DONE\n");
				putchar('\n');
				break;
			case 2:
				system("cls");

				OPSELECT(REGISTRYRECOVERYAMOUNT);

				name_list = fopen("registry/names_database.txt", "r");
				REGEN_GEN(&name_list, &admission_number_vector);
				fclose(name_list);

				GEN_output = fopen("registry/registries_generated.txt", "r");
				REG_FSCAN(&GEN_output, regs, REGISTRYRECOVERYAMOUNT);
				fclose(GEN_output);

				putchar('\n');
				printf("DONE\n");
				putchar('\n');
				break;
			case 3:
				system("cls");
				for(i=0; i<REGISTRYRECOVERYAMOUNT; i++){
					REG_PRINT(regs[i]);
					putchar('\n');
				}
				printf("\n");
				OPSELECT(REGISTRYRECOVERYAMOUNT);
				printf("\n");
				break;
			case 4:
				system("cls");
				OPSELECT(REGISTRYRECOVERYAMOUNT);
				for(i=0; i<REGISTRYRECOVERYAMOUNT; i++){

					BTREE_INSERT(regs[i], &root);

					reg_counter++;
					if(reg_counter%GRAPHSTEP == 0){
						GRAPH_ADDLINE(reg_counter);
					}

				}
				putchar('\n');
				printf("DONE\n");
				putchar('\n');
				break;
			case 5:
				system("cls");
				printf("Digite o numero de admissao: ");
				scanf("%d", &search_buffer);
				search_return.admission_number = search_buffer;
				BTREE_SEARCH(&search_return, root, &search_found);

				OPSELECT(REGISTRYRECOVERYAMOUNT);
				putchar('\n');
				if(search_found) REG_PRINT(search_return);
				putchar('\n');
				break;
			case 6:
				system("cls");
				printf("Digite o numero de registros a serem pesquisados: ");
				scanf("%d", &search_amount);
				if(search_amount > reg_counter){
					OPSELECT(REGISTRYRECOVERYAMOUNT);
					putchar('\n');
					printf("Numero inserido é maior que o numero de registros na arvore.\n");
					putchar('\n');
					break;
				}else{
					for(i=0; i<search_amount; i++){
						search_admission[i].admission_number = admission_number_vector[i];
					}

					for(i=0; i<search_amount; i++){
						BTREE_SEARCH(&search_admission[i], root, &search_found);

						search_counter++;

						if(i==0){
							GRAPH_DATA_RESET();
						}else if(search_counter%GRAPHSTEP == 0){
							GRAPH_ADDLINE(search_counter);
						}
					}

					search_counter = 0;

					OPSELECT(REGISTRYRECOVERYAMOUNT);
					putchar('\n');
					printf("DONE\n");
					putchar('\n');
				}
				break;
			case 7:
				system("cls");
				printf("Digite o numero de registros que deseja remover: ");
				scanf("%d", &remove_ammount);
				printf("Digite o(s) registro(s) que deseja remover, separe-os por espacos\nRegistros: ");

				for(i=0; i<remove_ammount; i++){
					scanf("%d", &remove_admission[i].admission_number);
				}

				for(i=0; i<remove_ammount; i++){
					BTREE_REMOVE(remove_admission[i], &root);
					reg_counter--;
				}

				OPSELECT(REGISTRYRECOVERYAMOUNT);
				putchar('\n');
				printf("DONE\n");
				putchar('\n');
				break;
			case 8:
				system("cls");
				printf("Digite o numero de registros que deseja remover: ");
				scanf("%d", &remove_ammount);

				if(remove_ammount > reg_counter){
					OPSELECT(REGISTRYRECOVERYAMOUNT);
					putchar('\n');
					printf("Numero inserido é maior que o numero de registros na arvore.\n");
					putchar('\n');
				}else{
					for(i=0; i<remove_ammount; i++){
						remove_admission[i].admission_number = admission_number_vector[i];
					}

					for(i=0; i<remove_ammount; i++){
						BTREE_REMOVE(remove_admission[i], &root);
						reg_counter--;

						if(i == 0){
							GRAPH_DATA_RESET();
						}else if((i+1)%GRAPHSTEP == 0){
							GRAPH_ADDLINE(reg_counter);
						}
					}
				}

				OPSELECT(REGISTRYRECOVERYAMOUNT);
				putchar('\n');
				printf("DONE\n");
				putchar('\n');
				break;
			case 9:
				system("cls");
				OPSELECT(REGISTRYRECOVERYAMOUNT);
				putchar('\n');
				printf("Height: %li\n", BTREE_HEIGHT(&root));
				putchar('\n');
				break;
			case 10:
				system("cls");
				OPSELECT(REGISTRYRECOVERYAMOUNT);
				putchar('\n');
				STATS_PRINT();
				putchar('\n');
				break;
			case 11:
				system("cls");
				OPSELECT(REGISTRYRECOVERYAMOUNT);
				GRAPH_GEN();
				putchar('\n');
				printf("DONE\n");
				putchar('\n');
				break;
			case 12:
				system("cls");
				OPSELECT(REGISTRYRECOVERYAMOUNT);
				STATS_RESET();
				GRAPH_DATA_RESET();
				putchar('\n');
				printf("DONE\n");
				putchar('\n');
				break;
			case 13:
				system("cls");
				OPSELECT(REGISTRYRECOVERYAMOUNT);
				printf("\nNumero de Registros na arvore: %d\n", reg_counter);
				putchar('\n');
				printf("DONE\n");
				putchar('\n');
				break;
			default:
				system("cls");
				OPSELECT(REGISTRYRECOVERYAMOUNT);
				printf("Invalid Operation\n\n");
				break;
		}
	}
	system("PAUSE");
	return 0;
}

void OPSELECT(int REGISTRYRECOVERYAMMOUNT){
	printf("Please, select one of the following operations:\n    1. Definir X\n    2. Gerar X = %d registros\n    3. Listar X = %d Registros\n    4. Inserir X = %d registros na arvore\n    5. Pesquisar um registro\n    6. Pesquisar N registros aleatorios\n    7. Remover registro(s)\n    8. Remover N registros aleatorios\n    9. Exibir altura da arvore\n    10.Verificar numero de acessos ao disco e comparacoes\n    11.Gerar Grafico\n    12.Limpar dados do arquivo de estatistica\n    13.Exibir numero de registros na arvore\n    0. EXIT\n", REGISTRYRECOVERYAMMOUNT,  REGISTRYRECOVERYAMMOUNT, REGISTRYRECOVERYAMMOUNT);
}