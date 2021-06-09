#include <cstdio>
#include <cstring>
using namespace std;

const int N = 131700;
int stat[N], cov[N << 2], rev[N << 2];

void xxor(int rt) {
	if(cov[rt] != -1) 
		cov[rt] ^= 1;
	else
		rev[rt] ^= 1;
}

void pushdown(int rt) {
	if(cov[rt] != -1) {
		cov[rt << 1] = cov[rt << 1 | 1] = cov[rt];
		rev[rt << 1] = rev[rt << 1 | 1] = 0;
		cov[rt] = -1;
	}
	if(rev[rt]) {
		xxor(rt << 1);
		xxor(rt << 1 | 1);
		rev[rt] = 0;
	}
}

void update(int rt, int l, int r, int L, int R, char op) {
	if(L <= l && r <= R) {
		if(op == 'U') {
			cov[rt] = 1;
			rev[rt] = 0;
		}
		else if(op == 'D')
			cov[rt] = rev[rt] = 0;
		else if(op == 'C' || op == 'S') {
			xxor(rt);
		}
		return;
	}
	pushdown(rt);
	int mid = l + r >> 1;
	if(L <= mid)
		update(rt << 1, l, mid, L, R, op);
	else if(op == 'I' || op == 'C') {
		cov[rt << 1] = rev[rt << 1] = 0;
	}
	if(R > mid)
		update(rt << 1 | 1, mid + 1, r, L, R, op);
	else if(op == 'I' || op == 'C') {
		cov[rt << 1 | 1] = rev[rt << 1 | 1] = 0;
	}
}

void query(int rt, int l, int r) {
	if(cov[rt] == 1) {
		for(int i = l; i <= r; ++i)
			stat[i] = 1;
		return;
	}
	if(cov[rt] == 0)
		return;
	if(l == r) 
		return;
	int mid = l + r >> 1;
	pushdown(rt);
	query(rt << 1, l, mid);
	query(rt << 1 | 1, mid + 1, r);
}

char com[12], line[20];
int a, b;

int main() {
	memset(cov, -1, sizeof(cov));
	memset(rev, 0, sizeof(rev));
	memset(stat, 0, sizeof(rev));
	while(~scanf("%s%s", com, line)) {
		sscanf(line + 1, "%d,%d", &a, &b);
		a <<= 1; b <<= 1;
		if(line[0] == '(')
			a++;
		if(line[strlen(line) - 1] == ')')
			b--;
		if(a > b) {
			if(com[0] == 'I' || com[0] == 'C') 
				cov[1] = rev[1] = 0;
		}
		else
			update(1, 0, 65535 << 1 | 1, a, b, com[0]);
	}
	query(1, 0, 65535 << 1 | 1);
	int s = -1, e = -1, flag = 0;
	for(int i = 0; i <= (65535 << 1 | 1); ++i) {
		if(stat[i]) {
			if(s == -1)
				s = i;
			e = i;
		}
		else {
			if(s != -1) {
				if(flag)
					putchar(' ');
				printf("%c%d,%d%c", s & 1 ? '(' : '[', s >> 1, e + 1 >> 1, e & 1 ? ')' : ']');
				flag = 1;
				s = -1;
			}
		}
	}
	if(!flag)
		printf("empty set");
	puts("");
	return 0;
}