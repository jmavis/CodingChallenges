#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <string>
#include <fstream>
#include <vector>

using namespace std;
/*
int ParseLine(string line);
void PrintPrimesLessThan(int primeToFind, vector<int>* foundPrimes);
vector<int>* FindPrimesUpTo(signed int n, vector<int>* pastPrimes);
int FindNextPrime(int startNumber, vector<int>* pastPrimes);
bool IsPrime(int number, vector<int>* pastPrimes);

/// Author Jared Mavis
/// Username jmavis
/// CodeEval Prime Numbers
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;
	vector<int>* foundPrimes = new vector<int>();
	foundPrimes->push_back(2);

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			int primeToFind = ParseLine(lineBuffer);
			foundPrimes = FindPrimesUpTo(primeToFind, foundPrimes);
			PrintPrimesLessThan(primeToFind, foundPrimes);
		}
	}
}

/// Will print out the result of SumOfDigits on the line
int ParseLine(string line){
	return (atoi(line.c_str()));
}

/// Prints the primes less than the given number that have been found in the past primes
void PrintPrimesLessThan(signed int n, vector<int>* pastPrimes){
	if (n > pastPrimes->back()){
		FindPrimesUpTo(n, pastPrimes);
	}
	for (unsigned int i = 0; i < pastPrimes->size(); i++){
		if (pastPrimes->at(i) < n){
			cout << pastPrimes->at(i) << (i+1 < pastPrimes->size() &&  pastPrimes->at(i+1) < n ? "," : "");
		} else {
			break;
		}
	}
	cout << endl;
}

// will update the pastPrimes up to the given number
vector<int>* FindPrimesUpTo(int n, vector<int>* pastPrimes){
	int currentNumber = pastPrimes->back() + 1; // start looking for the next prime at the last prime + 1
	while (n > currentNumber){
		currentNumber = FindNextPrime(currentNumber, pastPrimes);
		pastPrimes->push_back(currentNumber);
		currentNumber++;
	}
	return (pastPrimes);
}

int FindNextPrime(int startNumber, vector<int>* pastPrimes){
	int currentNumber = startNumber;
	while (!IsPrime(currentNumber, pastPrimes)){
		currentNumber++;
	}
	return (currentNumber);
}

/// Returns true if the number is a prime or false otherwise
bool IsPrime(int number, vector<int>* pastPrimes){
	for (unsigned int i = 0; i < pastPrimes->size(); i++){
		if (number == pastPrimes->at(i)){
			return (true);
		}
		if (number % pastPrimes->at(i) == 0){
			return (false);
		}
	}
	return (true);
}*/