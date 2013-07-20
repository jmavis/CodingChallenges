#------------------------------------------------------------------------------
# Jared Mavis
# jmavis@ucsc.edu
# Programming Assignment 4
# Prime.py - Prints out a user given number of primes
#------------------------------------------------------------------------------
def IsPrime(m, L):
    for prime in L:
        if (m % prime == 0):
            return (False)
    return (True)

def GenPrimeList(numToGen):
    primeList = [2]
    index = 3
    while (len(primeList) < numToGen):
        if (IsPrime(index, primeList)):
            primeList.append(index)
        index += 1
    return (primeList)

def PrintPrimes(primeList):
    for i in range(0, len(primeList)):
        print (str(primeList[i]) + " ", end= "\n" if (i % 10 == 0 and i != 0) else "")

num = int(input('Enter the number of primes to compute: '))
print ('\nThe first ' + str(num) + ' primes are:')
PrintPrimes(GenPrimeList(num))
