#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>  

using namespace std;

void PrintMissingLetters(string source);
vector<char> GenerateAlphabet();

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Panagrams
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			PrintMissingLetters(lineBuffer);
		}
	}
}

void PrintMissingLetters(string source){
	vector<char> alphabet = GenerateAlphabet();
	bool hasPrinted = false;
	transform(source.begin(), source.end(), source.begin(), ::tolower);
	for (unsigned int i = 0; i < alphabet.size(); i++){
		if (source.find(alphabet.at(i)) == string::npos){
			cout << alphabet.at(i);
			hasPrinted = true;
		}
	}
	if (!hasPrinted){
		cout << "NULL";
	}
	cout << endl;
}

vector<char> GenerateAlphabet(){
	vector<char> result;
	for (int i = 'a'; i <= 'z'; i++){
		result.push_back(char(i));
	}
	return (result);
}