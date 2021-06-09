#include <bits/stdc++.h>
using namespace std;

int T, a, b, m, ans;

long long gcd(long long a, long long b) {
    return b?gcd(b,a%b):a;
}
long long qp(long long a, long long n, long long m) {
    long long res = 1;
    while(n) {
        if(n & 1)
            res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

int get_phi(int val) {
    int res = val;
    for(int i = 2; i * i <= val; ++i) {
        if(val % i == 0) {
            res -= res / i;
            while(val % i == 0)
                val /= i;
        }
    }
    if(val != 1)
        res -= res / val;
    return res;
}

int qpp(int base, int times, int module) {
    if(module == 1) return base % module;
    if(times == 0) return base % module;
    int phi_module = get_phi(module);
    int b = qpp(base, times - 1, phi_module);
    return qp(a, b % phi_module + phi_module, module);
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &a, &b, &m);
        if(b == 0) {
            printf("%d\n", 1 % m);
            continue;
        }
        ans = qpp(a, b - 1, m);
        printf("%d\n", ans % m);
    }
    return 0;
}