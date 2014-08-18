import sys
import re
import math

def maxOfTriangleHelper(currentRowIndex, currentIndex, triangle):
    if (currentRowIndex >= len(triangle)): 
        return 0;
    currentEntry = triangle[currentRowIndex][currentIndex];
    if (currentEntry[1] != None):
        return currentEntry[1]

    leftSum = maxOfTriangleHelper(currentRowIndex+1, currentIndex, triangle);
    rightSum = maxOfTriangleHelper(currentRowIndex+1, currentIndex+1, triangle);
    highestSum = max(rightSum, leftSum);

    entrySum = highestSum + int(currentEntry[0]);

    currentEntry[1] = entrySum

    return entrySum

def findMaxOfTriangle(triangle):
    return maxOfTriangleHelper(0,0,triangle);

def printMaxOfTriangle(triangle):
    print findMaxOfTriangle(triangle);

def ReadFile(file):
    """ Reads in and parses the lines of the given file."""
    triangleRows = [];
    for line in file.readlines():
        line = line.rstrip() #remove endline
        row = map(lambda x: [x, None], line.split(' '));
        if len(triangleRows) > 0 and len(row) == 1:
            printMaxOfTriangle(triangleRows);
            triangleRows = [];
        triangleRows.append(row)
    printMaxOfTriangle(triangleRows);

#---------------------------------------------------------
# Running Test Cases
#---------------------------------------------------------
test_cases = open(sys.argv[1], 'r')
ReadFile(test_cases)
test_cases.close()