import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static boolean check(BigInteger d) {
        String s = d.toString();
        if(s.charAt(0) != '1') return false;
        int l = s.length();
        for(int i = 1; i < l; ++i) {
            if(s.charAt(i) != '0')
                return false;
        }
        return true;
    }
    public static void main(String[] args) {
        int T, x = 0, y = 0, z = 100000;
        StringBuilder add = new StringBuilder();
        for(int i = 0; i < z; ++i) {
            add.append('0');
        }
        String addd = add.toString();
        Scanner cin = new Scanner(System.in);
        T = cin.nextInt();
        while(T-- != 0) {
            String a = cin.next();
            String b = cin.next();
            String c = cin.next();
            c = c.concat(addd);
            boolean found = false;
            for(x = c.length() - a.length() - 1; x <= c.length() - a.length(); ++x) {
                StringBuilder aa = new StringBuilder(a);
                for(int i = 0; i < x; ++i)
                    aa.append('0');
                BigInteger A = new BigInteger(aa.toString());
                BigInteger B = new BigInteger(b);
                BigInteger C = new BigInteger(c);
                BigInteger delta = C.subtract(A);
                BigInteger div = delta.divide(B);
                if(div.multiply(B).equals(delta)) {
                    if(check(div)) {
                        found = true;
                        y = div.toString().length() - 1;
                        break;
                    }
                }
            }
            if(!found)
                for(y = c.length() - b.length() - 1; y <= c.length() - b.length(); ++y) {
                    StringBuilder bb = new StringBuilder(b);
                    for (int i = 0; i < x; ++i)
                        bb.append('0');
                    BigInteger A = new BigInteger(a);
                    BigInteger B = new BigInteger(bb.toString());
                    BigInteger C = new BigInteger(c);
                    BigInteger delta = C.subtract(B);
                    BigInteger div = delta.divide(A);
                    if (div.multiply(A).equals(delta)) {
                        if (check(div)) {
                            found = true;
                            x = div.toString().length() - 1;
                            break;
                        }
                    }
                }
            if(found)
                System.out.println(x + " " + y + " " + z);
            else
                System.out.println("-1");
        }
    }
}
