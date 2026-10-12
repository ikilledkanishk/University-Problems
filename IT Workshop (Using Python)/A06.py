'''A. Write a recursive function fibo(), which will take an integer as input(n) and show the Fibonacci Series
up to n-terms. Make sure that the default value of n is 1.'''
#Source Code:

def fibo(n=1, current=0, next_val=1):
    if n <= 0:
        return
    print(current, end=" ")
    fibo(n - 1, next_val, current + next_val)


'''B. Write a recursive function fibo_n(), which will take an integer as input(n) and returns the n-th term of
Fibonacci Series. Make sure that the default value of n is 1.'''
#Source Code:

def fibo_n(n=1):
    if n <= 0:
        return 0
    if n == 1:
        return 0
    if n == 2:
        return 1
    return fibo_n(n - 1) + fibo_n(n - 2)


'''C. Write a function gcdlcm(), which will take two integers (a, b) as input and return the GCD and LCM of
these two. Make sure that the default value b is 1.'''
#Source Code:

def gcdlcm(a, b=1):
    x, y = a, b
    while y:
        x, y = y, x % y
    gcd = x
    lcm = (a * b) // gcd
    return gcd, lcm


'''D. Use the concept of high-ordered filter function to generate a list of all prime numbers in the range 251
to 10500, in reverse order.'''
#Source Code:

def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True
prime_list = list(filter(is_prime, range(10500, 250, -1)))

#E. Use the concept of lambda function list all the Leap years in the range 2022 to 3000.
#Source Code:

leap_years = list(filter(lambda y: (y % 4 == 0 and y % 100 != 0) or (y % 400 == 0), range(2022, 3001)))
