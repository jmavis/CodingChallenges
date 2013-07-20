#--------------------------
#Jared Mavis
#jmavis@ucsc.edu
#Programming Assignment 6
#Vectory.py - Module that performs various vector operations
#--------------------------
"""
This module provides functions to perform standard vector operations.  Vectors
are represented as lists of numbers (floats or ints).  Functions that take two 
vector arguments may give arbitrary output if the vectors are not compatible,
i.e. of the same dimension.  
"""
#------------------------------------------------------------------------------
# import standard library modules
#------------------------------------------------------------------------------
import math
import random

def MyReverse(s):
    return ''.join([s[i] for i in range(len(s)-1,-1,-1)])

print (MyReverse("this is a test this is only a test"))

#------------------------------------------------------------------------------
# function definitions
#------------------------------------------------------------------------------
def add(u, v):
    """Return the vector sum u+v."""
    return [u[i] + v[i] for i in range(len(u))]
# end add()


def negate(u):
    """Return the negative -u of the vector u."""
    return scalarMult(-1, u)
# end negate()   

def sub(u, v):
    """Return the vector difference u-v."""
    return (add(u, negate(v)))
# end sub()

def scalarMult(c, u):
    """Return the scalar product cu of the number c by the vector u."""
    return [x * c for x in u]
# end scalarMult()

def zip(u, v):
    """Return the component-wise product of u with v."""
    return [u[i] * v[i] for i in range(len(u))]
# end zip()

def dot(u, v):
    """Return the dot product of u with v."""
    return (sum(zip(u,v)))
# end dot()

def length(u):
    """Return the (geometric) length of the vector u."""
    return math.sqrt(dot(u,u))
# end length()
   
def unit(v):
    """Return a unit (geometric length 1) vector in the direction of v."""
    return (scalarMult(1/length(v), v))
# end unit()

def angle(u, v):
    """Return the angle (in degrees) between vectors u and v."""
    return math.degrees(math.acos(dot(unit(u),unit(v))))
# end angle()

def randVector(n, a, b):
    """Return a vector of dimension n whose components are random floats in the range [a,b)."""
    return [random.uniform(a,b) for i in range(n)]
# end randomVector()

   
