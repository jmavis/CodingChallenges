#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>  

using namespace std;

vector<string> Split(const string& source, char toSplitBy);
void ParseLine(string line);

template <class T>
class MyStack {
private:
	int top;
	int SIZE;
	T* data;

public:
	MyStack(int size){
		SIZE = size;
		top = 0;
		data = new T[SIZE];
	}

	void Push(T toPush){
		if (top + 1 > SIZE){
			cout << "Went over the size limit of " << SIZE << endl;
			exit(1);
		}
		data[top++] = toPush;
	}

	T Pop(){
		if (top == 0){
			cout << "Trying to pop from an empty stack" << endl;
			exit(1);
		}
		return (data[(top--)-1]);
	}

	int Size(){
		return (top);
	}
};

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Detecting Cycles
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

/// will parse the given line apart then put it into the stack data type and print out the alternate entries
void ParseLine(string line){
	vector<string> splitParts = Split(line, ' ');
	MyStack<string> stack(splitParts.size());
	for (unsigned int i = 0; i < splitParts.size(); i++){
		stack.Push(splitParts.at(i));
	}
	bool shouldPrint = true;
	while (stack.Size() > 0){
		if (shouldPrint){
			cout << stack.Pop() << (stack.Size()-1 != 0 ? " " : "");
		} else {
			stack.Pop();
		}
		shouldPrint = !shouldPrint;
	}
	cout << endl;
}

vector<string> Split(const string& source, char toSplitBy){
	vector<string> result;
	string currentPart = "";
	for (unsigned int i = 0; i < source.length(); i++){
		if (i + 1 == source.length()){
			if (source[i] != toSplitBy){
				currentPart += source[i];
			}
			result.push_back(currentPart);
		} else if (source[i] == toSplitBy && currentPart != ""){
			result.push_back(currentPart);
			currentPart = "";
		} else {
			currentPart += source[i];
		}
	}
	return (result);
}