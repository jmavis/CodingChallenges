#include <iostream> // cout
#include <stdlib.h> // std namespace
#include <string> // string
#include <fstream> // file io

using namespace std;

struct CharNode{
public:
	bool locked;
	char character;

	CharNode(){}

	CharNode(char _character){
		character = _character;
		locked = false;
	}
};

class CharGrid{
private:
	CharNode* grid[3][4];

public:
	CharGrid(){
		grid[0][0] = new CharNode('A');
		grid[0][1] = new CharNode('B');
		grid[0][2] = new CharNode('C');
		grid[0][3] = new CharNode('E');
		grid[1][0] = new CharNode('S');
		grid[1][1] = new CharNode('F');
		grid[1][2] = new CharNode('C');
		grid[1][3] = new CharNode('S');
		grid[2][0] = new CharNode('A');
		grid[2][1] = new CharNode('D');
		grid[2][2] = new CharNode('E');
		grid[2][3] = new CharNode('E');
	}

	CharNode* getNodeAt(int row, int col){
		if (row < 0 || row > 2) return NULL;
		if (col < 0 || col > 3) return NULL;
		CharNode* node = grid[row][col];
		if (node->locked) return NULL;
		else return node;
	}

	CharNode* getAboveFrom(int row, int col){
		return getNodeAt(row-1, col);
	}

	CharNode* getBelowFrom(int row, int col){
		return getNodeAt(row+1, col);
	}

	CharNode* getLeftFrom(int row, int col){
		return getNodeAt(row, col-1);
	}

	CharNode* getRightFrom(int row, int col){
		return getNodeAt(row, col+1);
	}
};

bool canMakeSequenceFromPosition(string sequence, CharGrid& grid, int row, int col){
	if (sequence.length() == 0) return true;
	CharNode* currentNode = grid.getNodeAt(row, col);

	if (currentNode == NULL){
		return false;	
	}
	string remaingSequence;
	if (currentNode->character == sequence[0]){
		currentNode->locked = true;
		remaingSequence = sequence.substr(1);
	} else {
		return false;
	}
	if (canMakeSequenceFromPosition(remaingSequence, grid, row-1, col) || 
	    canMakeSequenceFromPosition(remaingSequence, grid, row+1, col) ||
		canMakeSequenceFromPosition(remaingSequence, grid, row, col-1) ||
		canMakeSequenceFromPosition(remaingSequence, grid, row, col+1)){
			currentNode->locked = false;
			return true;
	} else {
		currentNode->locked = false;
		return false;
	}
}

bool sequenceInGrid(string sequence){
	CharGrid grid;
	for (int row = 0; row <= 2; row++){
		for (int col = 0; col <= 3; col++){
			if (canMakeSequenceFromPosition(sequence, grid, row, col)){
				return true;
			}
		}
	}
	return false;
}

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Word Search
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	
	string lineBuffer;

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			cout << (sequenceInGrid(lineBuffer) ? "True" : "False") << endl;
		}
	}
}
