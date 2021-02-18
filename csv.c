#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "functions/column_count.h"
#include "functions/row_count.h"
#include "functions/semi_group_operation.h"


int main (int argc, char *argv[]){

  //error checking for arguments count
  if (argc < 3){
    printf("Invalid number of arguments\n");
    return EXIT_FAILURE;
  }

  //pointer which contains the file name
  char *filename = argv[argc -1]; 
  FILE *file_ptr =fopen(filename,"r");

  if (file_ptr == NULL){
    printf("Unable to open the file\n");
    return EXIT_FAILURE;
  }
  
  //read arguments
  for (int i =1; i<argc-1; i++){
    char *str = argv[i];
    printf("%s\n",str);
  }

  fclose(file_ptr);

  /*
  printf("hello world! CSV!\n");
  column_count(ptr);
  row_count(ptr,false);
  max(ptr,false,"hello");
  min(ptr,false,"hello");
  mean(ptr,false,"hello");
  search(ptr,false,"hello","");                                                                                               

  */
  return 0;
}
