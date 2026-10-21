3. Shell programming
a. Write a shell script which will take two integer values from the user and show the result of their summation, subtraction, multiplication, division, modulus.
If the numbers are 5 and 2, then the output will be like this-
5 + 2 = 7
5 – 2 = 3
5 * 2 = 10
5 / 2 = 2
5 % 2 = 1
#Source Code:
#!/bin/bash
echo "Enter two integers:"
read a
read b
echo "$a + $b = $((a + b))"
echo "$a - $b = $((a - b))"
echo "$a * $b = $((a * b))"
if [ $b -ne 0 ]; then
    echo "$a / $b = $((a / b))"
    echo "$a % $b = $((a % b))"
else
    echo "Division and modulus by zero are undefined."
fi

b. Take 2 integer values from the user and show the greatest value of them.
#Source Code:
#!/bin/bash
echo "Enter two integers:"
read a
read b
if [ $a -gt $b ]; then
    echo "$a is the greatest."
elif [ $b -gt $a ]; then
    echo "$b is the greatest."
else
    echo "Both numbers are equal."
fi

c. Take an integer number from the user and check whether it is even or odd.
#Source Code:
#!/bin/bash
echo "Enter an integer:"
read n
if [ $((n % 2)) -eq 0 ]; then
    echo "$n is even."
else
    echo "$n is odd."
fi
