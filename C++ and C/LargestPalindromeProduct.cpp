#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <string>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;
/*
int FindLargestPalindromeProduct(int highest);
bool IsPalindrom(double num);

/// Author Jared Mavis
/// Username jmavis
/// Project Euler Largest prime factor
int main (int argc, char* argv[]){
	cout << FindLargestPalindromeProduct(999) << endl;
	string s;
	cin >> s;
}

int FindLargestPalindromeProduct(int highest){
	int highestSoFar = 0;
	for (int i = highest; i > 0; i--){
		for (int x = highest; x > 0; x--){
			if (IsPalindrom(x*i) && x*i > highestSoFar){
				highestSoFar = x*i;
			}
		}
	}
	return (highestSoFar);
}

bool IsPalindrom(double num){
	double maxExponent = 0;
	while (pow(10.0, maxExponent) < num){
		maxExponent++;
	}

	for (int i = 0; i < ceil(maxExponent/2.0); i++){
		//cout << "pow = " << pow(10.0, i) << endl;
		//cout << floor(fmod(num, pow(10.0, i+1))/(pow(10.0, (i)))) << ", " << floor(fmod(num, pow(10.0, (maxExponent-i)))/(pow(10.0, (maxExponent-i-1)))) <<  endl;
		if (floor(fmod(num, pow(10.0, i+1))/(pow(10.0, (i))))  != floor(fmod(num, pow(10.0, (maxExponent-i)))/(pow(10.0, (maxExponent-i-1))))) {
			return (false);
		}
	}
	return (true);
}*/