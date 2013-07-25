#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <string>
#include <fstream>  

using namespace std;

void PrintFirstNonRepeatCharacter(string source);
bool ContainsCharInDifferentPlace(const string& source, int charPlace);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval First Non Repeat Character
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			PrintFirstNonRepeatCharacter(lineBuffer);
		}
	}
	cin >> lineBuffer;
}

void PrintFirstNonRepeatCharacter(string source){
	for (unsigned int i = 0; i < source.length(); i++){
		if (!ContainsCharInDifferentPlace(source, i)){
			cout << source[i] << endl;
			return;
		}
	}
	cout << "NULL" << endl;
}

bool ContainsCharInDifferentPlace(const string& source, int charPlace){
	for (unsigned int x = 0; x < source.length(); x++){
		if (x != charPlace && source[x] == source[charPlace]){
			return (true);
		}
	}
	return (false);
}