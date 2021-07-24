/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-07-24 19:55:37
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-07-24 20:01:27
 */
#include <bits/stdc++.h>
using namespace std;

double a, b, c;

int main() {
    scanf("%lf %lf", &a, &b);
    c = (a - b) / 3 + b;
    printf("%.15f\n", c);
    return 0;
}