import sys
import re
import math

def CalcDistance(point1, point2):
	""" Uses distance formula to return the distance between the 
	two points as a float """
	xDif = (point1[0]-point2[0]);
	yDif = (point1[1]-point2[1]);
	squaredSum = math.pow(xDif, 2) + math.pow(yDif, 2)
	return math.sqrt(squaredSum);

def ParseLine(line):
    """ Reads the line and will call PrintDistance
        with the appropriate arguments"""
    points = re.findall("\((.*?)\)", line)
    point1 = map(int, points[0].split(', '))
    point2 = map(int, points[1].split(', '))
    print int(CalcDistance(point1, point2))

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