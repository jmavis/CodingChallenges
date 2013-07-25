#include <iostream> // cout
#include <stdlib.h> // std namespace
#include <string> // string
#include <fstream> // file io
#include <vector> // vector
#include <algorithm> // sort

using namespace std;

void ParseLine(const string& line);
void PrintStringList(const string& current, int depth, const string& pool);
bool IsAtEnd(const string& current, char endOfPool);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval String List
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

/// Will parse the line apart and will call PrintStringList with the correct arguments
void ParseLine(const string& line){
	int commaIndex = line.find(',');
	int len = atoi(line.substr(0, commaIndex).c_str());
	string pool = "";

	for (unsigned int i = commaIndex+1; i < line.length(); i++){
		if (pool.find(line[i]) == string::npos){
			pool += line[i];
		}
	}
	sort(pool.begin(), pool.end());
	PrintStringList("", len, pool);
}

/// Will print out all the combinations that can be made from the pool in alpabetical order with a length of the initial depth
void PrintStringList(const string& current, int depth, const string& pool){
	if (depth == 0){
		cout << current << (IsAtEnd(current, pool[pool.length()-1]) ? "\n" : ",");
		return;
	}

	for (unsigned int i = 0; i < pool.length(); i++){
		PrintStringList(current+pool[i], depth-1, pool);
	}
}

/// Will return true if the current string consists only of the end of the pool
bool IsAtEnd(const string& current, char endOfPool){
	for (unsigned int i = 0; i < current.length(); i++){
		if (current[i] != endOfPool){
			return (false);
		}
	}
	return (true);
}