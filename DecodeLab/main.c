#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void getCode(char codeKey[]);
void getMessage(int message[]);
void sortMessage(int message[]);
void decodeMessage(char codeKey[], int message[]);

int main(void) {
	char codeKey[53] = {0};
	int message[MAX];
	int i;

	for (i = 0; i < MAX; i++) { //sentinel values into array
		message[i] = -1;
	}

	getCode(codeKey);
	getMessage(message);
	sortMessage(message);
	decodeMessage(codeKey, message);


	getchar(); getchar(); getchar();
	return 0;
}

void getCode(char codeKey[]) {
	int i, c;

	FILE *fp;
	if (!(fp = fopen("codefile.txt", "r"))) {
		printf("codefile.txt could not be opened for input.");
		getchar(); //debug added so it actually gives user time to read in MVS
		exit(1);
	}

	while ((c = getc(fp)) != EOF) { 

		for (i = 0; i < 53; i++) {
			fscanf_s(fp,"%c", &codeKey[i], 5); //Needs whitespace in input file to write to [0] correctly...?
			//codeKey[i] = fgetc(fp); No difference in correcting whitespace issue
			
		}
		for (i = 0; i < 53; i++) {//DEBUG
			printf("[%d]=%c ", i, codeKey[i]);
		}
		printf("\n\n");
	}
	//fclose(fp);
}

void getMessage(int message[]) {
	int i, c;

	FILE *fp;
	if (!(fp = fopen("msgfile.txt", "r"))) {
		printf("msgfile.txt could not be opened for input.");
		getchar(); //debug added so it actually gives user time to read in MVS
		exit(1);
	}

	while ((c = getc(fp)) != EOF) { //within msg file

		for (i = 0; i < MAX; i++) {
			fscanf_s(fp,"%d", &message[i]);

		}

		for (i = 0; i < MAX; i++) { //DEBUG
			if (message[i] != -1)
			printf("[%d]=%d ", i, message[i]);
		}
	}
	//fclose(fp);
}

void sortMessage(int message[]) {
	int i, j, temp;

	for (i = 1; i < MAX; i++) {
		if (message[i] != -1) {
			temp = message[i];
			j = i - 1;
			while (j >= 0 && temp < message[j]) {
				message[j + 1] = message[j];
				j = j - 1;
			}
			message[j + 1] = temp;
		}
	}
	printf("\n\n");
	for (i = 0; i < MAX; i++) { //DEBUG
		if (message[i] != -1) {
			printf("[%d]=%d ", i, message[i]);
		}
	}
}

void decodeMessage(char codeKey[], int message[]) {
	int i;

	for (i = 0; i < MAX; i++) {
		if (message[i] != -1) {
			message[i] = message[i] % 100;
		}
	}

	printf("\n\n");

	for (i = 0; i < MAX; i++) {
		if (message[i] != -1) {
			printf("%c", codeKey[message[i]]);
		}
	}
}