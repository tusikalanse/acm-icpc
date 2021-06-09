#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int T, HPA, HPB, ATKA, ATKB;

char s[2][N], tmp[N];
long long ans[2];

int judge(int i) {
	int l = 1, r = 1e5, ans;
	while (l <= r) {
		int mid = l + r >> 1;
		if (1LL * mid * (mid + 1) / 2 >= i) {
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	return ans;
}

int fuck(int i) {
	int l = 1, r = 1e5, ans;
	while (l <= r) {
		int mid = l + r >> 1;
		if (1LL * mid * (mid + 1) / 2 <= i) {
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return ans;
}

void gao(int lim, int down, int up) {
	//down <= up < lim
	if (up == 0) return;
	if (up == down && up == 2) {
		s[1][2] = 'A';
		return;
	}
	int bot = fuck(up);
	if (1LL * bot * (bot + 1) / 2 >= down) {
		for (int i = 1; i <= bot; ++i)
			s[1][i] = 'A';
	}
	else {
		for (int i = 1; i < bot; ++i)
			s[1][i] = 'A';
		s[1][down - 1LL * bot * (bot + 1) / 2 + bot] = 'A';
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d", &HPA, &HPB, &ATKA, &ATKB);
		{//(A|B)*ABB*
			ans[0] = 1e18;
			int i = judge(HPA), j = i + 1;
			int tmp = 1LL * i * (i + 1) / 2 - HPA;
			long long b = 0;
			while (b < HPB)
				b += j++;
			j--;
			if (b - j + tmp >= HPB) {
				j--;
				for (int _ = 1; _ <= i; ++_)
					s[0][_] = 'A';
				for (int _ = i + 1; _ <= j; ++_)
					s[0][_] = 'B';
				s[0][tmp] = 'B';
			}
			else {
				for (int _ = 1; _ <= i; ++_)
					s[0][_] = 'A';
				for (int _ = i + 1; _ <= j; ++_)
					s[0][_] = 'B';
			}
			s[0][j + 1] = 0;
			ans[0] = 1LL * j * ATKB + 1LL * i * ATKA;
		}
		{
			//(A|B)*BAA*
			ans[1] = 1e18;
			int i = judge(HPB), j = i + 1;
			int tmp = 1LL * i * (i + 1) / 2 - HPB, down = 0;
			long long a = 0;
			while (a < HPA)
				a += j++;
			j--;
			if (a - j + tmp >= HPA) {
				down = HPA - (a - j);
				j--;
			}
			for (int _ = 1; _ <= i; ++_)
				s[1][_] = 'B';
			for (int _ = i + 1; _ <= j; ++_)
				s[1][_] = 'A';
			gao(i, down, tmp);
			s[1][j + 1] = 0;
			ans[1] = 1LL * j * ATKA + 1LL * i * ATKB;
		}
		if (ans[0] < ans[1] || (ans[0] == ans[1] && strcmp(s[0] + 1, s[1] + 1) < 0)) {
			printf("%lld %s\n", ans[0], s[0] + 1);
		}
		else {
			printf("%lld %s\n", ans[1], s[1] + 1);
		}
	}
	return 0;
}