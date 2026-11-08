/*Write a Java program to calculate the volume of a cylinder given 
its radius and height.
• Use the formula: 𝑉 = 𝜋 × 𝑟
2 × ℎ
• You may use Math.PI for π in Java.
• The program should take radius and height as input and 
print the computed volume.*/

//Source Code:

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double radius = sc.nextDouble();
        double height = sc.nextDouble();

        double volume = Math.PI * radius * radius * height;

        System.out.printf("Volume is: %.2f%n", volume);

        sc.close();
    }
}
