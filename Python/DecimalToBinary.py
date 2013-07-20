#---------------------------------------------------------
# Author: Jared Mavis
# Username: jmavis
# Problem name: Decimal To Binary
# Problem url: https://www.codeeval.com/open_challenges/27/
#---------------------------------------------------------

import sys
import math

#---------------------------------------------------------
# Function definitions
#---------------------------------------------------------
def FindLargestPowerOf2(num):
    """ Will find the largest power of 2 that will fit inside
        the given number."""
    return (math.floor(math.log(num,2)))
# end FindLargestPowerOf2()
 
def DecimalToBinary(num):
    """ Will convert the given decimal number to binary.
        *Note bin(num) will give the binary representation
        but for fun I made this function. """
    currentPower = FindLargestPowerOf2(num)
    currentNumber = num
    while (currentPower >= 0):
        powerOf2 = math.pow(2, currentPower)
        currentPower -= 1
        if (powerOf2 <= currentNumber):
            currentNumber -= powerOf2
            sys.stdout.write('1')
        else:
            sys.stdout.write('0')
    print
# end DecimalToBinary()

def ParseLine(line):
    """ Reads the line and will call CountNumOneBits
        with the appropriate arguments"""
    DecimalToBinary(int(line))
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

