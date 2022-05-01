#include <stdio.h>
#include "util.h"

#define MAX_SIZE 100

main() {
   char my_strg[ MAX_SIZE ];
   getaline(my_strg, MAX_SIZE);

   int my_int = octal2decimal(my_strg);
   printf( "%d\n", my_int);  /* output the decimal number */
}
