/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-08-14 19:48:48
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-08-14 20:02:21
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n <= 125)
        cout << 4 << endl;
    else if (n <= 211)
        cout << 6 << endl;
    else
        cout << 8 << endl;
   
    return 0;
}