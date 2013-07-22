#include <iostream> // cout
#include <stdlib.h> // std namespace
#include <string> // string
#include <fstream> // file io

using namespace std;

void PrintWithCapitilizedWords(const string& words);
bool IsLower(const char& character);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Capitilize Words
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			PrintWithCapitilizedWords(lineBuffer);
		}
	}
}

/// Will print out the given sentance with all of the words capitilized
void PrintWithCapitilizedWords(const string& words){
	int asciiDifBetweenCapitialAndNon = 'A' - 'a';
	if (words.size() >= 1){
		if (IsLower(words[0])){
			cout << (char)(words[0] + asciiDifBetweenCapitialAndNon);
		} else {
			cout << words[0];
		}
	} else return;
	for (unsigned int i = 1; i < words.length(); i++){
		if (words[i-1] == ' ' && IsLower(words[i])) {
			cout << (char)(words[i] + asciiDifBetweenCapitialAndNon);
		} else {
			cout << words[i];
		}
	}
	cout << endl;
}

/// Returns true if the given character is a-z or false otherwise
bool IsLower(const char& character){
	return ('a' <= character && character <= 'z');
}