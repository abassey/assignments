/* Anemmeabasi Bassey
abassey@uoguelph.ca
Question 5 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void oneTable(int userNum) {
int multTable[9][9] = {{1,2,3,4,5,6,7,8,9}, {2,4,6,8,10,12,14,16,18}, {3,6,9,12,15,18,21,24,27}, {4,8,12,16,20,24,28,32,36}, {5,10,15,20,25,30,35,40,45}, {6,12,18,24,30,36,42,48,54}, {7,14,21,28,35,42,49,56,63}, {8,16,24,32,40,48,56,64,72}, {9,18,27,36,45,54,63,72,81}};

		printf("Printing multiplication table for %d: \n", userNum);
		printf("-------------------------------------\n");
		for (int k = 1; k <= 9; ++k) {
			printf("%d X %d = %d\n", userNum, k, multTable[userNum - 1][k - 1]);
		}
		printf("\n");

	return;
}

void allTables() {
	int multTable[9][9] = {{1,2,3,4,5,6,7,8,9}, {2,4,6,8,10,12,14,16,18}, {3,6,9,12,15,18,21,24,27}, {4,8,12,16,20,24,28,32,36}, {5,10,15,20,25,30,35,40,45}, {6,12,18,24,30,36,42,48,54}, {7,14,21,28,35,42,49,56,63}, {8,16,24,32,40,48,56,64,72}, {9,18,27,36,45,54,63,72,81}};
	char numVert[10][10] = {"One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
	printf("          Printing Multiplication Tables From 1 - 9\n");

			for (int v = 0; v < 81; ++v){
				printf("*");
			}
	printf("\n");
	printf("\tOne\tTwo\tThree\tFour\tFive\tSix\tSeven\tEight\tNine\n");
			for (int i = 0; i < 9; ++i){

				for (int j = 0; j < 9; ++j){
					if(numVert[i][j] == '\0'){
						printf("\n");
					} else {
						printf("%c", numVert[i][i]);
					}
					printf("\t");
					if (multTable[i][j] < 10){
						printf("  %d  ", multTable[i][j]);
					} else {
						printf("  %d ", multTable[i][j]);
					}
				}
					printf("\n");
			}

			for (int u = 0; u < 81; ++u){
				printf("*");
			}
	printf("\n");
}


int main () {
	int userNum = 0;
	char userChoice = ' ';

	printf("Enter zero (0) to see all multiplication tables from 1 - 9 OR \n Enter a specfic number bewteen 1 and 9 to see its multiplication table \n");
	printf("Enter a choice: ");
	scanf("%d", &userNum);
	printf("\n");

 	if (userNum > 0) {
		oneTable(userNum);
	}
	if (userNum == 0) {
		allTables();
	}

	printf("Do you wish to continue? Enter y for yes, any other character for no: ");
	scanf(" %c", &userChoice);

	if (userChoice != 'y'){
		printf("Good Bye.\n");
	}

	do {
		printf("Enter zero (0) to see all multiplication tables from 1 - 9 OR \n Enter a specfic number bewteen 1 and 9 to see its multiplication table \n");
		printf("Enter a choice: ");
		scanf("%d", &userNum);
		printf("\n");

		if (userNum > 0) {
			oneTable(userNum);
		}

		if (userNum == 0){
			allTables();
		}

		printf("Do you wish to continue? Enter y for yes, any other character for no: ");
		scanf(" %c", &userChoice);
		printf("\n");
	} while (userChoice == 'y');

 		if (userChoice != 'y'){
			printf("Good Bye.\n");
		}
	return 0;
}
