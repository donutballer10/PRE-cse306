#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LINES 3
#define LINE_LEN 100
#define WORD_LEN 50
// pretty sure im gonna use these, unlike the 3 above
#define CHAR 1
#define NEWLINE '\n'
#define COMMA ','

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
	bool newline = false; // for 2nd layer, so i know when to call getc() there
	char ***cur_row = rows; // pointer to increment through rows array
	char cur_char = getc(inFile); // current char in file
	while (cur_char != EOF){


		// build line array and add to rows
		// each line array consists of the words in that line
		char **line = calloc(LINE_LEN, WORD_LEN); 
		char **cur_line = line; // to increment through line array
		if (newline == true) { cur_char = getc(inFile); newline = false; }
		while (cur_char != NEWLINE){


			// build word
			char *word = calloc(WORD_LEN, CHAR);
			char *cur_word = word; // pointer to increment through word
			while (cur_char != COMMA && cur_char != NEWLINE && cur_char != EOF){
				*cur_word = cur_char;	
				cur_word++;
				cur_char = getc(inFile);
			}	
			*cur_line = word; // add word to line array // whitespace char here, what happens then?
			cur_line++;

			if (cur_char == EOF) { break; } // not sure if this break works as intended, i think so
			else if (cur_char == NEWLINE) { newline = true; }
			// will the next char after a comma ever be a newline or EOF? i don't think so?
			else if (cur_char == COMMA) { cur_char = getc(inFile); } 


		}
		*cur_row = line; // add line to rows
		cur_row++;
		// cur_char = getc(inFile); // this is supposed to be either here...


	}

	printf("%s\n", rows[0][0]);
	printf("%s\n", rows[0][1]);
	printf("%s\n", rows[0][2]);

	printf("%s\n", rows[1][0]);
	printf("%s\n", rows[1][1]);
	printf("%s\n", rows[1][2]);

	printf("%s\n", rows[2][0]);
	printf("%s\n", rows[2][1]);
	printf("%s\n", rows[2][2]);
//	printf("%s = line array index 2\n", rows[1]);
//	printf("%s = line array index 3\n", rows[2]);
	
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
