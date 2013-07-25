#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <string>
#include <fstream>

using namespace std;

string RemoveChars(const string& source, const string& charsToRemove);
bool ShouldRemoveChar(const char& toCheck, const string& charsToRemove);
void ParseLine(string line);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Remove Characters
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

/// will parse the given line apart then give RemoveChars the correct arguments and print out
/// the result of removing the given chars
void ParseLine(string line){
	int commaIndex = line.find(',');
	string source = line.substr(0,commaIndex);
	string charsToRemove = line.substr(commaIndex+2);
	cout << RemoveChars(source, charsToRemove) << endl;
}

/// Will return a string consiting of the source string with the given characters removed
string RemoveChars(const string& source, const string& charsToRemove){
	string result = "";

	for(int currentIndex = 0; currentIndex < source.length(); currentIndex++){
		if (!ShouldRemoveChar(source[currentIndex], charsToRemove)){
			result += source[currentIndex];
		}
	}
	return (result);
}

/// Will return true if the character to char is in the charactersToRemove or false otherwise
bool ShouldRemoveChar(const char& toCheck, const string& charsToRemove){
	for (int i = 0; i < charsToRemove.length(); i++){
		if (toCheck == charsToRemove[i]){
			return (true);
		}
	}
	return (false);
}