#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
/*
using namespace std;

void ParseLine(string line);
string ReverseWords(string s);


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

/// Will print out the result of ReverseWords on the line
void ParseLine(string line){
	string reversed = ReverseWords(line);
	if (reversed.length() == 0) return;
	cout << reversed << endl;
}

/// Will go through the given string and will reverse all the words in it
/// Takes a string with no trailing spaces
/// Returns a string with the words in reverse order of appearance
string ReverseWords(string s){
	string reversed = "";
	int nextWordEndPos = 0;
	int nextWordStartPos = 0;

	while (nextWordStartPos < s.length()){
		nextWordEndPos = s.find(' ', nextWordStartPos);
		if (nextWordEndPos == string::npos){
			nextWordEndPos = s.length();
		} 
		if (nextWordEndPos != nextWordStartPos) { // if we didn't move forward any (ie inside spaces)
			reversed = s.substr(nextWordStartPos, nextWordEndPos-nextWordStartPos) + (reversed.length() == 0 ? "" : " ") + reversed;
		}

		nextWordStartPos = nextWordEndPos + 1;
	}
	return (reversed);
}*/