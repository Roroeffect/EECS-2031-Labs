/******************************************************************************


*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main()
{

   int i, j, cap, numberOfTests = 32;

   struct extendableArray *A = (struct extendableArray *)initArr();

   cap = arrCapacity(A);
   printf("Capacity = %d\n", arrCapacity(A));

   for (i = 0; i < numberOfTests; i++)
   {
      insertLast(A, i * 5);
      if (cap < arrCapacity(A))
      {
         /* print the array right after it was extended */
         printf("Capacity = %d\n", arrCapacity(A));
         printArray(A);
         cap = arrCapacity(A);
      }
   }

   printArray(A);

   cap = arrCapacity(A);

   for (i = 0; i < numberOfTests; i++)
   {
      j = removeLast(A);
      //printf("removed = %d\n", j);
      if (cap > arrCapacity(A))
      {
         /* print the array right after it was shrunk */
         printf("Capacity = %d\n", arrCapacity(A));
         printArray(A);
         cap = arrCapacity(A);
      }
   }

   printArray(A);
}