#---------------------------------------------------------
# Author: Jared Mavis
# Username: jmavis
# Problem name: Prime Numbers 
# Problem url: https://www.codeeval.com/open_challenges/46/
#---------------------------------------------------------

import sys
import math

#---------------------------------------------------------
# Function definitions
#---------------------------------------------------------
def UpdatePrime(posPrime, pastPrimes):
    """ Will check if the given number is a prime if it is then it
        will be added to the past primes """
    for prime in pastPrimes:
        if (posPrime == prime posPrime % prime != 0 or posPrime )
    pastPrimes.add(posPrime)
    return True
# end UpdatePrime()

def MakeResult(palindrome, iterations):
    return (str(iterations) + " " + str(palindrome))
# end MakeResult()

def ReverseAndAdd(num, iterations):
    """ Will add the given number to the reverse of itself and check if that is a palindrome
        if not it will repeat untill one is found """
    strNum = str(num)
    numReverse = strNum[::-1]
    numIterations = iterations + 1
    if (strNum == numReverse):
        return MakeResult(num, numIterations)
    if (IsPalindrom(strNum, numReverse)):
        return MakeResult(num + int(numReverse), numIterations)
    return (ReverseAndAdd(num + int(numReverse), numIterations))
# end ReverseAndAdd()

def ParseLine(line):
    """ Reads the line and will call ReverseAndAdd
        with the appropriate arguments"""
    print (ReverseAndAdd(int(line), 0))
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

