#------------------------------------------------------------------------------
# Jared Mavis
# jmavis@ucsc.edu
# Programming Assignment 1
# Sphere.py - Computes the surface area and volume of a Sphere given the radius
#------------------------------------------------------------------------------
from math import pi as pi

radius = float(input("Enter the radius of the sphere: "))

if radius < 0: 
	radius = abs(radius)

surfaceArea = 4*(pi*(radius**2))
volume = (4/3)*pi*(radius**3)

print("The volume is: " + str(volume))
print("The surface area is: " + str(surfaceArea))
input()