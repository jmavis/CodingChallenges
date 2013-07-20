#include <iostream> // cout
#include <stdlib.h> //std
#include <string> // string
#include <fstream> // file io
#include <math.h> // pow

using namespace std;

int ConvertHexToDec(string hexNum);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Hex to Dec
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			cout << ConvertHexToDec(lineBuffer) << endl;
		}
	}
}

int ConvertHexToDec(string hexNum){
	int exponent = 0;
	int total = 0;
	int currentNum;
	char currentDigit;

	for(int i = hexNum.length()-1; i >= 0; i--){
		currentDigit = hexNum[i];
		if ('0' <= currentDigit && currentDigit <= '9'){
			currentNum = currentDigit - '0';
		} else {
			currentNum = currentDigit - 'a' + 10;
		}

		total += (currentNum * pow(16.0, exponent++));
	}
	return (total);
}