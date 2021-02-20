#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "functions/get_dimensions.h"
#include "functions/record.h"
#include "functions/semi_group_operation.h"
#include <string.h>

#define r "-r"
#define f "-f"
#define h "-h"
#define max "-max"
#define min "-min"
#define mean "-mean"
#define records "-records"

//it does not inlcude -f and -h becuase they are special cases handled inside the main
char* determineOperation(char* operation){
  if (strcmp(operation,r) == 0){
    return r;
  }else if (strcmp(operation,f) == 0){
    return f;
  }else if (strcmp(operation,h) == 0){
    return h;
  }else if (strcmp(operation,max) == 0){
    return max;
  }else if (strcmp(operation,min) == 0){
    return min;
  }else if (strcmp(operation,mean) == 0){
    return mean;
  }else if (strcmp(operation,records) == 0){
    return records;
  }else{
    printf("unrecoginzed operator was passed\n");
    return NULL;
  }
}

void executeOperations(int *i,char* operator, char *argv[],FILE* file_ptr,bool containsH){
  
  if (operator == r){
    get_rows(file_ptr, containsH);
  }
  if (operator == f){
    get_columns(file_ptr);
  }
  
  //if the operator is not f or r, then other operators requires field name for valid input
  char *field_name = argv[*i];
 
  if (operator == min){
    find_min(file_ptr, field_name);
  }
  if (operator == max){
    find_max(file_ptr, field_name);
  }
  if (operator == mean){
    find_mean(file_ptr, field_name);
  }
  if (operator == records){
    //get the value we are searching for in record 
    char *value = argv[++(*i)];
    get_record(field_name,value);
  }
}

int main (int argc, char *argv[]){

  // we need atleast 2 arguments (for -f) for a valid input 
  if (argc < 3){
    printf("Invalid number of arguments\n");
    return EXIT_FAILURE;
  }

  //last argument contains the file name
  char *filename = argv[argc -1]; 
 
  //open file for reading
  FILE *file_ptr = fopen(filename,"r");
    
  //only parse csv file
  if (file_ptr == NULL){
    printf("Unable to open the file\n");
    return EXIT_FAILURE;
  }

  //skip the first argument as it's the name of the executable
  int i = 1;
  bool containsH = false;

  //determine if the arguments contains a header
  for (int j = 1; j < argc - 1; j++){
    char *argument = argv[j];
    if (strcmp(argument,h) == 0){
      containsH = true;
      break;
    }
  }
  //skip the last argument as it's the name of the csv file 
  while ( i < argc - 1){
    
    //get the first operator and move pointer to the next operator
    char *operator = determineOperation(argv[i++]);
    
    if (operator == NULL){
      return EXIT_FAILURE;
    }

    if (operator == h){
      operator = determineOperation(argv[i++]);
    }

    if (operator == NULL){
      return EXIT_FAILURE;
    }
    
    executeOperations(&i, operator, argv, file_ptr,containsH);

    i++;
  }

  fclose(file_ptr);
  
  return EXIT_SUCCESS;
}
