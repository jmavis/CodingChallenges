#include <iostream> // cout
#include <stdlib.h> //std
#include <string> // string
#include <fstream> // file io
#include <vector> // vector
#include <algorithm> // count

using namespace std;

bool IsSelfDescribingNumber(string num);
void ParseLine(string line);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Self Describing Numbers
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

/// Will print out the result of IsSelfDescribingNumber of the parsed line
void ParseLine(string line){
	cout << IsSelfDescribingNumber(line) << endl;
}

/// Will return true if the given number as a string is a self describing number or false otherwise
bool IsSelfDescribingNumber(string num){
	vector<int> digitCounts;
	for (unsigned int i = 0; i < num.length() && i < 10; i++){
		digitCounts.push_back(count(num.begin(), num.end(), i+'0'));
	}

	unsigned int index = 0;
	while (index < num.length() && (num[index]-'0') == digitCounts.at(index)){
		index++;
	}
	return (index == num.length());
}