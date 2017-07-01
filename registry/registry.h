#ifndef AEDS2_APLICACAO_ARVORE_B_REGISTRY_H
#define AEDS2_APLICACAO_ARVORE_B_REGISTRY_H
#define NAME_LENGTH 30
#define OC_LENGTH 11
#define CIVILSTAT_LENGTH 32
#define ADMISSDATE_LENGTH 11

typedef struct{
	int admission_number;
	char name[NAME_LENGTH];
	char admission_date[ADMISSDATE_LENGTH];
	int age;
	char occupation[OC_LENGTH];
	char civil_status[CIVILSTAT_LENGTH];
}Registry;

void REG_PRINT(Registry reg);
void REG_FPRINT(FILE** output, Registry reg);
void REG_FSCAN(FILE** input, Registry registries[], long numberToBeRead);

#endif //AEDS2_APLICACAO_ARVORE_B_REGISTRY_H
