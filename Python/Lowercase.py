#---------------------------------------------------------
# Author: Jared Mavis
# Username: jmavis
# Problem name: Lowercase  
# Problem url: https://www.codeeval.com/open_challenges/20/
#---------------------------------------------------------

import sys

#---------------------------------------------------------
# Function definitions
#---------------------------------------------------------
def IsCapitalized(char):
    """ Will return true if the given character is a capital letter"""
    return (ord(char) >= ord('A') and ord(char) <= ord('Z'))

def ConvertToLower(s):
    """ Will return the lower case version of the given string"""
    differce = ord('a') - ord('A') # get the ascii value for the difference between A and a
    lowerCase = ""
    for char in s:
        if (IsCapitalized(char)):
            lowerCase += chr(ord(char) + differce)
        else:
            lowerCase += char
    return (lowerCase)
# end ConvertToLower()

def ParseLine(line):
    """ Reads the line and will call ConvertToLower
        with the appropriate arguments"""
    print(ConvertToLower(line))
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

