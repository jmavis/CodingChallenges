#include <iostream> // cout
#include <string> // string
#include <fstream> // file io

using namespace std;

/// Will find the next to last word in the given string or will return an empty string if there is not one
string FindPenultimateWord(const string& source);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Penultimate Word
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			cout << FindPenultimateWord(lineBuffer) << endl;
		}
	}
}

string FindPenultimateWord(const string& source){
	string currentWord = "";
	string lastWord = "";

	for (unsigned int i = 0; i < source.length(); i++){
		if (i + 1 == source.length()){
			if (lastWord != "") break;
			return "";
		} else if (source.at(i) == ' ' && currentWord != ""){
			lastWord = currentWord;
			currentWord = "";
		} else {
			currentWord += source.at(i);
		}
	}
	return lastWord;
}