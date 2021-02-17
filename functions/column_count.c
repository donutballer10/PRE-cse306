#include <stdio.h>

void column_count(FILE *file_pointer){
  printf("you're in column count function\n");
  return;
}


/*

Be sure to keep the main function below the column_count otherwise it will create an implicit declartion error
int main(){
  FILE *fptr;
  column_count(fptr);
  return 0;
}

*/
