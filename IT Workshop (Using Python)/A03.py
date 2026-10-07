#A. In general, an equation of the form 𝑎𝑥 2 + 𝑏𝑥 +𝑐 = 0 is known as quadratic equation. Accept the values
#of a, b, and c from the user and write a python program to calculate the roots of the given quadratic
#equation.

#Source Code:
import cmath
print("Enter the coefficients for the quadratic equation ax^2 + bx + c = 0:")
a = float(input("Enter a: "))
b = float(input("Enter b: "))
c = float(input("Enter c: "))
if a == 0:
    print("\nThe value of 'a' cannot be zero in a quadratic equation.")
else:
    discriminant = (b**2) - (4*a*c)
    root1 = (-b + cmath.sqrt(discriminant)) / (2 * a)
    root2 = (-b - cmath.sqrt(discriminant)) / (2 * a)
    print(f"\nThe discriminant is: {discriminant}")
    print(f"Root 1: {root1}")
    print(f"Root 2: {root2}")



#B. Write a python to generate Fibonacci Series up-to n-terms using loop.
#Source Code:
n_terms = int(input("How many terms of the Fibonacci series do you want? "))
n1, n2 = 0, 1
count = 0
if n_terms <= 0:
    print("Please enter a positive integer greater than 0.")
elif n_terms == 1:
    print(f"Fibonacci series up to {n_terms} term:")
    print(n1)
else:
    print(f"Fibonacci series up to {n_terms} terms:")
    while count < n_terms:
        print(n1, end="  ")
        nth = n1 + n2
        n1 = n2
        n2 = nth
        count += 1
    print()
  


#C. Write a python program to generate all Prime Numbers within a range, where range is user input.
#Source Code:
lower_limit = int(input("Enter the lower limit of the range: "))
upper_limit = int(input("Enter the upper limit of the range: "))

print(f"\nPrime numbers between {lower_limit} and {upper_limit} are:")
for num in range(lower_limit, upper_limit + 1):
    if num > 1:
        is_prime = True
        for i in range(2, int(num ** 0.5) + 1):
            if num % i == 0:
                is_prime = False
                break  
        if is_prime:
            print(num, end=" ")
print() 



#D. Write three separate python programs to generate the following patterns:
#Pattern 1:
'''
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5'''
rows = 5
print("Pattern 1:")
for i in range(1, rows + 1):
    for j in range(1, i + 1):
        print(j, end=" ")
    print() 


#Pattern 2:
'''
*
* *
* * *
* * * *
* * * * *
* * * *
* * *
* *
*'''
max_stars = 5

print("Pattern 2:")
for i in range(1, max_stars + 1):
    print("* " * i)
for i in range(max_stars - 1, 0, -1):
    print("* " * i)
  


#Pattern 3:
'''  
   *
 * * *
* * * * *
* * * * * * '''
print("Pattern 3:")
print("   *")
print(" * * *")
print("* * * * *")
print("* * * * * *")

