#------------------------------------------------------------------------------
# Jared Mavis
# jmavis@ucsc.edu
# Programming Assignment 2
# Star.py - Creates an n-pointed star based on user input
#------------------------------------------------------------------------------
import turtle

numPoints = int(input("Enter an odd integer greater than or equal to 3: "))

if (numPoints < 3 or numPoints%2 == 0):
    raise ValueError("Enter an odd integer greater that or equal to 3")

angle = (180 - (180 / numPoints))

window = turtle.Screen()
window.title(str(numPoints)+"-pointed star")
drawer = turtle.Turtle()
drawer.pensize(2)
drawer.color("blue", "green")
drawer.backward(150)
drawer.speed(0)

drawer.begin_fill()
for i in range(numPoints):
    drawer.forward(300)
    drawer.dot(10, "red")
    drawer.right(angle)
drawer.end_fill()
drawer.hideturtle()

window.mainloop();

