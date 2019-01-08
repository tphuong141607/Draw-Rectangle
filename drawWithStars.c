/** A program that asks the user to input a number n. It will then
 *  generate the following outputs.
 *  Example: if input n is 3, we will get:
 *
 *  *	       *	   *
 *	**	      **	  ***
 *	***	     ***	 *****
 *
 *  Created by Thao Phuong, 1/31/2018
 */

#include <stdio.h>

void printArray(int r, int c, char array[r][c]);
void initiateValue(int r, int c, char array[r][c]);

int main() {
	int number;
	printf("Please enter an integer number: ");
	scanf("%d", &number);
	
	int colArray2 = number * 2 - 1;
	char array[number][number];
	char array2[number][colArray2];

	//  *
	//  **
	//  ***
	//  ****
	initiateValue(number, number, array);
	for(int row = number-1; row >= 0; row--) {
		for(int column = 0; column <= row; column++) {
			array[row][column] = '*';
		}
	}
	printArray(number, number, array);

	   
	//      *
	//     **
	//    ***
	//   ****
	initiateValue(number, number, array);
	for(int column = number-1; column >= 0; column--) {
		for(int row = number; row >= number - column; row--) {
			array[row - 1][column] = '*';
		}
	}
	printArray(number, number, array);
	

	//      *
	//     ***
	//    *****
	//   *******
	initiateValue(number, colArray2, array2);
	int k = 0; 
	for(int row = number-1; row >= 0; row--) {
		for(int column = 0 + k; column < colArray2 - k; column++) {
			array2[row][column] = '*';
		}
		k++;
	}
	printArray(number, colArray2, array2);

	return 0;
}

void initiateValue(int r, int c, char array[r][c]) {	
	for(int row = 0; row < r; row++) {
			for(int column = 0; column < c; column++) {
				array[row][column] = ' ';
			}
	}
}

void printArray(int r, int c, char array[r][c]) {
	printf("\n");
	for(int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%c", array[i][j]);
		}
		printf("\n");
	}
}











