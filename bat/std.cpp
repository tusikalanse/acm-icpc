#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
char s[100010];
int n, m, op, L, R, A, B;

int main() {
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    while (m--) {
        scanf("%d%d%d", &op, &L, &R);
        if (op == 1) {
            for (int i = L; i <= R; ++i) {
                if (s[i] == 'A')
                    s[i] = 'B';
                else
                    s[i] = 'A';
            }
        }
        else {
            scanf("%d%d", &A, &B);
            for (int i = L; i <= R; ++i) {
                if (s[i] == 'A')
                    A = (A + B) % mod;
                else
                    B = (B + A) % mod;
            }
            printf("%d %d\n", A, B);
        }
    }
    return 0;
}