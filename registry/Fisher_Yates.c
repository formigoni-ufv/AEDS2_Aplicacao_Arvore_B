#include <stdio.h>
#include <stdlib.h>
#include "Fisher_Yates.h"

void FY_Shuffle(int* vector[], int TAM){
	int i, r, temp, max = TAM;

	*vector = (int*) malloc(max*sizeof(int));

	for(i=0; i<max; i++){
		(*vector)[i] = i;
	}

	do{
		r = rand()%max;

		temp = (*vector)[r];
		(*vector)[r] = (*vector)[max-1];
		(*vector)[max-1] = temp;

		max--;
	}while(max > 0);
}