#include <stdio.h>
#include "util.h"

#define MAX_SIZE 100

main() {
   char my_strg[ MAX_SIZE ];
   getaline(my_strg, MAX_SIZE);
   str_reverse(my_strg);
   printf( "%s\n", my_strg );  /* output the reversed string */
}
