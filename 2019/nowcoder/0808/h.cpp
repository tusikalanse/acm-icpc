#include <bits/stdc++.h>
using namespace std;

long long dp[31][2][2][2][2], ans;
int n, A, B, C, T, a[33], b[33], c[33];

int get_bit(int x, int aa[]) {
	for(int i = 0; i <= 29; ++i)
		aa[i] = (x >> i) & 1;
}

int main() {
	cin >> T;
	while(T--) {
		cin >> A >> B >> C;
		ans = 0;
		memset(dp, 0, sizeof(dp));
		get_bit(A, a);
		get_bit(B, b);
		get_bit(C, c);
		dp[30][0][0][0][0] = 1;
		for(int i = 30; i; --i) {
			for(int _a = 0; _a < 2; ++_a) {
				for(int _b = 0; _b < 2; ++_b) {
					for(int AandB = 0; AandB < 2; ++AandB) {
						for(int AxorB = 0; AxorB < 2; ++AxorB) {
							for(int AtmpA = 0; AtmpA < 2; ++AtmpA) {
								for(int BtmpB = 0; BtmpB < 2; ++BtmpB) {
									if(AtmpA == 0 && _a > a[i - 1]) continue;
									if(BtmpB == 0 && _b > b[i - 1]) continue;
									if(AandB == 0 && (_a & _b) > c[i - 1]) continue;
									if(AxorB == 0 && (_a ^ _b) < c[i - 1]) continue;
									int newAandB = AandB | ((_a & _b) < c[i - 1]);
									int newAxorB = AxorB | ((_a ^ _b) > c[i - 1]);
									int newAtmpA = AtmpA | (_a < a[i - 1]);
									int newBtmpB = BtmpB | (_b < b[i - 1]);
									dp[i - 1][newAandB][newAxorB][newAtmpA][newBtmpB] += dp[i][AandB][AxorB][AtmpA][BtmpB];
								}
							}
						}
					}		
				}
			}
		}
		ans = 1LL * A * B;
		for(int a = 0; a < 2; ++a)
			for(int b = 0; b < 2; ++b)
				for(int c = 0; c < 2; ++c) 
					for(int d = 0; d < 2; ++d)
						ans -= dp[0][a][b][c][d];
		ans += max(0, A - C + 1);
		ans += max(0, B - C + 1);
		cout << ans << endl;
	}
	return 0;
}