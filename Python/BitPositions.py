#---------------------------------------------------------
# Author: Jared Mavis
# Username: jmavis
# Problem name: Bit Positions
# Problem url: https://www.codeeval.com/open_challenges/19/
#---------------------------------------------------------

import sys
import math

#---------------------------------------------------------
# Function definitions
#---------------------------------------------------------
def HasOneBitAt(num, pos):
    """ Will return true if there is a ones but at the given
        position starting from 1 """
    return ((int(math.pow(2, pos-1)) & num) == 0)

def HasSameBitPositions(num, pos1, pos2):
    """ Will return true if the bits in the given positions are the same in
        the given number."""
    return (HasOneBitAt(num, pos1) == HasOneBitAt(num, pos2))
# end HasSameBitPositions()
 
def ParseLine(line):
    """ Reads the line and will call HasSameBitPositions
        with the appropriate arguments"""
    numAr = line.split(",")
    print(str(HasSameBitPositions(int(numAr[0]), int(numAr[1]), int(numAr[2]))).lower())
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

