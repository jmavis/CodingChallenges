import sys
# Decode Numbers
# Code Eval Challenge
# Author Jared Mavis

def calcDecodingsOfString(string):
    decodings = 1;
    for x in range(0, len(string)-1):
        if int(string[x]) < 3 and int(string[x]) > 0: #nothing 3X would decode
            if int(string[x] + string[x+1]) <= 26:
                decodings += 1;
    return decodings

def ParseLine(line):
    print calcDecodingsOfString(line);

def ReadFile(file):
    """ Reads in and parses the lines of the given file"""
    for line in file.readlines():
        line = line.rstrip() #remove endline
        ParseLine(line)

#---------------------------------------------------------
# Running Test Cases
#---------------------------------------------------------
test_cases = open(sys.argv[1], 'r')
ReadFile(test_cases)
test_cases.close()