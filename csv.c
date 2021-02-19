#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINES 3
#define LINE_LEN 100
#define WORD_LEN 50
#define CHAR 1
#define WHITESPACE ' '
#define NEWLINE '\n'

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
	// array of pointers to arrays of strings; lines[line[words]]
	char ***rows = calloc(LINES, LINE_LEN);
	// build array of lines
	char ***cur_row = rows; // pointer to increment through rows array
	char cur_char = getc(inFile); // current char in file
	while (cur_char != EOF){

		// build line array and add to rows
		// each line array consists of the words in that line
		char **line = calloc(LINE_LEN, WORD_LEN); 
		char **cur_line = line; // to increment through line array
		while (cur_char != NEWLINE){

			// build word
			char *word = calloc(WORD_LEN, CHAR);
			char *cur_word = word; // pointer to increment through word
			while (cur_char != WHITESPACE && cur_char != NEWLINE){
				*cur_word = cur_char;	
				cur_word++;
				cur_char = getc(inFile);
			}	
			*cur_line = word; // add word to line array
			cur_line++;
			cur_char = getc(inFile); // increment to next char in file

		}
		*cur_row = line;
		cur_row++;

	}

	printf("%s = line array index 1\n", rows[0]);
	printf("%s = line array index 2\n", rows[1]);
	printf("%s = line array index 3\n", rows[2]);
	
	/*
	// free each line in rows
	printf("%p = rows pointer later\n", rows);
  cur_row = rows; // reset it, to increment through line array, this time to free 
	printf("%p = cur_row address when freeing\n", cur_row);
	for (int i = 1; i <= LINES; i++){
		//free((char *) free_cur);
		printf("%s = line\n", (char *) cur_row);
		cur_row++;
	}*/
	free(rows); // free rows array
	fclose(inFile); // close file

	return 0;
}
