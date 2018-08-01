/* Anemmeabasi Bassey
abassey@uoguelph.ca
Question 3 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main () {
	char sentence[50];
	int vowelCnt, consonantCnt, charCnt, spaceCnt = 0;
	double avgLen = 0.0;


	printf("Enter a sentence: ");
	fgets(sentence, 50, stdin);

	for (int i = 0; i < strlen(sentence); ++i) {
		if (sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u') {
			++vowelCnt;
		} else if (!(isspace(sentence[i]))){
			++consonantCnt;
		}

		if (isspace(sentence[i])) {
			if(sentence[i + 1] == ' '){
				continue;
			}
			++spaceCnt; //words are divided by spaces
		}
	}


	charCnt  = (strlen(sentence)) - spaceCnt;
	avgLen = charCnt / spaceCnt;

	printf("Number of vowels in sentence: %d\n", vowelCnt);
	printf("Number of consonants in the sentence: %d\n", consonantCnt);
	printf("Average word length: %.1lf\n", avgLen);
	return 0;
}
