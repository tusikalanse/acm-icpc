/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-07-24 19:55:37
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-07-24 20:04:20
 */
#include <bits/stdc++.h>
using namespace std;

vector<string> a, b;

int main() {
    string s;
    for (int i = 0; i < 4; i++) {
        cin >> s;
        a.push_back(s);
    }
    b.push_back("H");
    b.push_back("2B");
    b.push_back("3B");
    b.push_back("HR");
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a == b) {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;

    return 0;
}