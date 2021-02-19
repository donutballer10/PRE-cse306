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
	char ***lines_arr = calloc(3, 100);

	// build array of lines
	char ***cur_line = lines_arr; // pointer to increment through lines_arr array
	char cur_char = getc(inFile); // current char in file
	while (cur_char != EOF){

		// build line array and add to lines_arr
		// each line array consists of the words in that line
		char **line = calloc(LENGTH, CHAR); 
		char **cur = line; // to increment through line array
		while (cur_char != NEWLINE){

			// build word
			char *word = calloc(WORD_LEN, CHAR);
			char *cur_word = word; // pointer to increment through word
			while (cur_char != WHITESPACE && cur_char != NEWLINE){
				*cur_word = cur_char;	
				cur_word++;
				cur_char = getc(inFile);
			}	
			*cur = word; // add word to line array
			cur++;
			cur_char = getc(inFile); // increment to next char in file

		}
		cur_char = getc(inFile); // increment to next char in file
		*cur_line = line;
		cur_line++;

	}

	printf("%s = line array index 1\n", lines_arr[0]);
	printf("%s = line array index 2\n", lines_arr[1]);
	printf("%s = line array index 3\n", lines_arr[2]);
	
	/*
	// free each line in lines_arr
	printf("%p = lines_arr pointer later\n", lines_arr);
  cur_line = lines_arr; // reset it, to increment through line array, this time to free 
	printf("%p = cur_line address when freeing\n", cur_line);
	for (int i = 1; i <= LINES; i++){
		//free((char *) free_cur);
		printf("%s = line\n", (char *) cur_line);
		cur_line++;
	}*/
	free(lines_arr); // free lines_arr array
	fclose(inFile); // close file

	return 0;
}
