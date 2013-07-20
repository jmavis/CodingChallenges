#include <stdio.h>
#include <stdlib.h>

/// Author Jared Mavis
/// Username jmavis
/// CodeEval Fibonacci Series
/*
/// Will get the nth fibonacci number starting with 1 as the 0th endtry
int getNthFibonacciNumber(int n){
	int currentNum = 1;
	int firstNum = 1;
	if (n < 2) return 1;
	do {
		int tempCopy = currentNum;
		currentNum += firstNum;
		firstNum = tempCopy;
		n--;
	} while (n > 2);
	return (currentNum);
}

int main(int argc, char *argv[]){
	FILE* f = fopen(argv[1], "r");
	char line[999];
	while (fgets(line, 1024, f)) {
		// Skip empty lines
		if (line[0] == '\n') {
			continue;
		}
		printf("%i\n", getNthFibonacciNumber(atoi(line)));
	}
	fclose(f);
	return 0;
}
*/