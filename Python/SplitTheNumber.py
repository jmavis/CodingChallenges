import sys

def ParseLine(line):
    dataInput = line.split(' ');
    numberComponent = str(dataInput[0]);
    stringComponent = dataInput[1];
    indexOfOperator = stringComponent.find('+');
    if indexOfOperator != -1:
        firstNumber = int(numberComponent[0:indexOfOperator]);
        secondNumber = int(numberComponent[indexOfOperator:]);
        print firstNumber + secondNumber
    else:
        indexOfOperator = stringComponent.find('-');
        firstNumber = int(numberComponent[0:indexOfOperator]);
        secondNumber = int(numberComponent[indexOfOperator:]);
        print firstNumber - secondNumber

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