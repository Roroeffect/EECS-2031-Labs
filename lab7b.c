#include <stdio.h>
#include "util.h"
/* This program reads a line of characters and finds the count and sum 
 * of each individual numbers. All numbers are treated individually.
 */

#define MAX_ENTRY 100

void main(){
	char inchstr[MAX_ENTRY];
	float inch;
	
	printf("Enter a line of characters>");
	fgets(inchstr, MAX_ENTRY, stdin);
	int_count(inchstr);

}
