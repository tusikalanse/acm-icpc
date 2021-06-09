#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

inline int read() {
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}

int a[1000100], c[1000100];
int M, N, cnt, f0, ni, t;


inline int lowbit(int x) {
	return x & (-x);
}

void update(int k, int x) {
	for(register int i = k; i <= M*N; i += lowbit(i)) 
		c[i] += x;
}

int getsum(int x) {
	int ans = 0;
	for(register int i = x; i; i -= lowbit(i))
		ans += c[i];

	return ans;
}

int main() {
	while((M = read()) && (N = read())) {
		ni = cnt = 0;
		for(register int i = 0; i <= M*N; i++)
			c[i] = 0;
		for(register int i = 1; i <= M; i++) {
			for(register int j = 1; j <= N; j++) {
				t = read();
				if(t) 
					a[cnt++] = t;
				else
					f0 = i;
			}
		}
		for(register int i = cnt - 1; i >= 0; i--) {
			ni += getsum(a[i]);
			update(a[i], 1);
		}
		if(((N & 1) == 0) && ((M - f0) & 1))
			ni++;
		puts((ni & 1) ? "NO" : "YES");
	}
	return 0;
}