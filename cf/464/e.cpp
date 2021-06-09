#include <bits/stdc++.h>
using namespace std;

int n, t, cnt = 0, num[500005];
long long s[500005];

int main()
{
	scanf("%d", &n);
	memset(s, 0, sizeof(s));
	while(n--){
		scanf("%d", &t);
		if(t == 1) {
			scanf("%d", &num[++cnt]);
			s[cnt] = s[cnt-1] + num[cnt];
		}
		else{
			int l = 1, r = cnt - 1, lmid, rmid;
			while(l <= r){
				lmid = l + (r - l)/3;
				rmid = r - (r - l)/3;
				if((double)(s[lmid]+num[cnt])/(double)(lmid+1) >= (double)(s[rmid]+num[cnt])/(double)(rmid+1)){
					l = lmid + 1;
				}
				else
					r = rmid - 1;
			}
			printf("%lf\n", num[cnt] - (double)(s[l-1]+num[cnt])/(double)l);
		}
	}
	return 0;
}