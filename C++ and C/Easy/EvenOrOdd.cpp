#include <iostream> // cout
#include <stdlib.h> // std namespace
#include <string> // string
#include <fstream> // file io

using namespace std;

void ParseLine(string line);

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

/// will get the last character in the line and determine if it is even or not
void ParseLine(string line){
	char lastChar = line[line.length()-1];
	cout << (lastChar % 2 == 0) << endl; // ascii values for chars 0-9 match evenness with their number countparts
}