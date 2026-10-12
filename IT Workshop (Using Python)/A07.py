'''A. Create module called ‘numberCheck’, with two functions called ‘primeCheck()’ (to check a number is
prime or not) and ‘palindromCheck()’ (to check a number is palindrome or not). Import the following
module in your source code. Take an integer input in your current source code and call the
‘numberCheck’ module’s functions to check the number is prime and/or Palindrome number or not.'''
#Module: 
def primeCheck(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def palindromCheck(num):
    s = str(num)
    return s == s[::-1]
  
#Source Code:
import numberCheck
n = int(input("Enter an integer: "))
if numberCheck.primeCheck(n):
    print(f"{n} is a Prime number.")
else:
    print(f"{n} is not a Prime number.")
if numberCheck.palindromCheck(n):
    print(f"{n} is a Palindrome number.")
else:
    print(f"{n} is not a Palindrome number.")

'''B. Import numpy module in your source code. Create function named matrixMultiplication(), where
create m X n matrix (A) integer by taking user inputs. Also, create a n X m matrix (B) with random
numbers between 1 to 20 . Generate a C matrix where C = A X B. Show the C Matrix.'''
#Source Code:
import numpy as np

def matrixMultiplication():
    m = int(input("Enter number of rows (m): "))
    n = int(input("Enter number of columns (n): "))
    
    print(f"Enter {m * n} elements for Matrix A:")
    elements = [int(input()) for _ in range(m * n)]
    A = np.array(elements).reshape(m, n)
    B = np.random.randint(1, 21, size=(n, m))
    C = np.dot(A, B)
    print("\nMatrix A:")
    print(A)
    print("\nMatrix B (Random):")
    print(B)
    print("\nResultant Matrix C (A X B):")
    print(C)
matrixMultiplication()

