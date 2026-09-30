#1A: WAP to print MCKVIE and Computer Science and Engineering. Use \n.
#Source Code: 
print("MCKVIE\nComputer Science and Engineering")

#1B: Consider a radius of a circle, WAP in python to calculate area and perimeter and display the result
#Source Code: 
rad = 5
area = (3.14)*rad
per = 2*(3.14)*rad
print(f"{area:.2f}","\n",f"{per:.2f}")

#1C: Write a python program to swap two variables using and without using third variable.
# Using 3rd variables
x = 5
y = 10
print(f"Before swap: x = {x}, y = {y}")
temp = x
x = y
y = temp

print(f"After swap: x = {x}, y = {y}")

# Without using 3rd variables
x = 5
y = 10
print(f"Before swap: x = {x}, y = {y}")
x, y = y, x
print(f"After swap: x = {x}, y = {y}")
