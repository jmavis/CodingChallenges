import sys


def ReadFile(file):
    """ Reads in and parses the lines of the given file."""
    for line in file.readlines():
        line = line.rstrip() #remove endline
        numbers = line.split(' ');
        currentNumber = numbers[0];
        countOfCurrentNumber = 0;
        for number in numbers:
        	if number == currentNumber:
        		countOfCurrentNumber += 1;
        	else:
        		print str(countOfCurrentNumber) + " " + str(currentNumber),
        		countOfCurrentNumber = 1
        		currentNumber = number
        print str(countOfCurrentNumber) + " " + str(currentNumber)

#---------------------------------------------------------
# Running Test Cases
#---------------------------------------------------------
test_cases = open(sys.argv[1], 'r')
ReadFile(test_cases)
test_cases.close()