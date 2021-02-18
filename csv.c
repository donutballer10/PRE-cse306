#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINES 3
#define LENGTH 100
#define CHAR 1

int main(int argc, char *argv[]){

	FILE * inFile = NULL;

	// assign file pointer to inFile
	if (argc > 1){
		inFile = fopen(argv[1], "r");
	}

	// check that there is a valid file given
	if (inFile == NULL){ 
		printf("%s\n", "invalid file given\n");
		return 0;
	}

	// array of lines from the file
	// pointer to array(pointer) of strings(pointer)? should i use '**' instead
	char **lines = calloc(3, 100);
	printf("%p = lines pointer \n", lines);

	// print all characters in file
	char **cur_line = lines; // pointer to increment through lines array
	char cur_char = getc(inFile); // current char in file
	while (cur_char != EOF){
		//printf("%c", cur);
		char *line = calloc(LENGTH, CHAR); 
		char *cur = line; // to increment through line array
		//printf("%c\n", cur_char);
		while (cur_char != '\n'){
			//printf("%c = cur_char\n", cur_char);
			*cur = cur_char; // add char to line array
			cur++; // increment to next spot in line array
			cur_char = getc(inFile); // increment to next char in file
		}
		cur_char = getc(inFile); // increment to next char in file
		//printf("%s = line\n", line);
		*cur_line = line;
		printf("%s = line array in loop\n", *cur_line);
		cur_line++;

	}
	printf("%s = line array index 1\n", lines[0]);
	printf("%s = line array index 2\n", lines[1]);
	printf("%s = line array index 3\n", lines[2]);
	

	// free each line in lines array
	printf("%p = lines pointer later\n", lines);
  cur_line = lines; // reset it, to increment through line array, this time to free 
	printf("%p = cur_line address when freeing\n", cur_line);
	for (int i = 1; i <= LINES; i++){
		//free((char *) free_cur);
		printf("%s = line\n", (char *) cur_line);
		cur_line++;
	}	
	free(lines); // free lines array
	fclose(inFile); // close file

	return 0;
}
