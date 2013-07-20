#---------------------------------------------------------
# Author: Jared Mavis
# Username: jmavis
# Problem name: Odd Numbers  
# Problem url: https://www.codeeval.com/open_challenges/25/
#---------------------------------------------------------

import sys

#---------------------------------------------------------
# Function definitions
#---------------------------------------------------------
def PrintOddNumbersFrom(start, end):
    """ Will print the odd numbers from the start to the end exclusive"""
    if start % 2 == 0:
        start += 1 # start counting at and odd number
    for num in range(start, end, 2):
        print(num)
# end print odd numbers


#---------------------------------------------------------
# Running Script
#---------------------------------------------------------
PrintOddNumbersFrom(1,100)

