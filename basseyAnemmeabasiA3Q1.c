/* Anemmeabasi Bassey, 1032523
abassey@uoguelph.ca
Question 1 */

#include <stdio.h>

// function prototypes here
float percentage(float actualMark, float maxPossible);
float contribution(float actualMark, float maxPossible, float weightage);
float assignmentContribution(float assnOne, float assnTwo, float assnThree);
float dailyPracticeContribution(float daily[11]);
float labContribution(float lab[9], float examOne, float examTwo);
float totalTermMark(float assnSum, float labSum, float dailySum);
float finalMarkRequired(float totalMark, float desiredMark); 

//function definitions here
//working
//actual over max times 100
float percentage(float actualMark, float maxPossible){
	float percent = 0.0;
	percent = (actualMark / maxPossible) * 100;
	return percent;
}
//working
//actual divided by max times weightage
float contribution(float actualMark, float maxPossible, float weightage){
	float contr = 0.0;
	contr = (actualMark / maxPossible) * weightage;
	return contr;
}
//working
//raw contibution for each, then return the sum
float assignmentContribution(float assnOne, float assnTwo, float assnThree){
	float assignContr = 0.0;
	assignContr = ((assnOne / 50) * 5) + ((assnTwo / 60) * 10) + ((assnThree / 60) * 10);
	return assignContr;
}
//working
//average of top ten marks
float dailyPracticeContribution(float daily[11]){
	float minDaily = daily[0];
	float sumDaily = 0.0;
	float avgDaily = 0.0;

	for(int i = 0; i < 11; ++i){
		if(minDaily > daily[i]){
			minDaily = daily[i];
		}
		sumDaily = sumDaily + daily[i];
	}

	sumDaily = sumDaily - minDaily;
	avgDaily = sumDaily / 10;
	return avgDaily;
}
//working
//sum up the lab marks, then use this to calculate the raw contirbution total
float labContribution(float lab[9], float examOne, float examTwo){
	float labSum = 0.0;
	float labContrTotal = 0.0;

	for(int j = 0; j < 9; ++j){
		labSum = labSum + lab[j];
	}

	labContrTotal = ((labSum / 9) * 10) + ((examOne / 50) * 10) + ((examTwo / 50) * 10);
	return labContrTotal;
}
//working
//if perfect, add 5. else, sum all input
float totalTermMark(float assnSum, float labSum, float dailySum){
	float sumTotal = 0.0;
	sumTotal = assnSum + labSum + dailySum;

	if(sumTotal == 65){
		sumTotal += 5;
		return sumTotal;
	} else {
		return sumTotal;
	}
}
//working
//difference of tM and dM and divide by 35 = percentage
float finalMarkRequired(float totalMark, float desiredMark) {
	float markDifference = 0.0;
	float requiredPercent = 0.0;

	markDifference = totalMark - desiredMark;
	requiredPercent = (markDifference / 35) * 100 * -1;
	return requiredPercent;
}
