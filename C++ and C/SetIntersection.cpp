#include <iostream> // cout
#include <string> // string
#include <fstream> // file io
#include <vector> // vector
#include <algorithm> //find

using namespace std;

string FindIntersection(const vector<string>& set1, const vector<string>& set2);
void ParseLine(string line);
vector<string> Split(const string& source, char toSplitBy);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Set Intesection
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
}

/// will parse the given line apart then print the result of FindIntersection of the line
void ParseLine(string line){
	int semiColonIndex = line.find(';');
	string firstSet = line.substr(0,semiColonIndex);
	string secondSet = line.substr(semiColonIndex+1);
	cout << FindIntersection(Split(firstSet, ','), Split(secondSet, ',')) << endl;
}

/// Returns a string consisting of the comma seperated list of the intersection of the given vectors
string FindIntersection(const vector<string>& set1, const vector<string>& set2){
	vector<string>::const_iterator set1Iterator = set1.begin();
	vector<string>::const_iterator set2Iterator = set2.begin();
	while (set1Iterator != set1.end() && find(set2.begin(), set2.end(), *set1Iterator) == set2.end()){
		set1Iterator++;
	}
	if (set1Iterator == set1.end()) return "";
	string intersection = "";
	set2Iterator = find(set2.begin(), set2.end(), *set1Iterator);

	while (set1Iterator != set1.end() && set2Iterator != set2.end() && *set1Iterator == *set2Iterator){
		intersection += *set1Iterator;
		set1Iterator++;
		set2Iterator++;
		if (set1Iterator != set1.end() && set2Iterator != set2.end() && *set1Iterator == *set2Iterator){
			intersection += ",";
		}
	}
	return (intersection);
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