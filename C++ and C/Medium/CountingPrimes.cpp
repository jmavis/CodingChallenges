#include <iostream> // cout
#include <stdlib.h> // std namespace
#include <string> // string
#include <fstream> // file io
#include <vector> // vector

using namespace std;

/// Will break apart the line and will display the result of count primes between the input
void ParseLine(const string& line, vector<int>& pastPrimes);
/// WIll return true if the given number is a prime or false otherwise
bool IsPrime(int toCheck, const vector<int>& pastPrimes);
/// Will return the number of primes between the two numbers inclusivly and will update the past prime list as needed.
int CountPrimesBetween(int start, int end, vector<int>& pastPrimes);
/// Will fill up the pastprimes list with primes up to the given number
void FindPrimesUpTo(int end, vector<int>& pastPrimes);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Counting Primes
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;
	vector<int> foundPrimes;
	foundPrimes.push_back(2);

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			ParseLine(lineBuffer, foundPrimes);
		}
	}
}

void ParseLine(const string& line, vector<int>& pastPrimes){
	int commaIndex = line.find(',');
	int start = atoi(line.substr(0, commaIndex).c_str());
	int end = atoi(line.substr(commaIndex+1).c_str());
	cout << CountPrimesBetween(start, end, pastPrimes) << endl;
}

int CountPrimesBetween(int start, int end, vector<int>& pastPrimes){
	if (start > end) return 0;

	FindPrimesUpTo(start, pastPrimes);

	int primeCount = 0;
	for (int i = start; i <= end; i++){
		if (IsPrime(i, pastPrimes)){
			primeCount++;
			if (i > pastPrimes.back()){
				pastPrimes.push_back(i);
			}
		}
	}
	return (primeCount);
}

bool IsPrime(int toCheck, const vector<int>& pastPrimes){
	for (vector<int>::const_iterator iter = pastPrimes.begin(); iter < pastPrimes.end(); iter++){
		if (*iter == toCheck) return true;
		if ((toCheck % *iter) == 0) return false;
	}
	return true;
}

void FindPrimesUpTo(int end, vector<int>& pastPrimes){
	int currentHighest = pastPrimes.back()+1;
	while (currentHighest <= end){
		if (IsPrime(currentHighest, pastPrimes)){
			pastPrimes.push_back(currentHighest);
		}
		currentHighest++;
	}
}