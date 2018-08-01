#include <stdio.h>

// function prototypes here

int main(){
    
	printf("percentage(5.5, 8) - expected output: %.2f\n", 68.75); 
	printf("percentage(5.5, 8) - actual output: %.2f\n", percentage(5.5, 8));
	
    printf("contribution(5.5, 8, 5) - expected output: %.2f\n", 3.44);
	printf("contribution(5.5, 8, 5) - actual output: %.2f\n",contribution(5.5, 8, 5));
	
	/* 
	Test other functions similarly. 
	You must test with different inputs. 
	Your functions must work for any input - not just the ones 
	given as examples in the assignment
	*/
	
    return 0;
}

//function definitions here 

