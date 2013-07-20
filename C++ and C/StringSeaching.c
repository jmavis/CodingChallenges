#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

/// Author Jared Mavis
/// Username jmavis
/// CodeEval String Searching
/*
/// Will find the starting index of the first occurance of the given string or -1 if the string was not found
int FindIndex(char* base, char* toFind){
	unsigned int i;
	unsigned int x;
	for (i = 0; i < strlen(base); i++){
		for (x = 0; x < strlen(toFind); x++){
			if (base[i+x] != toFind[x]){
				break;
			} else {
				if (x + 1 == strlen(toFind)){
					return (i);
				}
			}
		}
	}
	return (-1);
}

/// Will determine if the given parts occur after one another and return true if so
char* StringIsSubstring(char* base, char** parts){
	
}

/// will parse the line apart and print the result of StringIsSubstring of the input
void ParseLine(char* line){
	size_t charSpace = 1;
	int baseWordIndex = FindIndex(line, ",");
	char* baseWord = (char*)malloc(sizeof(char));
	//char* subsequence = malloc(strlen(line)-baseWordIndex+1);
	int i = 0;
	printf("%s\n + size = %i", baseWord, strlen(baseWord));
	for (i = 0; i < baseWordIndex; i++){
		baseWord[i] = line[i];
		//printf("Base = %s + line[i] = %c i = %i\n", baseWord, line[i], i);
	}
	for (i = 0; i < strlen(line)-baseWordIndex+1; i++){
		subsequence[i] = line[baseWordIndex+i+1];
	}
	//printf("Line = %s + Base word = %s + subsequnce = %s index = %i", line, baseWord, subsequence, baseWordIndex);
}

int main(int argc, char *argv[]){
	FILE* f = fopen(argv[1], "r");
	char line[999];
	while (fgets(line, 1024, f)) {
		// Skip empty lines
		if (line[0] == '\n') {
			continue;
		}
		ParseLine(line);
	}
	fclose(f);
	getchar();
	return 0;
}*/