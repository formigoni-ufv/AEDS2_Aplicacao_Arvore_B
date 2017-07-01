#include <stdio.h>
#include <string.h>
#include "registry.h"

void REG_PRINT(Registry reg){
	printf("Admission Number: %d\nName            : %s\nAdmission Date  : %s\nAge             : %d\nOccupation      : %s\nCivil           : %s\n", reg.admission_number, reg.name, reg.admission_date, reg.age, reg.occupation, reg.civil_status);
}

void REG_FPRINT(FILE** output, Registry reg){
	fprintf(*output, "Admission Number: %d\nName            : %s\nAdmission Date  : %s\nAge             : %d\nOccupation      : %s\nCivil           : %s\n", reg.admission_number, reg.name, reg.admission_date, reg.age, reg.occupation, reg.civil_status);
}

void REG_FSCAN(FILE** input, Registry registries[], long numberToBeRead){
	long i;
	char temp[30];

	for(i=0; i<numberToBeRead; i++){
		fscanf(*input, "Admission Number: %d\n", &((registries[i])).admission_number);

		fscanf(*input, "Name            : %s", ((registries[i])).name);
		fscanf(*input, "%s\n", temp);
		strcat((registries[i]).name, " ");
		strcat((registries[i]).name, temp);

		fscanf(*input, "Admission Date  : %s\n", ((registries[i])).admission_date);

		fscanf(*input, "Age             : %d\n", &((registries[i])).age);

		fscanf(*input, "Occupation      : %s\n", ((registries[i])).occupation);

		fscanf(*input, "Civil           : %s\n", ((registries[i])).civil_status);
	}
}
