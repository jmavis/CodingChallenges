#include <iostream> // cout
#include <stdlib.h> // std namespace
#include <string> // string
#include <fstream> // file io
#include <vector> // vector

using namespace std;

template <class T>
class SpiralPrinter{
private:
	class Entry{
	private:
		T value;
		bool hasBeenVisited;
	public:
		Entry(){}
		Entry(T _value){
			value = _value;
			hasBeenVisited = false;
		}
		bool HasBeenVisited(){
			return (hasBeenVisited);
		}
		T Visit(){
			if (hasBeenVisited){
				cout << "Attempting to revisit an entry." << endl;
				exit(0);
			}
			hasBeenVisited = true;
			return (value);
		}
	};
	class Mover{
	private:
		enum Direction{
			right,
			down,
			left,
			up,
			none
		};
		Direction currentDirection;
		vector<vector<Entry> > entries;
		bool CanGoInDirection(Direction direction, const int& rowIndex, const int& colIndex){
			switch (direction){
			case down:
				return (rowIndex+1 < entries.size() && !entries[rowIndex+1][colIndex].HasBeenVisited());
			case up:
				return (rowIndex-1 >= 0 && !entries[rowIndex-1][colIndex].HasBeenVisited());
			case right:
				return (colIndex+1 < entries[0].size() && !entries[rowIndex][colIndex+1].HasBeenVisited());
			case left:
				return (colIndex-1 >= 0 && !entries[rowIndex][colIndex-1].HasBeenVisited());
			case none:
				return (false);
			}
			return (false);
		}
		void MoveInDirection(Direction direction, int& rowIndex, int& colIndex){
			switch (direction){
			case right:
				colIndex++;
				break;
			case left:
				colIndex--;
				break;
			case down:
				rowIndex++;
				break;
			case up:
				rowIndex--;
				break;
			}
		}
		Direction GetNextDirection(Direction direction, const int& rowIndex, const int& colIndex){
			Direction startingDirection = direction;
			do {
				direction = static_cast<Direction>((int)direction+1);
				
				if (direction == none){
					direction = right;
				}
				if (direction == startingDirection){
					return (none);
				}
			} while (!CanGoInDirection(direction, rowIndex, colIndex) && direction != startingDirection);
			return (direction);
		}
	public:
		Mover(vector<vector<Entry> > _entries){
			currentDirection = right;
			entries = _entries;
		}
		bool MoveNext(int& rowIndex, int& colIndex){
			if (currentDirection == none){
				cout << Visit(rowIndex, colIndex);
				return (false);
			}
			if (CanGoInDirection(currentDirection, rowIndex, colIndex)){
				cout << Visit(rowIndex, colIndex) << " ";
				MoveInDirection(currentDirection, rowIndex, colIndex);
				return (true);
			} else {
				currentDirection = GetNextDirection(currentDirection, rowIndex, colIndex);
				return (MoveNext(rowIndex, colIndex));
			}
		}
		T Visit(const int& rowIndex, const int& colIndex){
			return (entries[rowIndex][colIndex].Visit());
		}
	};
	Mover* mover;
	
	vector<vector<Entry> > GenerateEntries(const vector<T>& data, int rows, int cols){
		rows--;
		cols--;
		vector<vector<Entry> > result(rows, vector<Entry>(cols));
		for (int row = 0; row < rows; row++){
			for (int col = 0; col < cols; col++){
				result[row][col] = Entry(data[((row*cols) + col) ]);
			}
		}
		return (result);
	}
public:
	SpiralPrinter(const vector<T>& data, int rows, int cols){
		mover = new Mover(GenerateEntries(data, rows, cols));
	}
	void Print(){
		int rowIndex = 0;
		int colIndex = 0;
		while (mover->MoveNext(rowIndex, colIndex)){}
		cout << endl;
	}
};

void ParseLine(const string& line);
vector<string> Split(const string& source, char toSplitBy);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Spiral Printing
/// Will read in a line in the form of rows;cols;d1 d2 d3....
/// and will print it out in a spiral
///  1   2   3
///  8   9   4
///  7   6   5
///  = 1 2 3 4 5 6 7 8 9
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

/// Will parse the line apart and will create a spiral printer with the correct data and will ask it to print in a spiral
void ParseLine(const string& line){
	int firstNumEnd = line.find(';');
	int rows = atoi(line.substr(0,firstNumEnd).c_str());
	int secondNumEnd = line.find(';', ++firstNumEnd);
	int cols = atoi(line.substr(firstNumEnd,secondNumEnd-firstNumEnd).c_str());

	vector<string> data = Split(line.substr(++secondNumEnd), ' ');
	SpiralPrinter<string> printer(data, rows+1, cols+1);
	printer.Print();
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