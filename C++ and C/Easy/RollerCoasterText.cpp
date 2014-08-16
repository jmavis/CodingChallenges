#include <iostream> // cout
#include <string> // string
#include <fstream> // file io
#include <stdlib.h> // std lib fns
#include <vector>
#include <sstream> 

using namespace std;

string toRollerCoaster(string& line){
	bool printUpper = true;
	string rollerCoasterLine = "";
	for (int i = 0, length = line.length(); i < length; i++){
		if (isalpha(line[i])){
			if (printUpper) rollerCoasterLine += toupper(line[i]);
			else rollerCoasterLine += tolower(line[i]);
			printUpper = !printUpper;
		} else {
			rollerCoasterLine += line[i];
		}
	}
	return rollerCoasterLine;
}

void printLineInRollerCoasterForm(string& line){
	if (line.length() != 0) {
		cout << toRollerCoaster(line) << endl;
	}
}

/// Author Jared Mavis
/// Username jmavis
/// Code Eval RollerCoaser Conversion
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			string line = lineBuffer;
			printLineInRollerCoasterForm(line);
		}
	}
}