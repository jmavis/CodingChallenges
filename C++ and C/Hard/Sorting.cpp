#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;
/*
typedef void (*SortMethod)(vector<int>&);
void Swap(int i, int j, vector<int>& toSort);
vector<int> MakeReverseList(int max);
vector<int> MakeOrderedList(int max);
void PrintVector(vector<int>& toPrint);
bool IsSorted(vector<int>& toTest);

void TestSort(SortMethod sortMethod, vector<int> toSort, string name){
	clock_t start;
	clock_t end;
	start = clock();
	sortMethod(toSort);
	end = clock();

	double timeTaken = double(end - start) / CLOCKS_PER_SEC;
	cout << name << " took " << timeTaken << " seconds\n" << endl;
	if (!IsSorted(toSort)){
		PrintVector(toSort);
	}
}

void BubbleSort(vector<int>& toSort){
	int end = toSort.size()-1;
	while (end > 0){
		for (int i = 0; i < end; i++){
			if (toSort[i] > toSort[i+1]){
				Swap(i, i+1, toSort);
			}
		}
		end--;
	}
}

void SelectionSort(vector<int>& toSort){
	int sortedEnd = 0;
	while (sortedEnd < toSort.size()){
		int lowest = toSort[sortedEnd];
		int lowestPos = sortedEnd;
		for (int i = sortedEnd; i < toSort.size(); i++){
			if (lowest > toSort[i]){
				lowest = toSort[i];
				lowestPos = i;
			}
		}
		Swap(sortedEnd, lowestPos, toSort);
		sortedEnd++;
	}
}

void CombSort(vector<int>& toSort){
	int gap = toSort.size();
	float shrink = 1.3;
	bool swapped = true;

	while (gap > 1 || swapped){
		gap = gap/shrink;
		if (gap < 1) gap = 1;
		//cout << "Gap = " << gap << endl;

		swapped = false;
		for (int i = 0; i + gap < toSort.size(); i++){
			//cout << "Looking at " << toSort[i] << " and " << toSort[i+gap] << endl;
			if (toSort[i] > toSort[i+gap]){
				//cout << "Swapping " << toSort[i] << " and " << toSort[i+gap] << endl;
				Swap(i, i+gap, toSort);
				swapped = true;
			}
		}
	}
}

vector<int>& Merge(const vector<int>& left, const vector<int>& right){
	int leftIndex = 0;
	int rightIndex = 0;
	vector<int> result;

	while (leftIndex < left.size() && rightIndex < right.size()){
		//cout << "leftIndex = " << left[leftIndex] << " right index = " << right[rightIndex] << endl;
		if (left[leftIndex] < right[rightIndex]){
			result.push_back(left[leftIndex]);
			leftIndex++;
		} else {
			result.push_back(right[rightIndex]);
			rightIndex++;
		}
	}
	if (leftIndex == left.size()){
		for (int i = rightIndex; i < right.size(); i++){
			result.push_back(right[i]);
		}
	} else {
		for (int i = leftIndex; i < left.size(); i++){
			result.push_back(left[i]);
		}
	}
	return (result);
}

vector<int>& MergeSortHelper(vector<int>& toSort){
	//cout << "To sort = " << endl;
	//PrintVector(toSort);
	if (toSort.size() <= 1){
		return toSort;
	}

	vector<int> left;
	vector<int> right;
	int middle = toSort.size()/2;
	for (int i = 0; i < middle; i++){
		left.push_back(toSort[i]);
	}
	for (int i = middle; i < toSort.size(); i++){
		right.push_back(toSort[i]);
	}
	//cout << "Left pre sort" << endl;
	//PrintVector(left);
	//cout << "Right pre sort" << endl;
	//PrintVector(right);
	
	left = MergeSortHelper(left);
	//cout << "Left" << endl;
	//PrintVector(left);
	right = MergeSortHelper(right);
	//cout << "Right" << endl;
	//PrintVector(right);

	return (Merge(left, right));
}

void MergeSort(vector<int>& toSort){
	toSort = MergeSortHelper(toSort);
}

int main(int argc, char* argv[]){
	vector<int> test = MakeOrderedList(10000);
	//PrintVector(test);
	TestSort(BubbleSort, test, "BubbleSort");
	//PrintVector(test);
	TestSort(SelectionSort, test, "SelectionSort");
	//PrintVector(test);
	TestSort(CombSort, test, "CombSort");
	TestSort(MergeSort, test, "MergeSort");
	string s;
	cin >> s;
}

void Swap(int i, int j, vector<int>& toSort){
	int temp = toSort[i];
	toSort[i] = toSort[j];
	toSort[j] = temp;
}

void PrintVector(vector<int>& toPrint){
	for (int i = 0; i < toPrint.size(); i++){
		cout << toPrint[i] << (i + 1 < toPrint.size() ? "," : ""); 
	}
	cout << endl;
}

vector<int> MakeReverseList(int max){
	vector<int> result;
	for (int i = max; i >= 0; i--){
		result.push_back(i);
	}
	return (result);
}

vector<int> MakeOrderedList(int max){
	vector<int> result;
	for (int i = 0; i <= max; i++){
		result.push_back(i);
	}
	return (result);
}

bool IsSorted(vector<int>& toTest){
	for (int i = 0; i < toTest.size(); i++){
		if (toTest[i] != i){
			return (false);
		}
	}
	return (true);
}*/