#---------------------------------------------------------
# Author: Jared Mavis
# Username: jmavis
# Problem name: Double Squares
# Problem url: https://www.codeeval.com/open_challenges/33/
#---------------------------------------------------------

import sys
import math

#---------------------------------------------------------
# Function definitions
#---------------------------------------------------------
def FindLargestSquare(num):
    """ Will find the largest square that will fit inside
        the given number."""
    return (int(math.floor(math.sqrt(num))))
# end FindLargestSquare()

def FindSmallestSquare(num):
    """ Will find the smallest square that will fit inside
        the given number."""
    return (int(math.floor(math.sqrt(num/2))))
# end FindSmallestSquare()

def IsSumOfDoublSquares(num, currentVal):
    """ Will determine if the given currentVal will lead to a pair
        of square adding up to the given num"""
    return (float(math.sqrt((num - math.pow(currentVal,2)))).is_integer())
 
def FindNumDoubleSquares(num):
    """ Will find the number of pairs of squares
        that will fit into teh given number """
    if (num == 0): # special case
        return 1
    highestValue = FindLargestSquare(num)
    lowestValue = FindSmallestSquare(num)
    count = 0
    for i in range (lowestValue+1, highestValue+1):
        if (IsSumOfDoublSquares(num, i)):
            count += 1
    return (count)
# end FindNumDoubleSquares()

def ParseLine(line):
    """ Reads the line and will call FindNumDoubleSquares
        with the appropriate arguments"""
    print (FindNumDoubleSquares(int(line)))
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

