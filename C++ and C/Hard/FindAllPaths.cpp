#include <iostream> // cout
#include <stdlib.h> // std namespace
#include <vector> // vector
#include <string> // string

/// Author Jared Mavis
/// Username jmavis
/// CodeEval Robot Movements
/// Will print all the possible paths from the top left of a 4x4 grid to the bottom right
using namespace std;

class Node;

/// Checks if the given number is in the range startBounds-endBounds (exclusive end)
bool IsInBounds(int toCheck, int startBounds, int endBounds);
vector<vector<Node* > > GenerateNodeGrid(int rows, int cols);

class Node{
private:
	vector<Node* > neighbors;
	int rowIndex;
	int colIndex;
	bool isMarked; // denotes if the node is currently part of the path
public:
	Node(int rowPos, int colPos){
		rowIndex = rowPos;
		colIndex = colPos;
		isMarked = false;
	}
	/// Will find the neighbors of this node if they have not already been found
	vector<Node* > GetNeighbors(const vector<vector<Node*> >& nodes){
		if (neighbors.size() == 0){
			if (rowIndex+1 < nodes.size()){
				neighbors.push_back(nodes[rowIndex+1][colIndex]);
			}
			if (rowIndex-1 >= 0){
				neighbors.push_back(nodes[rowIndex-1][colIndex]);
			}
			if (colIndex+1 < nodes[0].size()){
				neighbors.push_back(nodes[rowIndex][colIndex+1]);
			}
			if (colIndex-1 >= 0){
				neighbors.push_back(nodes[rowIndex][colIndex-1]);
			}
		}
		return (neighbors);
	}
	bool IsMarked(){return (isMarked);}
	void Mark(){isMarked = true;}
	void UnMark(){isMarked = false;}
};

/// Will hold a 2d array of nodes and will be able to find the numbers of ways to go from 2 indicies of the array
class PathFinder{
private:
	/// Will return the total number of paths from the current point to the goal
	int FindPathsFrom(Node* current, Node* goal){
		if (current == goal){
			return (1);
		}
		vector<Node* > neighbors = current->GetNeighbors(nodes);
		
		bool hasUnsearchedNeighbor = false;
		for (unsigned int i = 0; i < neighbors.size(); i++){
			if (!neighbors[i]->IsMarked()){
				hasUnsearchedNeighbor = true;
			}
		}
		if (neighbors.size() == 0 || !hasUnsearchedNeighbor) {
			return (0);
		}

		current->Mark();
		int pathsFromHere = 0;
		
		for (unsigned int i = 0; i < neighbors.size(); i++){
			if (!neighbors[i]->IsMarked()){
				pathsFromHere += FindPathsFrom(neighbors[i], goal);
			}
		}
		current->UnMark();
		return (pathsFromHere);
	}
	vector<vector<Node* > > nodes;
	int cols;
	int rows;
public:
	PathFinder(const vector<vector<Node* > >& _nodes):nodes(_nodes){
		rows = nodes.size();
		cols = (nodes.size() == 0 ? 0 : nodes[0].size());
	}
	int CalcPathsFrom(int startRowPos, int startColPos, int endRowPos, int endColPos){
		if (!IsInBounds(startRowPos, 0, rows) || !IsInBounds(startColPos, 0, cols) ||
			!IsInBounds(endRowPos, 0, rows) || !IsInBounds(endColPos, 0, cols)){
				cout << "Error input was out of bounds" << endl;
				return (0);
		}
		Node* startNode = nodes[startRowPos][startColPos];
		Node* goalNode = nodes[endRowPos][endColPos];
		return (FindPathsFrom(startNode, goalNode));
	}
};

int main (int argc, char* argv[]){
	int rows = 4;
	int cols = 4;
	vector<vector<Node* > > grid = GenerateNodeGrid(rows, cols);
	PathFinder pathFinder(grid);
	cout << pathFinder.CalcPathsFrom(0,0,rows-1,cols-1) << endl;
}


bool IsInBounds(int toCheck, int startBounds, int endBounds){
	return (startBounds <= toCheck && toCheck < endBounds);
}

vector<vector<Node* > > GenerateNodeGrid(int rows, int cols){
	vector<vector<Node* > > result(rows, vector<Node* >(cols));
	for (int row = 0; row < rows; row++){
		for (int col = 0; col < cols; col++){
			result[row][col] = new Node(row, col);
		}
	}
	return (result);
}