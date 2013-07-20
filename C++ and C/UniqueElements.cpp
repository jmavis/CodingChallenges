#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void PrintUniqueElements(string line){
	for (unsigned int i = 0; i < line.length(); i++){
		if (line[i] == ',') continue;
		if (i+2 >= line.length()){
			cout << line[i];
		} else if (line[i] != line[i+2]){
			cout << line[i] << ",";
		}
	}
	cout << endl;
}

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Unique Elements
/// Will the unique values from the sorted list on each line
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			PrintUniqueElements(lineBuffer);
		}
	}
}
