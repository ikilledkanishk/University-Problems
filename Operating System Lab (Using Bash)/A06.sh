'''Shell Programming based on Command Line Argument (CLA), Functions, Array and String
a. Write a function called gcd() in a shell script that will find the GCD of two numbers. The two numbers will be given by the user at
i.          Command Line
ii.         Taken as input'''
#Source Code:
#a. i.)
#!/bin/bash
gcd()
{
    a=$1
    b=$2
    while [ "$b" -ne 0 ]
    do
        temp=$b
        b=$((a % b))
        a=$temp
    done
    echo "GCD = $a"
}
if [ $# -ne 2 ]; then
    echo "Usage: $0 num1 num2"
    exit 1
fi
gcd "$1" "$2"

#a. ii.)
#!/bin/bash
gcd()
{
    a=$1
    b=$2
    while [ "$b" -ne 0 ]
    do
        temp=$b
        b=$((a % b))
        a=$temp
    done
    echo "GCD = $a"
}
echo "Enter two numbers:"
read a b
gcd "$a" "$b"

#b. Write a shell script to search a key (k) from an array of n elements using Linear Search. The value of key(k) and the number of elements must be passed through CLA. 
#Source Code:
#!/bin/bash
if [ $# -lt 3 ]; then
    echo "Usage: $0 n key element1 element2 ..."
    exit 1
fi
n=$1
key=$2
shift 2
if [ $# -ne "$n" ]; then
    echo "Enter exactly $n array elements."
    exit 1
fi
arr=("$@")
found=0
for ((i=0; i<n; i++))
do
    if [ "${arr[i]}" -eq "$key" ]; then
        echo "Element found at position $((i + 1))"
        found=1
        break
    fi
done
if [ "$found" -eq 0 ]; then
    echo "Element not found"
fi

#c. Write a shell script that takes a string as input and counts the number of letters, digits, and special characters in it. Also, it will count the number of vowels and consonants in it. Use “case” for solving the problem.
#Source Code:
#!/bin/bash
echo "Enter a string:"
IFS= read -r str
letters=0
digits=0
special=0
vowels=0
consonants=0
for ((i=0; i<${#str}; i++))
do
    ch="${str:i:1}"
    case "$ch" in
        [a-zA-Z])
            letters=$((letters + 1))
            case "$ch" in
                [aeiouAEIOU])
                    vowels=$((vowels + 1))
                    ;;
                *)
                    consonants=$((consonants + 1))
                    ;;
            esac
            ;;
        [0-9])
            digits=$((digits + 1))
            ;;
        *)
            special=$((special + 1))
            ;;
    esac
done
echo "Letters = $letters"
echo "Digits = $digits"
echo "Special characters = $special"
echo "Vowels = $vowels"
echo "Consonants = $consonants"
