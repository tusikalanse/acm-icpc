/*
 * @Author: tusikalanse
 * @Date: 2021-06-09 20:50:08
 * @LastEditTime: 2021-06-09 20:58:02
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /algo/cf/1536/b.cpp
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

int t, n;
string s;
vector<string> mex[5];

int main() {
    for (int i = 0; i < 26; ++i) {
        string s1 = "";
        s1 += 'a' + i;
        mex[1].push_back(s1);
        for (int j = 0; j < 26; ++j) {
            string s2 = s1;
            s2 += 'a' + j;
            mex[2].push_back(s2);
            for (int k = 0; k < 26; ++k) {
                string s3 = s2;
                s3 += 'a' + k;
                mex[3].push_back(s3);
            }
        }
    }
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int flag = 0;
        for (int i = 1; i <= 3; ++i) {
            for (int j = 0; j < mex[i].size(); ++j) {
                if (s.find(mex[i][j]) == string::npos) {
                    cout << mex[i][j] << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
    }

    return 0;
}
