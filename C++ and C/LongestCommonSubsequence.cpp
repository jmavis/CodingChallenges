#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <string>
#include <fstream>
/*
using namespace std;

void ParseLine(string line);
string FindLongestCommonSubsequence(string seq1, string seq2);

/// Author Jared Mavis
/// Username jmavis
/// CodeEval Challenge Longest Common Subsequence
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

/// Will print out the result of FindLongestCommonSubsequence on the line
/// after parsing it apart and providing the right input
void ParseLine(string line){
	int firstSequnceIndex = line.find(';');
	string firstSequenceString = line.substr(0, firstSequnceIndex);
	string secondSequenceString = line.substr(firstSequnceIndex+1);
	if (firstSequenceString.length() < secondSequenceString.length()){ // use the largest one for the main looping
		string copy = firstSequenceString;
		firstSequenceString = secondSequenceString;
		secondSequenceString = copy;
	}
	cout << FindLongestCommonSubsequence(firstSequenceString, secondSequenceString) << endl;
}

/// Will find the longest common subsequence from the two strings
string FindLongestCommonSubsequence(string seq1, string seq2){
	int startPos = 0;
	int firstIndex = 0;
	int secondIndex = 0;
	string currentCombo = "";
	string largestComboSoFar = "";
	while (startPos < seq1.length()){
		int prevIndex = secondIndex; // store the previous index if the next one we look up leads nowhere
		char currentCharInSeq1 = seq1[firstIndex];
		secondIndex = seq2.find(currentCharInSeq1, secondIndex);
		if (secondIndex == string::npos){
			secondIndex = prevIndex; // move back
		} else {
			currentCombo += currentCharInSeq1;
			secondIndex++; // only look in the ones after
		}
		firstIndex++;
		if (firstIndex >= seq1.length()){
			startPos++;
			firstIndex = startPos;
			secondIndex = 0;
			if (currentCombo.length() > largestComboSoFar.length()){
				largestComboSoFar = currentCombo;
			}
			currentCombo = "";
		}
	}
	return (largestComboSoFar);
}*/