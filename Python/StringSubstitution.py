#---------------------------------------------------------
# Author: Jared Mavis
# Username: jmavis
# Problem name: String Substitution
# Problem url: https://www.codeeval.com/open_challenges/50/
#---------------------------------------------------------

import sys
import random
import time

#---------------------------------------------------------
# Function definitions
#---------------------------------------------------------
def MakeString(length):
    string = ""
    for i in range(0, length):
        string += str(random.randint(0,1))
    return (string)

def MakeStringArray(arLen, length):
    array = []
    for i in range(0, arLen):
        array.append(MakeString(length))
    return (array)

print (MakeString(500))
print (''.join(MakeStringArray(10,4)))

def StringSubstitution(s):
    """ Will read through the line and substitute into the first string
        matching occuranance found in the lines pairings """
    endOfSourceString = s.find(';')
    sourceString = s[0:endOfSourceString]
    #sourceString = MakeString(20)
    replacementString = s[endOfSourceString+1:]
    print ("source = '" + sourceString + "'")
    #print ("replacements = " + replacementString)
    splitArray = replacementString.split(',')
    #splitArray = MakeStringArray(50, 3)
    print ("split array = " + str(splitArray))
    if (len(splitArray) == 1): # if nothing was broken up
        return (sourceString)
    for i in range(0, len(splitArray), 2):
        currentEntry = splitArray[i]
        print ("current entry = " + currentEntry)
        #replace any found entry with the marker {'A'*i} so that every marker is unique
        sourceString = sourceString.replace(currentEntry, "{" + 'A'*i + "}") 
        print (sourceString)
    for i in range(0, len(splitArray), 2):
        currentReplacement = splitArray[i+1]
        print ("current Replacement = " + currentReplacement)
        sourceString = sourceString.replace("{" + 'A'*i + "}", currentReplacement) #replace the previous markers with thier value
        print (sourceString)
    return (sourceString)
# end StringSubstitution()

def ParseLine(line):
    """ Reads the line and will call StringSubstitution
        with the appropriate arguments"""
    print (StringSubstitution(line))
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

