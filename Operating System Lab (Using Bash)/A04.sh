#Shell Programming Loops 
#a. Write a shell program to find the factorial of an integer number using while, for and until loop. 
#Source Code:
#!/bin/bash
echo "Enter an integer:"
read n
fact=1
i=1
while [ $i -le $n ]
do
    fact=$((fact * i))
    i=$((i + 1))
done
echo "Factorial of $n = $fact"

#!/bin/bash
echo "Enter an integer:"
read n
fact=1
for ((i=1; i<=n; i++))
do
    fact=$((fact * i))
done
echo "Factorial of $n = $fact"


#!/bin/bash
echo "Enter an integer:"
read n
fact=1
i=1
until [ $i -gt $n ]
do
    fact=$((fact * i))
    i=$((i + 1))
done
echo "Factorial of $n = $fact"


#b. Write a shell script to generate the following pattern where the line number will be taken from the user. 
 '''
 * 
 * * 
 * * * 
 '''
 #Source Code:
 #!/bin/bash

echo "Enter the number of lines:"
read n

for ((i=1; i<=n; i++))
do
    for ((j=1; j<=i; j++))
    do
        echo -n "* "
    done
    echo
done
 
#c. Write a shell script which will take an integer value from the user and check if it is palindrome or not.
#Source Code:
#!/bin/bash

echo "Enter an integer:"
read n

num=$n
rev=0

while [ $n -gt 0 ]
do
    digit=$((n % 10))
    rev=$((rev * 10 + digit))
    n=$((n / 10))
done

if [ $num -eq $rev ]; then
    echo "$num is a palindrome."
else
    echo "$num is not a palindrome."
fi
