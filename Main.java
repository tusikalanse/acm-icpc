import java.util.Scanner;

public class Main {

    private static int MAXN = 10000;
    private static int n;

    private static int[] chain;
    private static int best;

    private static boolean found;
    private static int lb,ub,t;

    private static int[] a,parent;

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        while (true){
            best = MAXN;

            n = input.nextInt();

            chain = new int[MAXN];
            a = new int[MAXN];
            parent = new int[MAXN+1];

            if(n <= MAXN) {search(); output();}
            else System.out.println("Number too large!");
        }
    }

    private static void search(){
        lb = lowerb(n);
        ub = powertree(n);
        t = gett(n);
        if(lb < ub){
            found = false;
            while (!found){
                System.out.println("lb="+lb);
                a[1] = 1;
                backtrack(1);
                lb++;
                if(lb == ub) found=true;
            }
        }
    }

    private static int powertree(int n){
        found = false;
        ub = 1;
        for(int i=1; i<=MAXN; i++) parent[i]=0;
        while (!found){
            a[1] = 1;
            find(1);
            ub++;
        }

        return best;
    }

    private static void find(int step){
        int i,k;
        if(!found)
            if(a[step] == n){
                best = step;
                for(i=1; i<=best; i++) chain[i]=a[i];
                found = true;

                return;
            }else if(step <= ub)
                for(i=1; i<=step; i++){
                    k = a[step]+a[i];
                    if(k <= n){
                        a[step+1] = k;
                        if(parent[k] == 0) parent[k]=a[step];
                        if(parent[k] == a[step]) find(step+1);
                    }
                }
    }

    private static void backtrack(int step){
        if(!found)
            if(a[step] == n){
                best = step;
                for(int i=1; i<=best; i++)
                    chain[i] = a[i];
                found = true;

                return;
            }else if(step < lb)
                for(int i=step; i>=1; i--)
                    if(2*a[i] > a[step])
                        for(int j=i; j>=1; j--){
                            int k = a[i]+a[j];
                            a[step+1] = k;
                            if(k>a[step] && k<=n)
                                if(!pruned(step+1))
                                    backtrack(step+1);
                        }
    }

    private static boolean pruned(int step){
        if(step < lb-t-1) return (h(3*a[step])+step+2 > lb);
        else return (h(a[step])+step > lb);
    }

    private static int h(int num){
        int i=0;
        while (num < n) {num=num<<1; i++;}

        return i;
    }

    private static int lowerb(int m){
        int i=0,j=1;
        while (m > 1) { i++; if(odd(m)) j++; m=m>>1;}
        i += log2(j)+1;

        return i;
    }

    private static int log2(int m){
        int i=0,j=1;
        while (m > 1) {i++; if(odd(m)) j++; m=m>>1;}
        if(j > 1) i++;

        return i;
    }

    private static int gett(int num){
        int i=0;
        while (!odd(num)) {num=num>>1; i++;}

        return i-1;
    }

    private static void output(){
        System.out.println(best-1);
        for(int i=1; i<=best; i++)
            System.out.print(chain[i]+" ");
    }

    private static boolean odd(int num){
        return num%2==1;
    }
}