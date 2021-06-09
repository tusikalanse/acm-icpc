import java.util.Scanner;

public class D12C {
	static int n,k;
	static int[] a;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		k = in.nextInt();
		a = new int[n];
		long len = 0;
		for(int i = 0 ; i < n ; i++ ) {
			a[i] = ((int)(in.nextDouble()*1000))/10;
			len += a[i];
		} 
		int ave = (int)(len / k);
		if(len<k) {
			System.out.println("0.00");
		}else if(cancut(ave)){
			System.out.printf("%.2f",((double)ave)/100);
			System.out.println();
		}else {
			int high = ave;
			int low = 1;
			int mid = (high+low)/2;
			while(low <= high) {
				mid = (high + low) / 2;
				if(cancut(mid)) {
					low = mid + 1;
					ans = mid;
				}else{
					high = mid - 1;
				}
			}
			System.out.printf("%.2f",((double)low)/100);
			System.out.println();
		}
		in.close();
	}
	
	public static boolean cancut(int len) {
		long ans = 0;
		for(int i=0;i<n;i++) {
			ans += a[i]/len;
		}
		return ans >= k;
	}
	
}
