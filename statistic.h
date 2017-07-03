/*****************************************
Alunos: Ruan Evangelista Formigoni - 2661
        Matheus da Silva Alves - 2649
******************************************/

#ifndef AEDS2_APLICACAO_ARVORE_B_DISKRW_H
#define AEDS2_APLICACAO_ARVORE_B_DISKRW_H

void STATS_RESET();
void STATS_PRINT();
int STATS_SCAN(char selection);
void STATS_DISKREAD(int* isRoot);
void STATS_DISKWRITE(int* isRoot);
void STATS_COMPARISON();

#endif //AEDS2_APLICACAO_ARVORE_B_DISKRW_H
