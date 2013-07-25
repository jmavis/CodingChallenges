#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <string>
#include <fstream>

using namespace std;

int FindRightMostChar(const string& source, const char& toFind);
void ParseLine(string line);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Righmost Char
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			ParseLine(lineBuffer);
		}
	}
	cin >> lineBuffer;
}

/// will parse the given line apart then give FindRightMostChar the correct arguments and print out
/// the result
void ParseLine(string line){
	int commaIndex = line.find(',');
	string source = line.substr(0,commaIndex);
	char charToRemove = line[commaIndex+1];
	cout << FindRightMostChar(source, charToRemove) << endl;
}

/// Will return the index of the rightmost occurance of the given char
/// or -1 if it was not found
int FindRightMostChar(const string& source, const char& toFind){
	int index = source.length()-1;
	while (index >= 0 && source[index] != toFind){
		index--;
	}
	return (index);
}