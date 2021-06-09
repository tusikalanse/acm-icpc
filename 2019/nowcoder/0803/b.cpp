#include <bits/stdc++.h>
using namespace std;

int T, cas;
vector<int> ans, aa;
string a, tmp;
string s;
vector<pair<int, int>> zeros;

char mp[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

string convert(int x) {
    if(x == 0)
        return string("0");
    static string res;
    res.clear();
    while(x) {
        res += mp[x % 16];
        x /= 16;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--) {
        cin >> s;
        ans.clear(); aa.clear(); zeros.clear();
        for(int i = 0; i < 32; ++i) {
            ans.push_back((s[4 * i] - '0') * 8 + (s[4 * i + 1] - '0') * 4 + (s[4 * i + 2] - '0') * 2 + (s[4 * i + 3] - '0'));
        }
        for(int i = 0; i < 8; ++i) {
            aa.push_back(ans[4 * i] * 4096 + ans[4 * i + 1] * 256 + ans[4 * i + 2] * 16 + ans[4 * i + 3]);
        }
        int l = 0, r;
        while(l < 8 && aa[l] != 0) l++;
        while(l < 8) {
            r = l;
            while(r < 8 && aa[r] == 0) r++;
            if(l != r - 1)
                zeros.push_back({l, r - 1});
            l = r;
            while(l < 8 && aa[l] != 0) l++;
        }
        a.clear();
        for(int i = 0; i < 8; ++i) {
            a += convert(aa[i]);
            if(i != 7)
                a += ':';
        }        
        for(auto &pr: zeros) {
            int l = pr.first, r = pr.second;
            tmp.clear();
            for(int i = 0; i < l; ++i) {
                tmp += convert(aa[i]);
                if(i != l - 1) tmp += ':';
            }
            tmp += "::";
            for(int i = r + 1; i < 8; ++i) {
                tmp += convert(aa[i]);
                if(i != 7) tmp += ':';
            }
            if(tmp.length() < a.length() || (tmp.length() == a.length() && tmp < a))
                a = tmp;
        }
        cout << "Case #" << ++cas << ": " << a << endl;
    }
    return 0;
}