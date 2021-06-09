#include <bits/stdc++.h>
using namespace std;

int a, b, T;
double d, f;
char ch[10];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%s", &a, &b, ch);
		f = 0;
		bool flag = 0;
		int l = strlen(ch);
		for(int i = 0; i < l; ++i) {
			if(ch[i] == '-')
				d = -1;
			if(ch[i] == '+')
				d = 1;
			if(flag)
				f = f + 0.1 * (ch[i] - '0');
			if(ch[i] == '.')
				flag = 1;
			if(ch[i] >= '0' && ch[i] <= '9' && flag == 0)
				f = f * 10 + ch[i] - '0';
		}
		f *= d;
		f -= 8;
		a = a + floor(f);
		b = b + (f - floor(f)) * 60 + 0.5;
		while(b >= 60) {
			a += 1;
			b -= 60;
		}
		while(b < 0) {
			a -= 1;
			b += 60;
		}
		while(a < 0)
			a += 24;
		while(a >= 24)
			a -= 24;
		printf("%02d:%02d\n", a, b);
	}

	return 0;
}