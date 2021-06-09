#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int Max = 1e5 + 10;

int euler[Max];
LL sum[Max];


void Init(){   
     euler[1]=1;  
     for(int i=2;i<Max;i++)  
       euler[i]=i;  
     for(int i=2;i<Max;i++)  
        if(euler[i]==i)  
           for(int j=i;j<Max;j+=i)  
              euler[j]=euler[j]/i*(i-1);
     euler[1] = 0;
     for(int i = 1; i < Max; ++i)
     	sum[i] = sum[i - 1] + euler[i];
}

int prime[Max],primesize, s[Max];
bool isprime[Max];
void getlist(int listsize)
{
    memset(isprime,1,sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<=listsize;i++)
    {
        if(isprime[i])prime[++primesize]=i;
         for(int j=1;j<=primesize&&i*prime[j]<=listsize;j++)
         {
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0)break;
        }
    }
    for(int i = 1; i < Max; ++i) {
    	s[i] += s[i - 1];
    	if(isprime[i])
    		s[i] += i - 1;
    }
}

inline int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}


int main() {
	int n, m;
	Init();
	getlist(Max);
	cin >> n >> m;
	if(m > sum[n] || m < n - 1) 
		return 0 * printf("Impossible\n");
	printf("Possible\n");
	if(n > 1200) {
		for(int i = 2; i <= n; ++i)
			printf("%d %d\n", 1, i);
		m -= n - 1;
		for(int i = 2; i < 1200; ++i) {
			if(isprime[i]) {
				for(int j = 2; j < i; ++j) {
					if(m == 0) 
						return 0;
					printf("%d %d\n", j, i);
					m--;
				}
			}
		}
	}
	else {
		for(int i = 2; i <= n; ++i)
			printf("%d %d\n", 1, i);
		m -= n - 1;
		for(int i = 3; i <= n; ++i) {
			for(int j = 2; j < i; ++j) {
				if(m == 0)
					return 0;
				if(gcd(i, j) == 1) {
					printf("%d %d\n", i, j);
					m--;
				}
			}
		}
	}
	return 0;
}