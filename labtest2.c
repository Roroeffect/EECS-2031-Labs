#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

int main(int argc, char *argv[]) {

	FILE *input;

	// There should be 1 argument passed to the main function
	if (argc < 2) {
		printf("You should enter the input and output files and a search phrase. Example:\n");
		printf("labtest2 labtest2_makeup.in \n");
		exit(1);
	}

	// Check the input file
	input = fopen(argv[1], "r");
	if (input == NULL) {
		printf("File \"%s\" can not be opened for reading.\n", argv[1]);
		exit(1);
	}

	// Step 1 : 1 point
	printf("This message shows that the code is compiled and run correctly for Step 1\n");

	// make an empty list
	// Step 2: 1 point
	List *myList = makeEmptyList();

	// call fillList function from util.c
	// Step 3: 9 points
	fillList(myList, input);

	// print the entire list
	// Step 4: 6 points
	printList(myList);

	// free allocated memory
	// Step 5: 3 points
	freeList(myList);

	// close all files before exit
	fclose(input);

	return(0);
}

