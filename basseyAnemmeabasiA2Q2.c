/* Anemmeabasi Bassey
abassey@uoguelph.ca
Question 2 */

#include <stdio.h>

int main () {

	double population[10];
	int j = 0;
	double avg, max, min = 0.0;
	int minLocation, maxLocation = 0;

	printf("Enter the population of 10 provinces of Canada (in million): \n");
	for(int i = 0; i < 10; ++i) {
		++j;
		printf("Province number %d: ", j);
		scanf("%lf",&(population[i]));
	}

	max = population[0];
	min = population[0];

	for(int k = 0; k < 10; ++k) {
		avg = avg + population[k];
		if (population[k] > max) {
			max = population[k];
			maxLocation = k + 1;
		} else if (min > population[k]) {
			min = population[k - 1];
			minLocation = k + 1;
		}
	}

	printf("The average population size is: %.2lf million\n", avg);
	printf("Province number %d has the highest population\n", maxLocation);
	printf("Highest population: %.2lf million\n", max);
	printf("Province number %d has the lowest population\n", minLocation);
	printf("Lowest population: %.2lf million\n", min);
	return 0;
}
