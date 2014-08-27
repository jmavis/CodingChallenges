#include <iostream> // cout
#include <stdlib.h> // std namespace
#include <string> // string
#include <fstream> // file io

using namespace std;

int calculateCoinsToMake(int amount){
	if (amount <= 0) return 0;
	int numCoins = 0;

	while (amount > 0){
		if (amount >=5){
			amount -= 5;
		} else if (amount >= 3){
			amount -= 3;
		} else{
			amount -= 1;
		}
		numCoins++;
	}
	return numCoins;
}

void printCoinsToMakeAmount(int amount){
	cout << calculateCoinsToMake(amount) << endl;
}

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Minimum Coins
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	
	string lineBuffer;

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			printCoinsToMakeAmount(atoi(lineBuffer.c_str()));
		}
	}
}
