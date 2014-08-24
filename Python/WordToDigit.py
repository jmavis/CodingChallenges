import sys

numberStringHash = {
    "zero": 0,
    "one": 1,
    "two": 2,
    "three": 3,
    "four": 4,
    "five": 5,
    "six": 6,
    "seven": 7,
    "eight": 8,
    "nine": 9
}

def ReadFile(file):
    """ Reads in and parses the lines of the given file."""
    for line in file.readlines():
        line = line.rstrip() #remove endline
        print "".join(map(lambda x: str(numberStringHash[x]), line.split(';')));

#---------------------------------------------------------
# Running Test Cases
#---------------------------------------------------------
test_cases = open(sys.argv[1], 'r')
ReadFile(test_cases)
test_cases.close()