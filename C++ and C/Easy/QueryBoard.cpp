#include <iostream> // cout
#include <stdlib.h> // std namespace
#include <string> // string
#include <fstream> // file io

using namespace std;

class QueryBoard{
private:
	int SIZE;
	int data[256][256];
	
public:
	QueryBoard(){
		SIZE = 256;
		for (int row = 0; row < SIZE; row++){
			SetRow(row, 0);
		}
	}

	void SetRow(int row, int value){
		for (int col = 0; col < SIZE; col++){
			data[row][col] = value;
		}
	}

	void SetCol(int col, int value){
		for (int row = 0; row < SIZE; row++){
			data[row][col] = value;
		}
	}

	int QueryRow(int row){
		int total = 0;
		for (int col = 0; col < SIZE; col++){
			total += data[row][col];
		}
		return (total);
	}

	int QueryCol(int col){
		int total = 0;
		for (int row = 0; row < SIZE; row++){
			total += data[row][col];
		}
		return (total);
	}
};

void ParseLine(QueryBoard& board, const string& line);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Query Board
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;
	QueryBoard board;

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			ParseLine(board, lineBuffer);
		}
	}
	cin >> lineBuffer;
}

/// Will parse the line then perform the instruction on the board
void ParseLine(QueryBoard& board, const string& line){
	int startOfParamsIndex = line.find(' ');
	if (line.substr(0, 5) == "Query"){
		int queryParam = atoi(line.substr(startOfParamsIndex).c_str());
		if (line.substr(5, 3) == "Col"){
			cout << board.QueryCol(queryParam) << endl;
		} else {
			cout << board.QueryRow(queryParam) << endl;
		}
	} else {
		int secondParamIndex = line.find(' ', startOfParamsIndex+1);
		int index = atoi(line.substr(startOfParamsIndex, secondParamIndex-startOfParamsIndex).c_str());
		int value = atoi(line.substr(secondParamIndex).c_str());
		if (line.substr(3, 3) == "Col"){
			board.SetCol(index, value);
		} else {
			board.SetRow(index, value);
		}
	}
}