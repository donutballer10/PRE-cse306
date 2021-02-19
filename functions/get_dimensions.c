#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define comma ","

void get_columns(FILE* file_ptr){
  printf("get columns count was called\n");
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
