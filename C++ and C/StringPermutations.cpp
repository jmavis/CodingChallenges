#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
/*
void ParseLine(string line);
void PrintPermutationsOf(string s);
void PrintPermutationsHelper(string base, string pool, vector<string>* permutationsFound);

/// Author Jared Mavis
/// Username jmavis
/// CodeEval String Permutations
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

/// Will call PrintPermutationsOf with the given line
void ParseLine(string line){
	PrintPermutationsOf(line);
}

/// Will find the permutations of the given string and print them out alphabetically in a comma sorted list
void PrintPermutationsOf(string s){
	sort(s.begin(), s.end()); // Makes printing alphabetically easier if sorted now rather than sorting the permutations
	vector<string>* permutations = new vector<string>();
	PrintPermutationsHelper("", s, permutations);
	for (unsigned int i = 0; i < permutations->size(); i++){
		cout << permutations->at(i) << (i+1 < permutations->size() ? "," : "");
	}
	cout << endl;
}

/// Will find the perumations based of the given pool and add it to the combinations found
void PrintPermutationsHelper(string base, string pool, vector<string>* permutationsFound){
	if (pool.length() == 0){
		permutationsFound->push_back(base);
		return;
	}
	for (unsigned int i = 0; i < pool.length(); i++){
		PrintPermutationsHelper(base + pool[i], pool.substr(0,i) + pool.substr(i+1), permutationsFound);
	}
}*/