#include <stdio.h>
#include <stdbool.h>

#include "functions/column_count.h"
#include "functions/row_count.h"
#include "functions/semi_group_operation.h"


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
  max(ptr,false,"hello");
  min(ptr,false,"hello");
  mean(ptr,false,"hello");

  return 0;
}
