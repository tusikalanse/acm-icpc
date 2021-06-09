#include <iostream>  
using namespace std;

int main() {
	int k;
	int n;
	while (cin >> n){
		int sum = 0;
		for (k = 1; k<n; k++){
			if (k*(k + 1) / 2 == n){
				for (int j = 1; j <= k; j++){
					sum += j * j;
				}
				break;
			}
			if (k*(k + 1) / 2>n && k*(k - 1) / 2<n){
				for (int j = 1; j <= k - 1; j++){
					sum += j * j;
				}
				sum += k * (n - k * (k - 1) / 2);
                break;
			}
		}
		cout << sum;
	}
	return 0;
}
