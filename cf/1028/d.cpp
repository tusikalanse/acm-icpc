#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int mod = 1e9 + 7;

LL qp(LL a, LL n) {
	LL res = 1;
	while(n) {
		if(n & 1)
			res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

priority_queue<int> small;
priority_queue<int, vector<int>, greater<int> > big;
int n;
int cnt = 0;
int ac[370000][2], accnt = 0;
int num[370000];
char ch[30];
int up = -0x3f3f3f3f, down = -up;
unordered_map<int, int> vis;
unordered_map<int, int> loc;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%s%d", ch, &num[i]);
		if(ch[1] == 'C') {
			accnt++;
			ac[accnt][0] = num[i];
			ac[accnt][1] = i;
		}
		else
			loc[num[i]] = i;
	}
	if(accnt == 0)
		cnt = n;
	else {
		ac[0][1] = 0;
		for(int i = 1; i <= accnt; ++i) {
			vis[ac[i][0]] = 1;	
			while(!big.empty() && ac[i][0] >= big.top()) {
				if(vis[big.top()]) 
					big.pop();
				else {
					printf("0\n");
					return 0;
				}
			}
			if(big.empty()) up = -0x3f3f3f3f;
			while(!small.empty() && ac[i][0] <= small.top()) {
				if(vis[small.top()])
					small.pop();
				else {
				 	printf("0\n");
			 		return 0;
				}
			}
			if(small.empty()) down = 0x3f3f3f3f;
			if(loc[i] > ac[i - 1][1]) 
			if((ac[i][0] < up && ac[i][0] > down) || (up == -0x3f3f3f3f && ac[i][0] > down) || (down == 0x3f3f3f3f && ac[i][0] < up) || i * 2 == ac[i][1] || up + down == 0) 
				cnt++;
			up = max(up, ac[i][0]);
			down = min(down, ac[i][0]);
			if(ac[i][1] == i * 2) 
				up = -0x3f3f3f3f, down = -up;
			for(int j = ac[i - 1][1] + 1; j < ac[i][1]; ++j) {
				if(num[j] == ac[i][0]) 
					continue;
				if(num[j] < ac[i][0]) {
					while(!big.empty() && num[j] > big.top()) {
						if(vis[big.top()]) 
							big.pop();
						else {
							printf("0\n");
							return 0;
						}
					}
					small.push(num[j]);
				}
				else {
					while(!small.empty() && num[j] < small.top()) {
						if(vis[small.top()])
							small.pop();
						else
							 {
							 	printf("0\n");
							 	return 0;
							 }
					}
					big.push(num[j]);
				}
			}
		}
		while(!big.empty() && vis[big.top()]) big.pop();
		while(!small.empty() && vis[small.top()]) small.pop();
		big.push(1e9);
		small.push(0);		
		for(int j = ac[accnt][1] + 1; j <= n; ++j) {
			if(num[j] < big.top() && num[j] > small.top())
				cnt++;
		}
	}
	printf("%lld\n", qp(2, cnt));
	return 0;
}