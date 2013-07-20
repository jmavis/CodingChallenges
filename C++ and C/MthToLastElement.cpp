#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <string>
#include <fstream>
#include <vector>
/*
using namespace std;

void PrintMthToLastElement(string line);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Mth to last element
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			PrintMthToLastElement(lineBuffer);
		}
	}
}

/// Will print the mth to last element where m is the last number in the line and the line
/// is composed of a space seperacted list of strings.
/// if m > length of the list it will not print anything
void PrintMthToLastElement(string line){
	int index = line.length()-1;

	while (line[index] != ' '){
		index--;
	}

	int m = atoi(line.substr(index+1).c_str());

	int lastSpace = index;
	while(index >= 0 && m > 0){
		if (line[index] == ' '){
			m--;
			lastSpace = index;
		}
		index--;
	}

	if (m == 0){
		cout << line.substr(index, lastSpace-index) << endl;
	} else if (m == 1) { // if we are one away then we return the first element
		cout << line.substr(0, lastSpace) << endl;
	}
}*/