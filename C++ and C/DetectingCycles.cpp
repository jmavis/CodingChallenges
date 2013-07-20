#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>  

using namespace std;

string FindLongestCycle(const vector<string>& parts);
void ParseLine(string line);
vector<string> Split(const string& source, char toSplitBy);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Detecting Cycles
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

/// will parse the given line apart then give FindLongestCycle the correct arguments and print out
/// the result
void ParseLine(string line){
	vector<string> splitPart = Split(line, ' ');
	if (splitPart.size() >= 1){
		cout << FindLongestCycle(splitPart) << endl;
	}
}

vector<string> Split(const string& source, char toSplitBy){
	vector<string> result;
	string currentPart = "";
	for (unsigned int i = 0; i < source.length(); i++){
		if (i + 1 == source.length()){
			if (source[i] != toSplitBy){
				currentPart += source[i];
			}
			result.push_back(currentPart);
		} else if (source[i] == toSplitBy && currentPart != ""){
			result.push_back(currentPart);
			currentPart = "";
		} else {
			currentPart += source[i];
		}
	}
	return (result);
}

string FindLongestCycle(const vector<string>& parts){
	string currentCombo = "";

	vector<string>::const_iterator currentIndex = parts.begin();
	vector<string>::const_iterator startOfSubsequence = parts.end();
	
	while (startOfSubsequence == parts.end()){
		if (currentIndex + 1 >= parts.end()) {
			return (parts.at(0));
		}
		startOfSubsequence = find(currentIndex+1, parts.end(), *currentIndex);
		if (startOfSubsequence == parts.end()){
			currentIndex++;
		}
	} 

	vector<string>::const_iterator subsequenceIndex = startOfSubsequence;

	while (currentIndex != startOfSubsequence && subsequenceIndex < parts.end()){
		currentCombo += *currentIndex + (currentIndex + 1 < startOfSubsequence && subsequenceIndex + 1 < parts.end() ? " " : "");
		currentIndex++;
		subsequenceIndex++;
	}

	return (currentCombo);
}