#include <stdlib.h>
#include <string.h>
#include "registries_generator.h"
#include "registry.h"

void REGEN_GEN(FILE** input){
	int i;
	Registry reg;
	int admission_number = 1;
	char name0[NAME_LENGTH], name1[NAME_LENGTH];
	char admission_date[ADMISSDATE_LENGTH];
	char occupation[OC_LENGTH];
	char status[CIVILSTAT_LENGTH];

	FILE* output = fopen("registry/registries_generated.txt", "wt");

	for(i=0; i<REGSTOBESCANNED; i++){
		//ADMISSION NUMBER
		reg.admission_number = admission_number;
		admission_number++;

		//NAME
		fscanf(*input, "%s %s", name0, name1);
		strcpy(reg.name, strcat(name0, " "));
		strcat(reg.name, name1);

		//ADMISSION DATE
		REGEN_DATE(admission_date);
		strcpy(reg.admission_date, admission_date);

		//AGE
		reg.age = REGEN_AGE();

		//OCCUPATION
		REGEN_OCSTATUS(occupation);
		strcpy(reg.occupation, occupation);

		//CIVIL
		REGEN_CIVIL(status);
		strcpy(reg.civil_status, status);

		//PRINT
//		REG_PRINT(reg);
//		putchar('\n');
		REG_FPRINT(&output, reg);
	}

	fclose(output);
}

void REGEN_DATE(char* DDMMYY){
	char day[3], month[3], year[5];
	itoa(rand()%29, day, 10);
	itoa(1+(rand()%12), month, 10);
	itoa(2015+(rand()%3), year, 10);

	strcpy(DDMMYY, day);
	strcat(DDMMYY, "/");
	strcat(DDMMYY, month);
	strcat(DDMMYY, "/");
	strcat(DDMMYY, year);
}

int REGEN_AGE(){
	return 10 + (rand()%75);
}

void REGEN_OCSTATUS(char* occupation){
	int oc;
	oc = rand()%3;

	switch(oc){
		case 0:  strcpy(occupation, "Unemployed"); break;
		case 1:  strcpy(occupation, "Employed"); break;
		default: strcpy(occupation, "Retired"); break;
	}
}

void REGEN_CIVIL(char* status){
	int civ;
	civ = rand()%4;

	switch(civ){
		case 0:  strcpy(status, "Single"); break;
		case 1:  strcpy(status, "Married"); break;
		case 2:  strcpy(status, "Widow(er)"); break;
		default: strcpy(status, "MARRIED_TO_AN_APACHE_HELICOPTER"); break;
	}
}