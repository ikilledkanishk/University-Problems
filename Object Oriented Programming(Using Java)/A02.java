/*Write a Java program to calculate and print the area and perimeter
of a rectangle.
• The program should take the rectangle’s length and width as
input.
• Output the computed perimeter and area with appropriate
formatting.*/

//Source Code:

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double length = sc.nextDouble();
        double width = sc.nextDouble();

        double perimeter = 2 * (length + width);
        double area = length * width;

        System.out.printf("Perimeter = %.2f%n", perimeter);
        System.out.printf("Area = %.2f%n", area);

        sc.close();
    }
}
