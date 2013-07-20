#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <string>
#include <fstream>

using namespace std;

char HasTrailingString(string toCheck);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Trailing String
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			cout << HasTrailingString(lineBuffer) << endl;
		}
	}
}


/// Will return '1' if the trailing string occurs after the main string or 
/// '0' otherwise
char HasTrailingString(string toCheck){
	int commaIndex = toCheck.find(',');
	int aIndex = commaIndex-1;
	int bIndex = toCheck.length()-1;

	while (bIndex!=commaIndex){
		if (aIndex < 0 || toCheck[bIndex] != toCheck[aIndex]){
			return ('0');
		}
		bIndex--;
		aIndex--;
	}
	return ('1');
}