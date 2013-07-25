#include <iostream> // cout
#include <stdlib.h> // std namespace
#include <string> // string
#include <fstream> // file io
#include <vector> // vector

using namespace std;

void ParseLine(string line);
void PrintPairsThatSumToX(vector<int> data, int x);
vector<int> Split(const string& source, char toSplitBy);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Number Pairs
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

/// Will break up the given line and will call PrintPairsThatSumToX on the input
void ParseLine(string line){
	int semiColonIndex = line.find(';');
	int x = atoi(line.substr(semiColonIndex+1).c_str());

	PrintPairsThatSumToX(Split(line.substr(0,semiColonIndex),','), x);
	cout << endl;
}

/// Prints out all the pairs in data that add up to x in asending order
void PrintPairsThatSumToX(vector<int> data, int x){
	bool hasFoundPair = false;

	for (unsigned int i = 0; i < data.size(); i++){
		if (data.at(i) >= x) break;
		for (unsigned int y = i+1; y < data.size(); y++){
			if (data.at(i) + data.at(y) < x){
				continue;
			} else if (data.at(i) + data.at(y) == x){
				if (hasFoundPair){
					cout << ";";
				} else {
					hasFoundPair = true;
				}
				cout << data.at(i) << "," << data.at(y);
			} else {
				break;
			}
		}
	}

	if (!hasFoundPair){
		cout << "NULL";
	}
}

vector<int> Split(const string& source, char toSplitBy){
	vector<int> result;
	string currentPart = "";
	for (unsigned int i = 0; i < source.length(); i++){
		if (i + 1 == source.length()){
			if (source[i] != toSplitBy){
				currentPart += source[i];
			}
			result.push_back(atoi(currentPart.c_str()));
		} else if (source[i] == toSplitBy && currentPart != ""){
			result.push_back(atoi(currentPart.c_str()));
			currentPart = "";
		} else {
			currentPart += source[i];
		}
	}
	return (result);
}