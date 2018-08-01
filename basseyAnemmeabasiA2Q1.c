/* Anemmeabasi Bassey
abassey@uoguelph.ca
Question 1 */

#include <stdio.h>

int main () {
	int numLines, numWidth = 0;

	printf("Number of lines? ");
	scanf("%d", &numLines);
	printf("Width between left and right figure? ");
	scanf("%d", &numWidth);

	printf("\n");

	//top half
	for (int i = 1; i <= numLines / 2; ++i) {
		for (int h = i; h < numLines / 2; ++h){
			printf(" ");
		}
		for (int h = 1; h <= i; ++h) {
			printf("*");
		}
		for (int j = 1; j <= numWidth; ++j) {
			if(i == numLines / 2){
				printf("_");
			} else {
			printf(" ");
			}
		}
		for (int g = 0; g < i; ++g) {
			printf("*");
		}
		printf("\n");
	}

	//bottom half
	for (int k = numLines / 2; k >= 1; --k) {
		for (int y = numLines / 2; y >  k; --y) {
			printf(" ");
		}

		for (int y = 0; y <  k; ++y){
			printf("*");
		}

		for (int n = 1; n <= numWidth; ++n) {
			if (k == numLines / 2){
				printf("_");
			} else {
			printf(" ");
			}
		}
		for(int f = k; f >= 1; --f) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n");
	return 0;
}
