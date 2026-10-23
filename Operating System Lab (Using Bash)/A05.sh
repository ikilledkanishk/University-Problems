'''a. Write a menu-driven shell script that will take two integer values from the user and perform the following: 
1) Addition
2) Subtraction
3) Multiplication
4) Division
5) Exit
Make sure the division result is valid, and the dividend is a valid value. This process will continue until the user chooses option 5. Choices other than options 1 to 5 will show “Wrong option”.'''
#Source Code:
#!/bin/bash

while true
do
    echo "1. Addition"
    echo "2. Subtraction"
    echo "3. Multiplication"
    echo "4. Division"
    echo "5. Exit"
    echo "Enter your choice:"
    read choice

    case $choice in
        1)
            echo "Enter two integers:"
            read a
            read b
            echo "Result = $((a + b))"
            ;;
        2)
            echo "Enter two integers:"
            read a
            read b
            echo "Result = $((a - b))"
            ;;
        3)
            echo "Enter two integers:"
            read a
            read b
            echo "Result = $((a * b))"
            ;;
        4)
            echo "Enter the dividend:"
            read a
            echo "Enter the divisor:"
            read b

            if [ "$b" -eq 0 ]; then
                echo "Division by zero is not allowed."
            else
                echo "Result = $((a / b))"
            fi
            ;;
        5)
            echo "Exiting..."
            break
            ;;
        *)
            echo "Wrong option"
            ;;
    esac

    echo
done
