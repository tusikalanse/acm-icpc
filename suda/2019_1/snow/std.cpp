#include<bits/stdc++.h>
using namespace std;

int main(void){
                
	int T;
	cin >> T;
	while(T--){
		int n, p;
		cin >> n >> p;
		long long ans=0;
		int idx;
		for (int i=n-n/4;i<=n;i++){ 
			
			int xyh=n-i;
			int tmp=i/3;
			int ht=tmp-xyh;
			long long res=1LL*xyh*800+1LL*i*400;
			if (ht>xyh) res+=1LL*p*xyh*800+1LL*p*(ht-xyh)*400;
			else res+=1LL*p*ht*800;
			if (res>=ans) {
				ans=res;
				idx=i;
			}
		}
		cout << ans << " " << idx  << endl;
	}
}

