#include <stdio.h>
#include <stdbool.h>

#include "functions/column_count.h"
#include "functions/row_count.h"

/*
To execute the program run 
gcc csv.c -o csv
./csv
 */

int main (void){
  printf("hello world! CSV!\n");
  FILE *ptr;
  column_count(ptr);
  row_count(ptr,false);
  return 0;
}
