/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-08-14 19:48:48
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-08-14 20:03:49
 */
#include <bits/stdc++.h>
using namespace std;


int main() {
    int S, T, cnt = 0;
    cin >> S >> T;
    for (int a = 0; a <= S; a++) {
        for (int b = 0; a + b <= S; b++) {
            for (int c = 0; a + b + c <= S; c++) {
                if (a * b * c <= T)
                    cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}