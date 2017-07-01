#ifndef AEDS2_APLICACAO_ARVORE_B_REGISTRIES_HANDLER_H
#define AEDS2_APLICACAO_ARVORE_B_REGISTRIES_HANDLER_H
#include <stdio.h>
#include "registry.h"
#define REGSTOBESCANNED 10000

void REGEN_GEN(FILE** input);
void REGEN_DATE(char* date);
int REGEN_AGE();
void REGEN_OCSTATUS(char* occupation);
void REGEN_CIVIL(char* status);

#endif //AEDS2_APLICACAO_ARVORE_B_REGISTRIES_HANDLER_H
