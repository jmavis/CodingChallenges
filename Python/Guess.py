#------------------------------------------------------------------------------
# Jared Mavis
# jmavis@ucsc.edu
# Programming Assignment 3
# Guess.py - Generates a number from 1-10 and asks the user to guess up to 3 times reporting if the real number is higher or lower
#------------------------------------------------------------------------------
import random

intToWordList = ['first', 'second', 'third']

print ("\nI'm thinking of an integer in the range 1 to 10. You have three guesses.")

magicNumber = random.randint(1,10)

numGuesses = 0
maxGuesses = 3

while True:
    currentGuess = int(input("\nEnter your " + intToWordList[numGuesses] + " guess: "))
    numGuesses += 1
    if currentGuess > magicNumber:
        print ("Your guess is too high.", end="")
    elif currentGuess < magicNumber:
        print ("Your guess is too low.", end="")
    else:
        print ("You win!\n")
        break
    if numGuesses < maxGuesses:
        print (" Guess again.")
    else:
        print (" You lose. \n\nThe number was " + str(magicNumber) + "\n")
        break;


