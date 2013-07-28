#include <iostream> // cout
#include <string> // string
#include <fstream> // file io
#include <stdlib.h>

using namespace std;

/// Will return the largest integer that can be made out of coninuous entries in the given line
int FindLargestSum(const string& line);
/// Will find the next number in the given string and update the starting number
int FindNextNum(const string& source, unsigned int& start, char splitChar);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Sum of Integers
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			cout << FindLargestSum(lineBuffer) << endl;
		}
	}
}

int FindLargestSum(const string& line){
	unsigned int currentIndex = 0;
	int current = FindNextNum(line, currentIndex, ',');
	int highest = current;
	int nextNum;
	while (currentIndex < line.length()){
		nextNum = FindNextNum(line, currentIndex, ',');
		current += nextNum;
		if (current < 0){
			current = nextNum;
		}
		if (current > highest){
			highest = current;
		}
	}
	return (highest);
}

int FindNextNum(const string& source, unsigned int& start, char splitChar){
	int endIndex = source.find(splitChar, start);
	if (endIndex == string::npos){
		endIndex = source.length();
	}
	int startIndex = start;
	start = endIndex+1;
	return (atoi(source.substr(startIndex, endIndex-startIndex).c_str()));
}