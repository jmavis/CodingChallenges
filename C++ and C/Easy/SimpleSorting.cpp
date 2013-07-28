#include <iostream> // cout
#include <stdlib.h> // std namespace
#include <string> // string
#include <fstream> // file io
#include <vector> // vector
#include <sstream> // stringstream 
#include <iomanip> // set precision
#include <algorithm> // sort

using namespace std;

void ParseLine(const string& line);
vector<string> Split(const string& source, char toSplitBy);
vector<string> Merge(const vector<string>& left, const vector<string>& right);
vector<string> MergeSortHelper(vector<string>& toSort);


/// Author Jared Mavis
/// Username jmavis
/// Code Eval Simple Sorting
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

/// Will parse the line apart and will create a spiral printer with the correct data and will ask it to print in a spiral
void ParseLine(const string& line){
	vector<string> data = Split(line, ' ');
	//data = MergeSortHelper(data);
	sort(data.begin(), data.end());
	for (unsigned int i = 0; i < data.size(); i++){
		cout << data[i] << ((i+1<data.size())?" ": "\n");
	}
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
			currentPart = "";
		} else if (source[i] == toSplitBy && currentPart != ""){
			result.push_back(currentPart);
			currentPart = "";
		} else {
			currentPart += source[i];
		}
	}
	return (result);
}

vector<string> Merge(const vector<string>& left, const vector<string>& right){
	unsigned int leftIndex = 0;
	unsigned int rightIndex = 0;
	vector<string> result;

	while (leftIndex < left.size() && rightIndex < right.size()){
		if (left[leftIndex] < right[rightIndex]){
			result.push_back(left[leftIndex]);
			leftIndex++;
		} else {
			result.push_back(right[rightIndex]);
			rightIndex++;
		}
	}
	if (leftIndex == left.size()){
		for (unsigned int i = rightIndex; i < right.size(); i++){
			result.push_back(right[i]);
		}
	} else {
		for (unsigned int i = leftIndex; i < left.size(); i++){
			result.push_back(left[i]);
		}
	}
	return (result);
}

vector<string> MergeSortHelper(vector<string>& toSort){
	if (toSort.size() <= 1){
		return toSort;
	}

	vector<string> left;
	vector<string> right;
	int middle = toSort.size()/2;
	for (int i = 0; i < middle; i++){
		left.push_back(toSort[i]);
	}
	for (unsigned int i = middle; i < toSort.size(); i++){
		right.push_back(toSort[i]);
	}
	
	left = MergeSortHelper(left);
	right = MergeSortHelper(right);

	return (Merge(left, right));
}