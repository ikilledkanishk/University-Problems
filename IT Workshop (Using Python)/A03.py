#A. In general, an equation of the form 𝑎𝑥 2 + 𝑏𝑥 +𝑐 = 0 is known as quadratic equation. Accept the values
#of a, b, and c from the user and write a python program to calculate the roots of the given quadratic
#equation.

#Source Code:
import cmath

# 1. Accept input values from the user
print("Enter the coefficients for the quadratic equation ax^2 + bx + c = 0:")
a = float(input("Enter a: "))
b = float(input("Enter b: "))
c = float(input("Enter c: "))

# 2. Check if it is a valid quadratic equation
if a == 0:
    print("\nThe value of 'a' cannot be zero in a quadratic equation.")
else:
    # 3. Calculate the discriminant: d = b^2 - 4ac
    discriminant = (b**2) - (4*a*c)

    # 4. Compute both roots using the quadratic formula
    root1 = (-b + cmath.sqrt(discriminant)) / (2 * a)
    root2 = (-b - cmath.sqrt(discriminant)) / (2 * a)

    # 5. Display the results
    print(f"\nThe discriminant is: {discriminant}")
    print(f"Root 1: {root1}")
    print(f"Root 2: {root2}")



#B. Write a python to generate Fibonacci Series up-to n-terms using loop.
#Source Code:
# 1. Accept the number of terms from the user
n_terms = int(input("How many terms of the Fibonacci series do you want? "))

# 2. Initialize the first two terms of the series
n1, n2 = 0, 1
count = 0

# 3. Check if the input is valid
if n_terms <= 0:
    print("Please enter a positive integer greater than 0.")
elif n_terms == 1:
    print(f"Fibonacci series up to {n_terms} term:")
    print(n1)
else:
    print(f"Fibonacci series up to {n_terms} terms:")
    # 4. Generate the series using a loop
    while count < n_terms:
        print(n1, end="  ")
        # Calculate the next term by adding the previous two
        nth = n1 + n2
        # Update the values for the next iteration
        n1 = n2
        n2 = nth
        count += 1
    print()  # Print a newline at the end
  


#C. Write a python program to generate all Prime Numbers within a range, where range is user input.
#Source Code:
# 1. Accept the starting and ending limits from the user
lower_limit = int(input("Enter the lower limit of the range: "))
upper_limit = int(input("Enter the upper limit of the range: "))

print(f"\nPrime numbers between {lower_limit} and {upper_limit} are:")

# 2. Iterate through each number in the given range
for num in range(lower_limit, upper_limit + 1):
    # Prime numbers are strictly greater than 1
    if num > 1:
        # 3. Check for factors between 2 and the square root of the number
        is_prime = True
        for i in range(2, int(num ** 0.5) + 1):
            if num % i == 0:
                is_prime = False
                break  # Exit the inner loop early if a factor is found
        
        # 4. If no factors were found, the number is prime
        if is_prime:
            print(num, end=" ")
print()  # Print a newline at the end



#D. Write three separate python programs to generate the following patterns:
#Pattern 1:
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5

# Number of rows for the pattern
rows = 5

print("Pattern 1:")
for i in range(1, rows + 1):
    for j in range(1, i + 1):
        print(j, end=" ")
    print()  # Move to the next line after each row



#Pattern 2:
*
* *
* * *
* * * *
* * * * *
* * * *
* * *
* *
*# Maximum number of stars in the middle row
max_stars = 5

print("Pattern 2:")
# 1. Top half (growing)
for i in range(1, max_stars + 1):
    print("* " * i)

# 2. Bottom half (shrinking)
for i in range(max_stars - 1, 0, -1):
    print("* " * i)
  


#Pattern 3:
   *
 * * *
* * * * *
* * * * * * 
print("Pattern 3:")

# Row 1: 3 spaces, 1 star
print("   *")

# Row 2: 1 space, 3 stars
print(" * * *")

# Row 3: 0 spaces, 5 stars
print("* * * * *")

# Row 4: 0 spaces, 6 stars
print("* * * * * *")

