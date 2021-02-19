#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "functions/get_dimensions.h"
#include "functions/record.h"
#include "functions/semi_group_operation.h"
#include <string.h>

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

  //arguments
  char *f = "-f";
  
  //skip the first argument as it's the name of the executable
  int i = 1;

  //skip the last argument as it's the name of the csv file 
  while ( i < argc - 1){
    char *argument = argv[i];
    
    if (strcmp(argument,f) == 0){
      get_columns();
      i++;
    }
  }

  fclose(file_ptr);
                                                                                                
  return 0;
}
