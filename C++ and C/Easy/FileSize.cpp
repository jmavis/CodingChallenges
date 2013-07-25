#include <iostream> // cout
#include <fstream> // file io

using namespace std;

/// Author Jared Mavis
/// Username jmavis
/// Code Eval File Size
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	int totalSize = 0;

	file.seekg(0, file.end);
	cout << file.tellg() << endl;
}