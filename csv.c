#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	// print all characters in file
	FILE *i = inFile;
	while (getc(i) != EOF){
		printf("%c", getc(i));
		i++;
	}

	fclose(inFile); // close file

	return 0;
}
