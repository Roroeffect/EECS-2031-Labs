/**
// You need to add some code here to protect the header
**/

#ifndef UTIL_H
#define UTIL_H

#define BUF_SIZE 100

typedef struct city{
    char *name;
    int population;
} City;

typedef struct country{
    char *name;
	City *capitalCity;
    int population;
} Country;

typedef struct list {
    Country *country;
    struct list *next;
} List;

/**
// You need to introduce functions from util.c
**/
/**
// Make an empty list. An empty list has a head with null country and the "next" field is null.
**/
List *makeEmptyList(void);

/**
// Fill the empty list given by "head" using the content of the "input" file
**/
void fillList(List *head, FILE *input);

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
void printList(List *head);

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
void freeList(List *head);

#endif
