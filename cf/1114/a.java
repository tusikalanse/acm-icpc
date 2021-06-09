import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public static final Scanner cin = new Scanner(System.in);
    public static void main(String[] args) {
        int x, y, z, a, b, c;
        x = cin.nextInt();
        y = cin.nextInt();
        z = cin.nextInt();
        a = cin.nextInt();
        b = cin.nextInt();
        c = cin.nextInt();
        if (a < x) {
            System.out.println("No");
        }
        else {
            a -= x;
            b += a;
            if (b < y) {
                System.out.println("No");
            }
            else {
                b -= y;
                c += b;
                if (c < z) {
                    System.out.println("No");
                }
                else {
                    System.out.println("Yes");
                }
            }
        }
    }
}