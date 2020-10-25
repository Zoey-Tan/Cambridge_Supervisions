#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <math.h>
#define N 100000
 
int main(void) {

	int numArray[N],squareArray[N]; // Define an array of four integers
    
    // Use current time as seed for rand()
    srand(time(0));
	// Get inputs for the array elements
	for (int i=0;i<N; i++) {
    	numArray[i] = rand() % 4 + 1; // Generate random integer between 1 and 4
	}
	
	int sum = 0;
	
	for(int i=0;i<N;i++){
	   // Calculate individual squares
	   squareArray[i] = pow(numArray[i],2);
	   // Add the squared integers
	   sum += squareArray[i];
	  
	}
   
	printf("%d\n",sum);  // Print the sum
	return 0;

	//Time: 0.176s
}
