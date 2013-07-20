#---------------------------------------------------------
# Author: Jared Mavis
# Username: jmavis
# Problem name: Reverse and Add
# Problem url: https://www.codeeval.com/open_challenges/45/
#---------------------------------------------------------

import sys
import math

#---------------------------------------------------------
# Function definitions
#---------------------------------------------------------
def IsPalindrom(num, numReverse):
    """ Will determine if adding the 2 numbers results in a palindrome
        this occurs if adding none of the numbers results in a carry """
    for i in range(0, int(math.ceil(len(num)/2))+1):
        if (int(num[i]) + int(numReverse[i]) > 9):
            return False
    return True
# end IsPalindrom()

def ReverseAndAdd(num):
    """ Will add the given number to the reverse of itself and check if that is a palindrome
        if not it will repeat untill one is found """
    strNum = str(num)
    numReverse = strNum[::-1] 
    if (strNum == numReverse):
        return num
    if (IsPalindrom(strNum, numReverse)):
        return num + int(numReverse)
    return ReverseAndAdd(num + int(numReverse))
# end ReverseAndAdd()

def ParseLine(line):
    """ Reads the line and will call ReverseAndAdd
        with the appropriate arguments"""
    print (ReverseAndAdd(line))
# end ParseLine()

def ReadFile(file):
    """ Reads in and parses the lines of the given file"""
    for line in file.readlines():
        line = line.rstrip() #remove endline
        ParseLine(line)
#end ReadFile()

#---------------------------------------------------------
# Running Test Cases
#---------------------------------------------------------
test_cases = open(sys.argv[1], 'r')
ReadFile(test_cases)
test_cases.close()

