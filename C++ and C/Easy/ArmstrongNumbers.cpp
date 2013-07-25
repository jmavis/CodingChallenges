#include <iostream> // cout
#include <stdlib.h> // std namespace
#include <string> // string
#include <fstream> // file io
#include <math.h> // pow

using namespace std;

void ParseLine(string line);
bool IsArmstongNumber(int num, int size);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Armstrong Numbers
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

/// Will break up the given line and will print out the result of IsArmstongNumber on the line
void ParseLine(string line){
	if (IsArmstongNumber(atoi(line.c_str()), line.length())){
		cout << "True";
	} else {
		cout << "False";
	}
	cout << endl;
}

/// Will return true if the given number is an armstrong number or false otherwise
bool IsArmstongNumber(int num, int size){
	int total = 0;
	double currentDigit;

	for (int currentExponent = 1; pow(10.0, currentExponent-1) <= num; currentExponent++){
		currentDigit = (((int)fmod(num, pow(10.0, currentExponent)))/(int)(pow(10.0, currentExponent-1)));
		total += (int) pow(currentDigit, size);
	}
	return (total == num);
}