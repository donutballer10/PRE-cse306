#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define comma ","

void get_columns(FILE* file_ptr){
  
  char c;
  int strlc = 0; //counter to not include commas within string literals
  int count = 0; //counter for commas
  int columns = 0; //counter for number of columns present in csv
  
  while((c=fgetc(file_ptr)) != '\n'){
    if ( c == '\"'){
      strlc++;
    }
    else if(c == ',' && strlc%2 == 0){
      count++;
    }else{
    }
  }
  columns = count + 1; //3 commas found would indicate presence of 4 fields.
  printf("%d\n",columns);

  return;
}

void get_rows(FILE* file_ptr, bool containsH){
  
  char c;
  int count = 0;
  
  while((c=fgetc(file_ptr)) != EOF){
    if ( c == '\n'){
      count++;
    }
  }

  if (containsH){
    count = count - 1;
  }
  
  printf("%d\n",count);

  return;
}
