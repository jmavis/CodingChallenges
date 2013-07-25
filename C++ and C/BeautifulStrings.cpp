#include <iostream> // cout
#include <stdlib.h> // std namespace
#include <string> // string
#include <fstream> // file io
#include <map> // map
#include <vector> // vector
#include <algorithm> // reverse, sort

using namespace std;

int CalculateStringBeauty(const string& str);
bool IsLetter(const char& toCheck);

/// Author Jared Mavis
/// Username jmavis
/// Facebook Beautiful Strings
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			cout << CalculateStringBeauty(lineBuffer) << endl;
		}
	}
}

/// Will return the beauty of the given string as defined here https://www.codeeval.com/open_challenges/83/
int CalculateStringBeauty(const string& str){
	map<char, int> charCounts;
	char nextChar;
	for (unsigned int i = 0; i < str.length(); i++){
		nextChar = str[i];
		if (IsLetter(nextChar)){
			if ('A' <= nextChar && nextChar <= 'Z'){
				nextChar -= 'A';
				nextChar += 'a';
			}
			if (charCounts.find(nextChar) != charCounts.end()){
				charCounts.at(nextChar)++;
			} else {
				charCounts[nextChar] = 1;
			}
		}
	}

	vector<int> sortedCounts;

	for (map<char, int>::iterator iter = charCounts.begin(); iter != charCounts.end(); iter++){
		sortedCounts.push_back(iter->second);
	}

	sort(sortedCounts.begin(), sortedCounts.end());
	reverse(sortedCounts.begin(), sortedCounts.end());

	int total = 0;
	vector<int>::iterator countsIter = sortedCounts.begin();
	for (int i = 26; i >= 0 && countsIter != sortedCounts.end(); i--){
		total += i * (*countsIter);
		countsIter++;
	}
	return (total);
}

/// Returns true if the given character is a letter or false otherwise
bool IsLetter(const char& toCheck){
	return (('a' <= toCheck && toCheck <= 'z') || ('A' <= toCheck && toCheck <= 'Z'));
}