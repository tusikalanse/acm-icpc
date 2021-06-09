#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n, k, t, s2 = 0, s4 = 0, cnt1 = 0, cnt2 = 0;
	scanf("%d %d", &n, &k);
	while(k--){
		scanf("%d", &t);
		switch(t%4){
			case 0: s4 += t/4; break;
			case 1: s4 += t/4+1; cnt2++; break;
			case 2: s4 += t/4+1; cnt1++; break;
			case 3: s4 += t/4+2; cnt2++; cnt1++; break;
		}
	}
	s4 -= min(cnt1, cnt2);
	int x = cnt1, y = cnt2;
	cnt1 -= min(x,y);
	cnt2 -= min(x,y);
	if(cnt2%2) {s4 -= (cnt2/2+1); s2++;} 
	else s4 -= cnt2 / 2;
	s4 -= cnt1;
	s2 += cnt1;
	if(s4>=n){
	if (2*(s4-n)+s2 <= 2*n) printf("YES\n");
	else printf("NO\n");
}
	else 
	{		
		s2 -= (int)(1.5*(n-s4));
		if (s2 <= 2*n) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
