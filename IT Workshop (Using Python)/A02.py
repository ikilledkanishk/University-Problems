#A. Consider the basic pay of an employee as user input. AGP is 50% of the basic pay. Company provides
#50% DA and 15% HRA on the merged basic. Write a python program to calculate and display total
#salary of the employee.

#Source Code:
#sal = int(input("Enter basic pay: "))
#pay = 0.50*sal + sal
#t_sal = (pay*0.50) + (pay*0.15) + pay
#print(f"{t_sal:.2f}")
  
#B. Write a python program to find the greatest among three numbers.
#Source Code:
'''num1 = int(input())
num2 = int(input())
num3 = int(input())
if (num1>num2) and (num1>num3):
    print(num1)
elif (num2>num1) and (num2>num3):
    print(num2)
else:
    print(num3)'''

#C. Write a python program to check whether a year is Leap Year.
#Source Code:
year = int(input("Enter Year: "))
if (year%4 == 0 and year%100 != 0) or (year%400 == 0):
    print(f"{year} is a leap year")
else:
    print(f"{year} is mot a leap year")
