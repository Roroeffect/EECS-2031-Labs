#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

/**
// Make an empty list. An empty list has a head with null country and the "next" field is null.
**/
List *makeEmptyList(void){
    List *result;

	result = (List*)malloc(sizeof(List));
	result->country = NULL;
	result->next = NULL;

	return result;
}


/**
// Fill the empty list given by "head" using the content of the "input" file
**/
void fillList(List *head, FILE *input){

    char name[BUF_SIZE];
    char capitalName[BUF_SIZE];
    long int population;
    int capitalPopulation;

    if (head->next != NULL) {
        printf("The head is already pointed to an element. The list is not empty.\n");
        return;
    }

    List *last = head, *newNode;
    Country *newCountry;
    City *newCapital;

    // Read each line of the input file and store into "buffer"
    while(fscanf(input, "%s %li %s %d", name, &population, capitalName, &capitalPopulation) != EOF){
        // Allocate some memory
		newNode = (List*)malloc(sizeof(List));
		
		newCountry = (Country*)malloc(sizeof(Country));
		newCountry->name = malloc(strlen(name) + 1);
		
		newCapital = (City*)malloc(sizeof(Country));
		newCapital->name = malloc(strlen(capitalName) + 1);

        // Set values for the new node
		strcpy(newCountry->name, name);
		newCountry->population = population;

		strcpy(newCapital->name, capitalName);
		newCapital->population = capitalPopulation;

		newCountry->capitalCity = newCapital;
		newNode->country = newCountry;		

        // three line of code for setting the next node
		newNode->next = NULL;
		if (head->next == NULL) head->next = newNode;
		else last->next = newNode;
		last = newNode;
    }
}

/**
// print the list of countries and their capitals. Here is an example for labtest2_makeup.in:

Country Name             Population      Capital Name    Capital Population
--------------------------------------------------------------------------------
Canada                     37500000      Ottawa                     994837
Italy                      60360000      Rome                      2873000
USA                       328200000      Washington                 705749
China                    1393000000      Beijing                  21540000
--------------------------------------------------------------------------------
Population Sum           1819060000      Capital sum              26113586
Population Average        454765000      Capital Average           6528396


**/
void printList(List *head){

	long populationSum = 0;
	long capitalSum = 0;

	int n = 0;
	printf("%-20s\t", "Country Name");
	printf("%15s\t", "Population");
	printf("%-20s\t", "Capital Name");
	printf("%15s\n", "Capital Population");
	printf("---------------------------------------------------------------------------------------\n");
	while (head->next != NULL) {
		head = head->next;
		printf("%-20s\t", head->country->name);
		n = n + 1;		
		printf("%15d\t", head->country->population);

		printf("%-20s\t", head->country->capitalCity->name);
		printf("%15d\n", head->country->capitalCity->population);

		populationSum = head->country->population + populationSum;
		capitalSum = head->country->capitalCity->population + capitalSum;
	}
	printf("---------------------------------------------------------------------------------------\n");
	printf("%-20s\t", "Population Sum");
	printf("%15ld\t", populationSum);

	printf("%-20s\t", "Capital Sum");
	printf("%15ld\n", capitalSum);

	printf("%-20s\t", "Population Average");
	printf("%15.0f\t", (populationSum / (float)n));

	printf("%-20s\t", "Capital Average");
	printf("%15.0f\n", (capitalSum / (float)n));
}

/**
// Free up all allocated memory for the list which is represented by "head".
// Note:
When compile code with:
gcc -g labtest2_makeup.c util.c -o labtest2_makeup

You can check your memory leaks using:

valgrind --tool=memcheck --leak-check=yes labtest2_makeup labtest2_makeup.in


"valgrind" runs your code and find any possible memory leaks in your code.
To fix your code pay attention to line of code reported by "valgrind".
**/
void freeList(List *head){

   List *next2Head;

   while(head->next != NULL){
      
	   next2Head = head->next;
	   head->next = next2Head->next;

	   //free the node
	   free(next2Head->country->capitalCity->name);
	   next2Head->country->capitalCity->name = NULL;
	   
	   free(next2Head->country->capitalCity);
	   next2Head->country->capitalCity = NULL;

	   free(next2Head->country->name);
	   next2Head->country->name = NULL;

	   free(next2Head->country);
	   next2Head->country = NULL;

	   free(next2Head);
	   next2Head = NULL;
   }
   // don't forget to free the header too
   free(head);
   head = NULL;
}
