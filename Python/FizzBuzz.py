#---------------------------------------------------------
# Author: Jared Mavis
# Username: jmavis
# Problem name: FizzBuzz
# Problem url: https://www.codeeval.com/open_challenges/1/
#---------------------------------------------------------

# import for string spliting functionality
import shlex
import sys

#---------------------------------------------------------
# Function definitions
#---------------------------------------------------------
def FizzBuzz(div1, div2, maxNum):
    """ Prints out the numbers from 1-maxNum replacing
        numbers divisibles by div1 with F and div2 with B
        number divisible by both are replaced with FB"""
    for i in range(1, maxNum+1):
        if (i % div1 == 0 and i %div2 == 0):
            print "FB",
        elif (i % div1 == 0):
            print "F",
        elif (i % div2 == 0):
            print "B",
        else:
            print i,
    print
# end FizzBuzz()

def ParseLine(line):
    """ Reads the line and will break apart and call
        FizzBuzz with the appropriate arguments"""
    lineValues = shlex.split(line)
    A = int(lineValues[0])
    B = int(lineValues[1])
    N = int(lineValues[2])
    FizzBuzz(A, B, N)
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
