#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
/*
void ParseLine(string line);
string ContainsSubstring(string base, unsigned int endOfBaseString);

/// Author Jared Mavis
/// Username jmavis
/// CodeEval String Searching
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
}

/// Will call ContainsSubstring with the given line and print out the result
void ParseLine(string line){
	int endOfBaseString = line.find(",");
	cout << ContainsSubstring(line, endOfBaseString) << endl;
}

/// Will return true if the substrings occur inside of the given base string in order
string ContainsSubstring(string base, unsigned int endOfBaseString){
	unsigned int sequenceIndex = 0;
	unsigned int baseIndex = 0;
	while (baseIndex < endOfBaseString && sequenceIndex+endOfBaseString+1 < base.length()){
		char toFind = base[sequenceIndex+endOfBaseString+1];
		if ((toFind == '/' && sequenceIndex+endOfBaseString+2 < base.length() && base[sequenceIndex+endOfBaseString+2] == '*') ||
			(toFind == '*'))	{
			sequenceIndex++;
			while (sequenceIndex < base.length() && base[sequenceIndex+endOfBaseString+1] == '*'){
				sequenceIndex++;
			}
		}
		if (base[baseIndex] == base[sequenceIndex+endOfBaseString+1]){
			sequenceIndex++;
		} 
		baseIndex++;
	}
	if (baseIndex == endOfBaseString && sequenceIndex+endOfBaseString+1 != base.length()){ // if we got through all the base string first then we didn't find the subsequence
		return ("false");
	} else {
		return ("true");
	}
}*/