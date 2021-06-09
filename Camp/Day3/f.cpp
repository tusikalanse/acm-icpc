 #include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef std::map<int, LL> Map;
Map _phi, _mu;
LL n;
const int N = 20000008;
LL phi[N], musum[N];
int mu[N];
int pr[1300000];
const LL mod = 998244353;
void init(int n) {                    //计算[1, n]的phi值及mu值
  memset(phi, -1, sizeof phi);
  memset(mu, -1, sizeof mu);
  int prnum = 0, i, j;
  phi[1] = 1, mu[1] = 1;
  phi[0] = mu[0] = 0;
  for (i = 2; i <= n; ++i) {
    if (phi[i] < 0) {
      pr[prnum++] = i;
      phi[i] = i - 1;
      mu[i] = -1;
    }
    for (j = 0; j < prnum && (LL)i * pr[j] <= n; ++j) {
      if (i % pr[j]) {
        phi[i * pr[j]] = phi[i] * (pr[j] - 1) % mod;
        mu[i * pr[j]] = -mu[i];
      } else {
        phi[i * pr[j]] = phi[i] * pr[j] % mod;
        mu[i * pr[j]] = 0;
        break;
      }
    }
  }
  musum[1] = mu[1];
  for (i = 2; i <= n; ++i) {
    phi[i] = phi[i] + phi[i - 1];
    phi[i] %= mod;
    musum[i] = mu[i] + musum[i - 1];
  }
}
LL CalcPhi(LL n) {
  Map::iterator it;
  if (n < N)
    return phi[n];
  if ((it = _phi.find(n)) != _phi.end())
    return it->second;
  LL i, last, ans = n;
  ans %= mod;
  ans *= (n + 1) % mod;
  ans %= mod;
  ans = (ans * 499122177) % mod;
  for (i = 2; i <= n; i = last + 1) {
    last = n / (n / i);
    ans -= ((last - i + 1) * CalcPhi(n / i)) % mod;
    ans %= mod;
  }
  return _phi[n] = ans % mod;
}
LL CalcMu(LL n) {
  Map::iterator it;
  if (n < N)
    return musum[n];
  if ((it = _mu.find(n)) != _mu.end())
    return it->second;
  LL i, last, ans = 1;
  for (i = 2; i <= n; i = last + 1) {
    last = n / (n / i);
    ans -= (last - i + 1) * CalcMu(n / i);
    ans %= mod;
  }
  return _mu[n] = ans % mod;
}
LL ans = 0;
int main()
{
    init(N - 1);
    scanf("%lld", &n);
    if (n <= 20000000)
    {
        for (int i = 1; i <= n; ++i)
        {
            ans = (ans + mu[i] * phi[n / i] % mod) % mod;
        }
        ans = (ans * 2 % mod - musum[n] % mod) % mod;
        ans = (ans + mod) % mod;
        cout << ans << endl;
        return 0;
    }
    for (int i = 1; i <= 500; ++i)
    {
        LL temp =  CalcPhi(n / i) % mod;
        ans = (ans + mu[i] * temp % mod) % mod;
    }
    LL last = n / 501 + 1;
    for (int i = 501; i < last; ++i)
    {
        ans = (ans + mu[i] * phi[n / i] % mod) % mod;
    }
    LL lval = CalcMu(last - 1);
    for (int t = 500; t >= 1; --t)
    {
        LL r = n / t;
        LL val = CalcMu(r);
        ans = (ans + (val - lval) * phi[t] % mod) % mod;
        lval = val;
    }
    ans = (ans * 2 % mod - CalcMu(n) % mod) % mod;
    ans = (ans + mod) % mod;
    cout << ans << endl;
    return 0;
}