#---------------------------------------------------------
# Author: Jared Mavis
# Username: jmavis
# Problem name: Number of Ones
# Problem url: https://www.codeeval.com/open_challenges/16/
#---------------------------------------------------------

import sys

#---------------------------------------------------------
# Function definitions
#---------------------------------------------------------
def CountNumOneBits(num):
    """ Will keep right bit shifting the given number by 1 and
        counting the number of ones bits it contains """
    numOnes = 0
    while (num.bit_length() > 0):
        if (num & 1 == 1):
            numOnes += 1
        num >>= 1
    return (numOnes)
# end CountNumOneBits()

def ParseLine(line):
    """ Reads the line and will call CountNumOneBits
        with the appropriate arguments"""
    CountNumOneBits(int(line))
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

