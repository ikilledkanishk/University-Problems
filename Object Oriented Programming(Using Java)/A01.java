//Write a Java program that takes an integer as input and checks whether it is even or odd.
//• If the number is odd, print "Odd".
//• If the number is even, print "Even".

//Source Code:

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();

        if (num % 2 == 0) {
            System.out.println("Even");
        } else {
            System.out.println("Odd");
        }

        sc.close();
    }
}