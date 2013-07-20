#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <string>
#include <fstream>
/*
using namespace std;

void ParseLine(string line);
int MultiplesOfNumber(int num, int base);


/// Author Jared Mavis
/// Username jmavis
/// CodeEval Challenge Multiples of a Number
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
	cin >> lineBuffer;
}

/// Will print out the result of MultiplesOfNumber on the line
/// after parsing it apart
void ParseLine(string line){
	int firstNumberIndex = line.find(',');
	string firstNumberString = line.substr(0, firstNumberIndex);
	string secondNumberString = line.substr(firstNumberIndex+1);
	int firstNumber = atoi(firstNumberString.c_str());
	int secondNumber = atoi(secondNumberString.c_str());
	cout << MultiplesOfNumber(firstNumber, secondNumber) << endl;
}

/// Will go find the smallest multiple of the base that is greater than the given number
int MultiplesOfNumber(int num, int base){
	int multiplier = 0;
	int absNum = abs(num);
	while (absNum > (base * multiplier)){
		multiplier++;
	}
	if (num < 0){ // handle negatives
		multiplier -=1;
		multiplier *= -1;
	}
	return (base * multiplier);
}*/