#include <iostream> // cout
#include <string> // string
#include <fstream> // file io
#include <stdlib.h> // std lib fns
#include <math.h> // pow/sqrt

using namespace std;


/// A node in a doubly linked list
class Point{
public:	
	int x;
	int y;
	Point* next;
	Point* prev;

	Point(int xPos, int yPos){
		x = xPos;
		y = yPos;
		next = NULL;
		prev = NULL;
	}
	double Distance(const Point& point){
		return (sqrt((pow(x - point.x, 2.0) + pow(y - point.y, 2.0))));
	}
};

class PointList{
private:
	Point* first; // the first point of a doubly linked list of points sorted by x value
	double currentMinDistance;

	double FindMinimumDistanceInRangeOf(Point* point, double  distance){
		Point* lowerIter = point->prev;
		while (lowerIter != NULL && lowerIter->x >= point->x - distance){
			double curDistance = point->Distance(*lowerIter);
			if (curDistance < distance){
				distance = curDistance;
			}
			lowerIter = lowerIter->prev;
		}
		Point* upperIter = point->next;
		while (upperIter != NULL && upperIter->x >= point->x - distance){
			double curDistance = point->Distance(*upperIter);
			if (curDistance < distance){
				distance = curDistance;
			}
			upperIter = upperIter->next;
		}
		return distance;
	}

public:
	PointList(){
		first = NULL;
		currentMinDistance = 10000;
	}

	void PrintMinimum(){
		if (currentMinDistance >= 10000){
			cout << "INFINITY";
		} else {
			cout << currentMinDistance;
		}
		cout << endl;
	}

	void Insert(int x, int y){
		Point* newPoint = new Point(x,y);
		if (first == NULL) {
			first = newPoint;
			return;
		}
		
		Point* currentPoint = first;
		Point* prev;
		while (currentPoint != NULL && newPoint->x > currentPoint->x){
			prev = currentPoint;
			currentPoint = currentPoint->next;
		}

		if (currentPoint == NULL){
			prev->next = newPoint;
			newPoint->prev = prev;
		} else if (currentPoint == first){
			first = newPoint;
			newPoint->next = currentPoint;
		} else {
			currentPoint->prev->next = newPoint;
			newPoint->next = currentPoint;
			newPoint->prev = currentPoint->prev;
			currentPoint->prev = newPoint;
		}

		currentMinDistance = FindMinimumDistanceInRangeOf(newPoint, currentMinDistance);
	}
};

void InsertLine(PointList& pointlist, const string& line);

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Closest Pair
/// Will read in a set of pairs and will return the closest distance
int main (int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;

	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0){
			continue; //ignore all empty lines
		} else {
			int setSize = atoi(lineBuffer.c_str());
			PointList pointList;
			if (setSize == 0) break;
			while (!file.eof() && setSize > 0){
				getline(file, lineBuffer);
				InsertLine(pointList, lineBuffer);
				setSize--;
			}
			pointList.PrintMinimum();
		}
	}
}

void InsertLine(PointList& pointlist, const string& line){
	int spaceIndex = line.find(' ');
	int firstNum = atoi(line.substr(0,spaceIndex).c_str());
	int secondNum = atoi(line.substr(spaceIndex).c_str());
	//cout << "adding " << firstNum << ", " << secondNum << endl;
	pointlist.Insert(firstNum, secondNum);
}