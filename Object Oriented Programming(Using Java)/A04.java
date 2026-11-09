/*Complete the Java code fragment that reads two integer inputs from 
the keyboard and computes both the quotient and the remainder.
• The program should accept two integers: dividend and 
divisor.
• Output the quotient and remainder in a clear format.*/

//Source Code:
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int dividend = sc.nextInt();
        int divisor = sc.nextInt();

        if (divisor != 0) {
            int quotient = dividend / divisor;
            int remainder = dividend % divisor;

            System.out.println("The Quotient is = " + quotient);
            System.out.println("The Remainder is = " + remainder);
        } else {
            System.out.println("Division by zero is not allowed.");
        }

        sc.close();
    }
}
