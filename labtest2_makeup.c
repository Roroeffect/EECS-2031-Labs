#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

int main(int argc, char *argv[]) {
  FILE *input;

  // There should be 1 argument passed to the main function
  if (argc < 2){
	printf("You should enter the input and output files and a search phrase. Example:\n");
	printf("labtest2_makeup labtest2_makeup.in \n");
	exit(1);
  }

  // Check the input file
  input = fopen(argv[1],"r");
  if (input == NULL)
  {
	printf("File \"%s\" can not be opened for reading.\n", argv[1]);
	exit(1);
  }


  printf("This message shows that the code is compiled and run correctly for Step 1\n");

    List *myList = makeEmptyList();

    fillList(myList, input);

    printList(myList);

    freeList(myList);

    fclose(input);

    return(0);




}

