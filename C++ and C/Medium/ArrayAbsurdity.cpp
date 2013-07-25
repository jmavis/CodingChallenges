#include <iostream> // cout
#include <stdlib.h> // std namespace
#include <string> // string
#include <fstream> // file io
#include <vector> // vector

using namespace std;

void ParseLine(string line);
int FindDuplicate(unsigned int size, string data);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Even Numbers
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

/// Will break up the given line and will print out the result of find duplicate of it
void ParseLine(string line){
	int semiColonIndex = line.find(';');
	int size = atoi(line.substr(0, semiColonIndex).c_str());
	
	cout << FindDuplicate(size, line.substr(semiColonIndex+1)) << endl;
}

/// Will return the first instance of a duplicate in the data or -1 if none was found
int FindDuplicate(unsigned int size, string data){
	vector<bool> numCounts(size-1);

	unsigned int nextNumStart = 0;
	unsigned int nextNumEnd;
	unsigned int currentNum;
	do {
		if (nextNumStart >= data.length()){
			cout << "No duplicate found" << endl;
			return (-1);
		}
		nextNumEnd = data.find(',', nextNumStart);
		if (nextNumEnd == string::npos){
			nextNumEnd = data.length()-1;
		}
		currentNum = atoi(data.substr(nextNumStart, nextNumEnd-nextNumStart).c_str());
		nextNumStart = nextNumEnd+1;
		numCounts[currentNum] = !numCounts[currentNum]; 
	} while (numCounts.at(currentNum) != 0); // if before going numCount[currentNum] was true (was found before) and was toggled back to false (was found again) 
	return (currentNum);
}