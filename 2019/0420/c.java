import java.io.*;
import java.util.*;
import java.math.*;

class Mat{
    BigInteger[][] a;
    Mat() {
        a = new BigInteger[2][2];
        a[0][0] = a[0][1] = a[1][0] = a[1][1] = BigInteger.ZERO;
    }
    Mat multiply(Mat b) {
        Mat res = new Mat();
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < 2; ++j)
                for(int k = 0; k < 2; ++k)
                    res.a[i][j] = res.a[i][j].add(a[i][k].multiply(b.a[k][j]));
        return res;
    }
    static Mat qp(Mat a, BigInteger n) {
        Mat res = new Mat();
        res.a[0][0] = res.a[1][1] = BigInteger.ONE;
        while(!n.equals(BigInteger.ZERO)) {
            if(n.mod(BigInteger.valueOf(2)).equals(BigInteger.ONE))
                res = res.multiply(a);
            a = a.multiply(a);
            n = n.divide(BigInteger.valueOf(2));
        }
        return res;
    }
}

public class c{
    public static final Scanner cin = new Scanner(System.in);
    public static void main(String[] args) {
        BigInteger[] f = new BigInteger[30];
        BigInteger[] ff = new BigInteger[30];
        Mat aa  = new Mat();
        aa.a[0][0] = aa.a[0][1] = aa.a[1][0] = BigInteger.ONE;
        f[1] = f[2] = BigInteger.ONE;
        for(int i = 3; i < 29; ++i)
            f[i] = f[i - 1].add(f[i - 2]);
        for(int i = 1; i < 29; ++i) {
            aa.a[0][0] = aa.a[0][1] = aa.a[1][0] = BigInteger.ONE;
            aa.a[1][1] = BigInteger.ZERO;
            ff[i] = Mat.qp(aa, f[i].subtract(BigInteger.ONE)).a[0][0];
        }
        int T = cin.nextInt();
        for(int i = 0; i < T; ++i) {
            BigInteger W = cin.nextBigInteger();
            boolean[] vis = new boolean[30];
            for(int j = 28; j >= 6; --j) {
                if(W.compareTo(ff[j]) >= 0) {
                    W = W.subtract(ff[j]);
                    vis[j] = true;
                }
            }
            if(W.compareTo(BigInteger.valueOf(10)) <= 0) {
                if(W.equals(BigInteger.valueOf(1))) {
                    vis[1] = true;
                }
                else if(W.equals(BigInteger.valueOf(2))) {
                    vis[1] = vis[2] = true;
                }
                else if(W.equals(BigInteger.valueOf(3))) {
                    vis[1] = vis[2] = vis[3] = true;
                }
                else if(W.equals(BigInteger.valueOf(4))) {
                    vis[1] = vis[2] = vis[4] = true;
                }
                else if(W.equals(BigInteger.valueOf(5))) {
                    vis[1] = vis[2] = vis[3] = vis[4] = true;
                }
                else if(W.equals(BigInteger.valueOf(6))) {
                    vis[1] = vis[5] = true;
                }
                else if(W.equals(BigInteger.valueOf(7))) {
                    vis[1] = vis[2] = vis[5] = true;
                }
                else if(W.equals(BigInteger.valueOf(8))) {
                    vis[1] = vis[2] = vis[3] = vis[5] = true;
                }
                else if(W.equals(BigInteger.valueOf(9))) {
                    vis[1] = vis[2] = vis[4] = vis[5] = true;
                }
                else if(W.equals(BigInteger.valueOf(10))) {
                    vis[1] = vis[2] = vis[3] = vis[4] = vis[5] = true;
                }
                W = BigInteger.ZERO;
            }
            if(W.equals(BigInteger.ZERO)) {
                boolean first = true;
                for(int j = 1; j <= 28; ++j) {
                    if(vis[j]) {
                        if(first)
                            System.out.print(j);
                        else
                            System.out.print(" " + j);
                        first = false;
                    }
                }
                System.out.println();
            }
            else
                System.out.println(-1);
        }
    }
}