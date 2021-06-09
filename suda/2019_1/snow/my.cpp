#include <bits/stdc++.h>
using namespace std;

int T, p, n;
long long ans;

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> p;
        if (p < 1) 
            ans = (n / 4) * 2000 + (n % 4) * 400;
        else
            ans = (n / 7) * (3200 + 800LL * p) + ((n % 7 > 3) ? (400 * (n % 7 + p)) : (400 * (n % 7)));
    	cout << ans << endl;
    }
    return 0;
}


/home/tusikalanse/Downloads/qq-files/615822545/file_recv