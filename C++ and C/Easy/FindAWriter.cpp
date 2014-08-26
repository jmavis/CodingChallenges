#include <iostream> // cout
#include <stdlib.h> // std namespace
#include <string> // string
#include <fstream> // file io
#include <vector>

using namespace std;

vector<string> split(string line, char delimiter){
	vector<string> lines;
	if (line.length() == 0) return lines;
	
	int nextTokenStart = 0;
	while (line.at(nextTokenStart) == ' '){
		nextTokenStart++;
	}

	string nextLine;
	while (nextTokenStart < line.length()){
		int nextTokenEnd = line.find_first_of(delimiter, nextTokenStart);
		if (nextTokenEnd == string::npos){
			nextTokenEnd = line.length();
		}
		nextLine = line.substr(nextTokenStart, nextTokenEnd-nextTokenStart);
		lines.push_back(nextLine);
		nextTokenStart = nextTokenEnd+1;
	}
	return lines;
}

void printWriter(string codedString, vector<string> indicies){
	string writer = "";
	for (int i = 0; i < indicies.size(); i++){
		writer += codedString.at(atoi(indicies.at(i).c_str())-1);
	}
	cout << writer << endl;
}

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Find A Writer
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	
	string lineBuffer;

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			vector<string> data = split(lineBuffer,'|');
			vector<string> charIdicies = split(data.at(1), ' ');
			printWriter(data.at(0), charIdicies);
		}
	}
}
