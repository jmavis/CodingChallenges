#include <iostream> // cout
#include <stdlib.h> //std
#include <string> // string
#include <fstream> // file io

using namespace std;

/// Author Jared Mavis
/// Username jmavis
/// BST Implementation + 
/// Code Eval Lowest Common Ancestor



template <class T>
class MyBST{
private:
	class Node {
	public:
		Node* leftNode;
		Node* rightNode;
		Node* parentNode;
		T value;
		Node(T data){
			leftNode = NULL;
			rightNode = NULL;
			parentNode = NULL;
			value = data;
		}
	};
	Node* root;

public:
	MyBST(){
		root = NULL;
	}

	void Insert(T value){
		Node* newNode = new Node(value);
		if (root == NULL){
			root = newNode;
			return;
		}
		Node* current = root;
		while (true){
			if (newNode->value < current->value){
				if (current->leftNode == NULL){
					current->leftNode = newNode;
					newNode->parentNode = current;
					return;
				} else {
					current = current->leftNode;
				}
			} else {
				if (current->rightNode == NULL){
					current->rightNode = newNode;
					newNode->parentNode = current;
					return;
				} else {
					current = current->rightNode;
				}
			}
		}
	}
	T FindLowestCommonAncestor(T val1, T val2){
		Node* current = root;
		T lowest;
		T highest;
		if (val1 > val2){
			lowest = val2;
			highest = val1;
		} else {
			lowest = val1;
			highest = val2;
		}

		while (current != NULL){
			if (current->value < lowest){
				current = current->rightNode;
			} else if (current->value > highest){
				current = current->leftNode;
			} else {
				return (current->value);
			}
		}
		cout << "There was no common ancestor" << endl;
		return (NULL);
	}
};

void PrintLowestCommonAncestor(int val1, int val2);
void ParseLine(string line);
MyBST<int> GenerateExampleBST();

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
	cin >> lineBuffer;
}

/// will parse the given line apart then find the lowest common ancestor with the example set bst
void ParseLine(string line){
	int spaceIndex = line.find(' ');
	int firstNum = atoi(line.substr(0, spaceIndex).c_str());
	int secondNum = atoi(line.substr(spaceIndex).c_str());
	MyBST<int> bst = GenerateExampleBST();
	cout << bst.FindLowestCommonAncestor(firstNum, secondNum) << endl;
}

MyBST<int> GenerateExampleBST(){
	MyBST<int> bst;
	bst.Insert(30);
	bst.Insert(52);
	bst.Insert(8);
	bst.Insert(3);
	bst.Insert(20);
	bst.Insert(10);
	bst.Insert(29);
	return (bst);
}