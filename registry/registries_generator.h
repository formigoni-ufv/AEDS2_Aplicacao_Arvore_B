/*****************************************
Alunos: Ruan Evangelista Formigoni - 2661
        Matheus da Silva Alves - 2649
******************************************/

#ifndef AEDS2_APLICACAO_ARVORE_B_REGISTRIES_HANDLER_H
#define AEDS2_APLICACAO_ARVORE_B_REGISTRIES_HANDLER_H
#include <stdio.h>
#include "registry.h"
#define NAMESSCANNED 10000

void REGEN_GEN(FILE** input, int* admission_number_vector[]);
void REGEN_DATE(char* date);
int REGEN_AGE();
void REGEN_OCSTATUS(char* occupation);
void REGEN_CIVIL(char* status);

#endif //AEDS2_APLICACAO_ARVORE_B_REGISTRIES_HANDLER_H
