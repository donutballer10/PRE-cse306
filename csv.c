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
	char *lines[] = calloc(3, 100);

	// print all characters in file
	char cur = getc(inFile);
	while (cur != EOF){
		//printf("%c", cur);
		//cur = getc(inFile); // increments to next char
		char *line = calloc(LENGTH, CHAR); 
		char *cur_char = line; // to increment through line array
		while (cur != "\n"){
			*cur_char  = cur; // add char to line array
			cur_char++; // increment to next spot in line array
			getc(inFile); // increment to next char in file
		}


	}

	fclose(inFile); // close file

	return 0;
}
