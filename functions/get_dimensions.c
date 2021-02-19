#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define comma ","

void get_columns(FILE* file_ptr){
  printf("get columns count was called\n");
  
  char c;
  int count = 0;
  while((c=fgetc(file_ptr)) != EOF){
    if ( c == '\n'){
      count++;
    }
   
    printf("%c",c);
  }
  printf("%d\n",count);
  return;
}

void get_rows(){
  printf("get rows count was called\n");
  return;
}
