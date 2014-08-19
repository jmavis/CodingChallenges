#include <iostream> // cout
#include <string> // string
#include <fstream> // file io
#include <stdlib.h> // std lib fns
#include <vector>
#include <sstream> 

using namespace std;

void printLineLettercasePercentage(string& line){
	float lowerCaseCount = 0;
	int lineCharacters = line.length();
	for (int i = 0; i < lineCharacters; i++){
		if (line[i] == tolower(line[i])){
			lowerCaseCount++;
		}
	}
	float lowerCasePercent = (lowerCaseCount/lineCharacters) * 100.0;

	printf("lowercase: %2.2f uppercase: %2.2f\n", lowerCasePercent, 100.0-lowerCasePercent);
}

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Lettercase Percentage Ratio 
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			string line = lineBuffer.c_str();
			printLineLettercasePercentage(line);
		}
	}
}