#include <iostream> // cout
#include <stdlib.h> // std namespace
#include <string> // string
#include <fstream> // file io

using namespace std;
int ExaluatePrefixExpresion(const string& data);
int FindValueFrom(const string& data, int& index);
bool IsOperation(const string& toCheck);
string GetNextPart(const string& data, int& start, const char& endMark);
int PerformOperaction(const int& left, const int& right, const char& operation);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Prefix Expresion
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			cout << ExaluatePrefixExpresion(lineBuffer) << endl;
		}
	}
}

/// Will evaluate the prefix expresion and will return the result
/// Assumes the elements are space seperated so + A B
int ExaluatePrefixExpresion(const string& data){
	int index = 0;
	return (FindValueFrom(data, index));
}

/// Will find the value of the prefix expresion starting from the given index and then will increment the index by reference
int FindValueFrom(const string& data, int& index){
	char operation;
	string nextPart = GetNextPart(data, index, ' ');
	if (nextPart.length() == 1 && IsOperation(nextPart)){
		operation = nextPart[0];
	} else {
		return (atoi(nextPart.c_str()));
	}
	int leftValue = FindValueFrom(data, index);
	int rightValue = FindValueFrom(data, index);
	int result = PerformOperaction(leftValue, rightValue, operation);
	return (result);
}

/// Will return true if the operation is one that is supported
bool IsOperation(const string& toCheck){
	return (toCheck == "+" || toCheck == "/" || toCheck == "*");
}

/// Will return the next part as defined from the start to the first instance of the end mark or the end of the string
/// will move the start value to the place after the end marker
string GetNextPart(const string& data, int& start, const char& endMark){
	while (data[start] == endMark){
		start++;
	}
	int nextPartEndIndex = data.find(endMark, start);
	if (nextPartEndIndex == string::npos){
		nextPartEndIndex = data.length();
	}
	string result = data.substr(start, nextPartEndIndex-start);
	start = nextPartEndIndex+1;
	return (result);
}

/// Will return the result of the given operation on the left and right ints
int PerformOperaction(const int& left, const int& right, const char& operation){
	switch (operation){
	case '+':
		return (left + right);
	case '/':
		return (left / right);
	case '*':
		return (left * right);
	}
}