#include <iostream> // cout
#include <stdlib.h> //std

using namespace std;

/// Author Jared Mavis
/// Username jmavis
/// Code Eval Endianess
int main (int argc, char* argv[]){
	int num = 1;
	// 1 = 0x01000000 in little endian
	
	char * checker = (char*)&num;
	// Get the byte at the adress of the char aka the first byte of the number
	//  0x01  |  000000   in little endian
	//  if the first byte is still 1 then the system stored the number 1 in little endian
	if (*checker == 1){
		cout << "LittleEndian" << endl;
	} else {
		cout << "BigEndian" << endl;
	}
}
