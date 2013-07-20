#------------------------------------------------------------------------------
# Jared Mavis
# jmavis@ucsc.edu
# Programming Assignment 5
# Question.py - Asks for 2 numbers a low then high one. It then tries to find the number the user picked between them. Using user feedback to guide
#------------------------------------------------------------------------------
from __future__ import print_function
import math

def PickMiddle(low, high):
    return int((high + low) / 2)

def PrintGuesses(guesses):
    print ("I found your number in " + str(guesses) + " guess" + ("" if guesses == 1 else "es") + ".")

def DoGuesses(low, high):
    guesses = 0
    while True:
        guesses += 1
        if (low > high):
            print ("\nYour answers have not been consistent. Are you cheating?")
            break
        elif (low == high):
            print ("\nYour number is " + str(low) + ". ", end="")
            PrintGuesses(guesses)
            print()
            break
        currentGuess = PickMiddle(low, high)
        print ("\nIs your number Less than, Greater than, or Equal to " + str(currentGuess) + " ?")
        print ("Type 'L', 'G' or 'E': ", end="")
        while True:
            feedback = raw_input("")
            feedback = feedback.lower()
            if (feedback == "l"):
                high = currentGuess - 1
                break
            elif (feedback == "g"):
                low = currentGuess + 1
                break
            elif (feedback == "e"):
                print ()
                PrintGuesses(guesses)
                print ()
                return
            else:
                print ("\nPlease type 'L', 'G' or 'E':", end="");

high = 1 #dummy values to get past first check
low = 10

print ("Enter two numbers, low then high.")
while True:
    low = int (input("Low = "))
    high = int (input("High = "))
    if (high < low):
        print ("\nPlease enter the smaller followed by the larger number.")
    else :
        break

print ("Think of a number in the range " + str(low) + " to " + str(high) + ".")
DoGuesses(low, high)
