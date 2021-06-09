#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int MAXN = 100010;
int a[MAXN], sum[MAXN], que[MAXN];
int n, k, head, tail;

inline int KX(int a, int b) {return a - b;}
inline int KY(int a, int b) {return sum[a] - sum[b];}

int tot;
const int BUF = 25000000;
char Buf[BUF],*buf=Buf;
inline void read(int &a)
{
	for(a=0;*buf<48;buf++);
	while(*buf>47) a=a*10+*buf++-48;
}

int main() {
	tot = fread(Buf,1,BUF,stdin); 
	int n,k;
	while(1) {
		if(buf - Buf + 1 >= tot) break;
		read(n), read(k);
		sum[0] = head = tail = 0;
		for(int i = 1; i <= n; ++i) {
			read(a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		double ans = 0;
		for(int i = k; i <= n; ++i) {
			while(head < tail - 1 && 1LL * KY(i - k, que[tail - 1]) * KX(que[tail - 1], que[tail - 2]) <= 1LL * KY(que[tail - 1], que[tail - 2]) * KX(i - k, que[tail - 1]))
				tail--;
			que[tail++] = i - k;
			while(head < tail - 1 && 1LL * KY(i, que[head + 1]) * KX(que[head + 1], que[head]) >= 1LL * KY(que[head + 1], que[head]) * KX(i, que[head + 1]))
				head++;
			ans = max(ans, (sum[i] - sum[que[head]]) * 1.0 / (i - que[head]));
		}
		printf("%.2f\n", ans);
	}
	return 0;
}