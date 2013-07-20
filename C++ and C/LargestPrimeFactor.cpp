#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
/*
using namespace std;

double FindLargestPrimeFactor(double number);
double FindNextPrime(double startNumber, vector<double>* pastPrimes);
bool IsPrime(double number, vector<double>* pastPrimes);

/// Author Jared Mavis
/// Username jmavis
/// Project Euler Largest prime factor
int main (int argc, char* argv[]){
	cout << FindLargestPrimeFactor(600851475143) << endl;
	string s;
	cin >> s;
}

double FindLargestPrimeFactor(double number){
	double highestPrimeFactorFound = number;
	vector<double>* primesFound = new vector<double>();
	primesFound->push_back(2);
	cout << "num = " << number << endl;
	while (number >= pow(primesFound->back(),2)){
		int nextPrime = FindNextPrime(primesFound->back()+1, primesFound);
		//cout << "Next prime = " << nextPrime << endl;
		if (fmod(number, nextPrime) == 0){
			highestPrimeFactorFound = nextPrime;
			cout << "Highest prime = " << highestPrimeFactorFound << endl;
		}
		primesFound->push_back(nextPrime);
	}
	return (primesFound->back());
}

double FindNextPrime(double startNumber, vector<double>* pastPrimes){
	double currentNumber = startNumber;
	while (!IsPrime(currentNumber, pastPrimes)){
		currentNumber++;
	}
	return (currentNumber);
}

/// Returns true if the number is a prime or false otherwise
bool IsPrime(double number, vector<double>* pastPrimes){
	for (double i = 0; i < pastPrimes->size(); i++){
		if (number == pastPrimes->at(i)){
			return (true);
		}
		if (fmod(number, pastPrimes->at(i)) == 0){
			return (false);
		}
	}
	return (true);
}*/