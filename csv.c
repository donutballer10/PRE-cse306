#include <stdio.h>
#include "functions/column_count.h"

/*
To execute the program run 
gcc csv.c -o csv
./csv
 */

int main (void){
  printf("hello world! CSV!\n");
  FILE *ptr;
  column_count(ptr);
  return 0;
}
