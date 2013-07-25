#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <string>
#include <fstream>
#include <vector>
/*
using namespace std;

void PrintVector(vector<string>& toPrint){
	for (int i = 0; i < toPrint.size() && toPrint[i] != ""; i++){
		cout << toPrint[i] << endl;
	}
}

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Longest Line
/// Will print the n longest linst found in a file
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;

	getline(file, lineBuffer);
	int numLines = atoi(lineBuffer.c_str());

	vector<string> lines; // stores from high to low
	for (int i = 0; i < numLines; i++){
		lines.push_back("");
	}

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			if (lineBuffer.length() > lines.back().length()){
				int index = lines.size()-1;
				while (index-1 >= 0 && lineBuffer.length() > lines[index-1].length()){
					index--;
				}
				string temp = lines[index];
				lines[index] = lineBuffer; 
				for (int i = index+1; i < lines.size(); i++){
					string copy = lines[i];
					lines[i] = temp;
					if (i + 1 < lines.size()){
						temp = copy;
					}
				}
			}
		}
	}
	PrintVector(lines);
}
*/