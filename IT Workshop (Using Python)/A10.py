#A. Write a program in python to create a text file and write the text “Welcome to Python” in the file.
#Source Code:
f = open("welcome.txt", "w")
f.write("Welcome to Python")
f.close()

#B. Write a program in python to store the first n prime numbers in text file.
#Source Code:
n = int(input("Enter n: "))
count = 0
num = 2

f = open("prime.txt", "w")

while count < n:
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            break
    else:
        f.write(str(num) + "\n")
        count += 1

    num += 1

f.close()

#C. Write program in Python to store Fibonacci numbers between 0 to n, in a text file.
#Source Code:
n = int(input("Enter n: "))
a, b = 0, 1

f = open("fibonacci.txt", "w")

while a <= n:
    f.write(str(a) + "\n")
    a, b = b, a + b

f.close()

#D. Write a program in Python to read line(s) of a text file and display the lines.
#Source Code:
filename = input("Enter the filename: ")

f = open(filename, "r")

for line in f:
    print(line, end="")

f.close()

#E. Write a program in Python to find the size of a file.
#Source Code:
import os

filename = input("Enter the filename: ")

size = os.path.getsize(filename)

print("File size:", size, "bytes")
