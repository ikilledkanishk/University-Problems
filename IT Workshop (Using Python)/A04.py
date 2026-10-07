'''A. Consider a user given string s. write a program to convert uppercase letters into lowercase and
lowercase letters into uppercase. Also print the resultant string.
Input: The Joy Of Computing
Output: tHE jOY oF
cOMPUTING'''

#Source Code:
s = input("Enter the string: ")
result = s.swapcase()
print(result)


'''B. Given a student's email id in the following format 11603219005@mckvie.edu.in, write a program to
find the roll number and institute name of the student.
Input:
11603219005@mckvie.edu.in
Output: 11603219005 MCKVIE'''

#Source Code:
email = input("Enter student email: ")
roll_no, domain = email.split('@')
institute = domain.split('.')[0].upper()
print(f"{roll_no} {institute}")


'''C. Write a program that accepts a sentence and calculate the number of upper-case letters and lower-case
letters. Input Format: The first line of the input contains a statement.
Output Format: Print the number of upper case and lower case respectively.
Input: Hello world!
Output: 1 9'''

#Source Code:
sentence = input("Enter a statement: ")
upper_count = 0
lower_count = 0
for char in sentence:
    if char.isupper():
        upper_count += 1
    elif char.islower():
        lower_count += 1
print(f"{upper_count} {lower_count}")


'''D. Write a Python program that takes a sentence and two indices as input and extract the substring
between the specified indices also check the substring is a palindrome or not.
Input: A synthetic aperture radar can detect the presence of water and ice.
22 26
Output: radar
palindrome'''

#Source Code:
sentence = input("Enter the sentence: ")
start, end = map(int, input("Enter start and end indices: ").split())
substring = sentence[start : end + 1]
print(substring)
if substring == substring[::-1]:
    print("palindrome")
else:
    print("not a palindrome")