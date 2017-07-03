#include <stdio.h>
#include <string.h>
#include "statistic.h"

void STATS_RESET(){
	FILE* disk;
	disk = fopen("statistic.txt", "w");
	fprintf(disk, "Reads: 0\nWrites: 0\nComparisons: 0\n");
	fclose(disk);
}

void STATS_PRINT(){
	FILE* stats;
	int read_amount, write_amount, comparisons_amount;
	char dummy[13];

	stats = fopen("statistic.txt", "r");
	fscanf(stats, "%s %d %s %d %s %d", dummy, &read_amount, dummy, &write_amount, dummy, &comparisons_amount);
	fclose(stats);

	printf("Reads: %d\nWrites: %d\nComparisons: %d\n", read_amount, write_amount, comparisons_amount);
}

int STATS_SCAN(char selection){
	FILE* stats;
	int read_amount, write_amount, comparisons_amount;
	char dummy[13];

	stats = fopen("statistic.txt", "r");
	fscanf(stats, "%s %d %s %d %s %d", dummy, &read_amount, dummy, &write_amount, dummy, &comparisons_amount);
	fclose(stats);

	if(selection == 'r'){
		return read_amount;
	}else if(selection == 'w'){
		return write_amount;
	}else{
		return comparisons_amount;
	}
}

void STATS_DISKREAD(int* isRoot){
	FILE* stats;
	int read_amount, write_amount, comparisons_amount;
	char dummy[13];

	if(isRoot != NULL){
		if(*isRoot) return;
	}

	stats = fopen("statistic.txt", "r");
	fscanf(stats, "%s %d %s %d %s %d", dummy, &read_amount, dummy, &write_amount, dummy, &comparisons_amount);
	fclose(stats);

	read_amount++;

	stats = fopen("statistic.txt", "w");
	fprintf(stats, "Reads: %d\nWrites: %d\nComparisons: %d\n", read_amount, write_amount, comparisons_amount);
	fclose(stats);
}

void STATS_DISKWRITE(int* isRoot){
	FILE* stats;
	int read_amount, write_amount, comparisons_amount;
	char dummy[13];

	if(isRoot != NULL){
		if(*isRoot) return;
	}

	stats = fopen("statistic.txt", "r");
	fscanf(stats, "%s %d %s %d %s %d", dummy, &read_amount, dummy, &write_amount, dummy, &comparisons_amount);
	fclose(stats);

	write_amount++;

	stats = fopen("statistic.txt", "w");
	fprintf(stats, "Reads: %d\nWrites: %d\nComparisons: %d\n", read_amount, write_amount, comparisons_amount);
	fclose(stats);
}

void STATS_COMPARISON(){
	FILE* stats;
	int read_amount, write_amount, comparisons_amount;
	char dummy[13];

	stats = fopen("statistic.txt", "r");
	fscanf(stats, "%s %d %s %d %s %d", dummy, &read_amount, dummy, &write_amount, dummy, &comparisons_amount);
	fclose(stats);

	comparisons_amount++;

	stats = fopen("statistic.txt", "w");
	fprintf(stats, "Reads: %d\nWrites: %d\nComparisons: %d\n", read_amount, write_amount, comparisons_amount);
	fclose(stats);
}