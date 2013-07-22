#include <iostream> // cout
#include <stdlib.h> // std namespace
#include <string> // string
#include <fstream> // file io
#include <vector> // vector

using namespace std;

void ParseLine(string line);
bool IsJollyJumper(int size, const string& numbers);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Jolly Jumpers
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

/// Will break up the given line and will call IsJollyJumper on the input
void ParseLine(string line){
	int sizeEndIndex = line.find(' ');
	int size = atoi(line.substr(0, sizeEndIndex).c_str());

	if (IsJollyJumper(size, line.substr(sizeEndIndex+1))) {
		cout << "Jolly";
	} else {
		cout << "Not jolly";
	}
	cout << endl;
}

/// Will return true if the nuber is a jolly jumper (consecutive absolute differences of sequential integers create the set 1- (n-1))
/// or false other wise
/// A set with one number is considered jolly
bool IsJollyJumper(int size, const string& numbers){
	if (size == 1) return (true);

	vector<bool> counts(numbers.size()-1);
	unsigned int nextNumStart = 0;
	int nextNumEnd = numbers.find(' ');
	int currentNum = atoi(numbers.substr(nextNumStart, nextNumEnd).c_str());
	nextNumStart = nextNumEnd+1;
	int nextNum;
	int dif;

	do {
		nextNumEnd = numbers.find(' ', nextNumStart);
		if (nextNumEnd == string::npos){
			nextNumEnd = numbers.length();
		}
		nextNum = atoi(numbers.substr(nextNumStart, nextNumEnd).c_str());

		dif = abs(currentNum - nextNum);
		if (dif-1 >= 0 && dif-1 < (signed)counts.size()){
			if (counts.at(dif-1) == 1){
				return (false);
			}
			counts[dif-1] = !counts[dif-1];
		} else {
			return false; 
		}
		nextNumStart = nextNumEnd+1;
		currentNum = nextNum;
	} while (nextNumStart < numbers.length());

	return (true);
}