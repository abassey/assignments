/* Anemmeabasi Bassey
abassey@uoguelph.ca
Question 4 */

#include <stdio.h>
#include <string.h>

int main () {
	int goodnessCnt = 0;
	char str[50];

	printf("Enter a string with no spaces: ");
	fgets(str, 50, stdin);

	for (int i = 0; i < strlen(str) - 1; ++i) {
		if (!(str[i] == '0' || str[i] == '1')) {
			goodnessCnt = 0;
		} else {
			if (str[i] == '1') {
				++goodnessCnt;
			}
		}
	}

	printf("Goodness of the input string is %d\n", goodnessCnt);

	return 0;
}
