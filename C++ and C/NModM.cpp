#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <string>
#include <fstream>

using namespace std;

int NModM(int n, int m);
void ParseLine(string line);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval N mod N
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

/// Will parse the line then print out the result of NModN of the parsed line
void ParseLine(string line){
	int commaIndex = line.find(',');
	int n = atoi(line.substr(0,commaIndex).c_str());
	int m = atoi(line.substr(commaIndex+1).c_str());
	cout << NModM(n,m) << endl;
}

/// Will return the result of n mod m without using the modulus function
int NModM(int n, int m){
	int current = n;
	while (current >= m){
		current -= m;
	}
	return (current);
}