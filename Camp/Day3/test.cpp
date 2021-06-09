#include <bits/stdc++.h>
using namespace std;


typedef __int128_t lll;
typedef long long ll;
const lll mod = 998244353;
const int maxn = 5000000;

int prime[1000000],num;
int vst[maxn+5];
lll phi[maxn+5], miu[maxn+5];

inline void Pre(){
  phi[1]=1; miu[1]=1;
  for (int i=2;i<=maxn;i++){
    if (!vst[i]) prime[++num]=i,phi[i]=i-1,miu[i]=-1;
    for (int j=1;j<=num && (ll)i*prime[j]<=maxn;j++){
      vst[i*prime[j]]=1;
      if (i%prime[j]==0){
	      phi[i*prime[j]]=phi[i]*prime[j];
	      miu[i*prime[j]]=0;
	      break;
      }else{
	      phi[i*prime[j]]=phi[i]*phi[prime[j]];
	      miu[i*prime[j]]=miu[i]*miu[prime[j]];
      }
    }
  }
  for (int i=1;i<=maxn;i++) phi[i]=(phi[i]+phi[i-1]),miu[i]=(miu[i]+miu[i-1]);
}

namespace MIU{
  unordered_map<ll, lll> S;
  inline lll Sum(ll n){
    if (n<=maxn) return miu[n];
    if (S.count(n)) return S[n];
    lll tem=1; 
    lll l,r;
    for (l=2;l*l<=n;l++) {
      tem-=Sum(n/l);
    }
    for (ll t=n/l;l<=n;l=r+1,t--) {
      r = n/t;
      tem-=lll(r-l+1) * Sum(t);
    }
    return S[n] = tem;
  }
}
 
namespace PHI{
  unordered_map<ll, lll> S;
  inline lll Sum(ll n){
    if (n<=maxn) return phi[n];
    if (S.count(n)) return S[n];
    lll tem=lll(lll(n)*lll(n+1)/2);
    ll l,r;
    for (l=2;l*l<=n;l++) {
      tem-=Sum(n/l);
    }
    for (ll t=n/l;l<=n;l=r+1,t--) {
      r=n/t;
      tem-=lll(r-l+1)*Sum(t);
    }
    return S[n] = tem;
  }
}

signed main(){
  Pre();
  int T;
  long long n;
    scanf("%d", &T);
    while(T--) {
      scanf("%lld", &n);
      cout << "sum_mu, sum_phi = " << ll(MIU::Sum(n) % mod) << " " << ll(PHI::Sum(n) % mod) << endl;
    }
  long long N;
  cin >> N;
  long long nxtd;
  long long ans = 0;
  for (long long d = 1; d <= N; d = nxtd + 1) {
    nxtd = N / (N / d);
    lll summu = MIU::Sum(nxtd) - MIU::Sum(d-1);
    summu = (summu%mod + mod) % mod;
    lll sumphi = PHI::Sum(N / d) * 2 - 1;
    sumphi = (sumphi%mod + mod) % mod;
    ans = (ans + summu * sumphi % mod) % mod;
  }
  cout << ans << endl;
  return 0;
}