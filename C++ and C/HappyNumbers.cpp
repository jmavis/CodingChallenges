#include <iostream> // cout
#include <string> // string
#include <fstream> // file io
#include <math.h> // pow, fmod
#include <vector> // vector
#include <algorithm> //find

using namespace std;

int SumSquaredDigits(int num);
bool IsHappyNumber(int num);
void ParseLine(string line);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Happy Numbers
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

/// will parse the given line apart then print the result of IsHappyNumber of the line
void ParseLine(string line){
	cout << IsHappyNumber(atoi(line.c_str())) << endl;
}

// Will return true if the given number is a happy number of false otherwise
bool IsHappyNumber(int num){
	vector<int> pastSquaredSums;
	int sumOfSquaredDigits = num;

	while (sumOfSquaredDigits != 1){
		sumOfSquaredDigits = SumSquaredDigits(sumOfSquaredDigits);
		if (find(pastSquaredSums.begin(), pastSquaredSums.end(), sumOfSquaredDigits) != pastSquaredSums.end()){
			return (false);
		} else {
			pastSquaredSums.push_back(sumOfSquaredDigits);
		}
	} 
	return (true);
}

/// Will return the result of adding the squares of all the digits
int SumSquaredDigits(int num){
	int currentModulus = 1;
	int total = 0;
	do {
		total += (int)pow(floor((fmod(num, pow(10.0, currentModulus))) / pow(10.0, currentModulus-1)), 2);
		currentModulus++;
	} while (pow(10.0, currentModulus-1) <= num);
	return (total);
}