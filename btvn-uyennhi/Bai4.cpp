/*
 Author: Le Nguyen Uyen Nhi
*/
#include<bits/stdc++.h>

using namespace std;

int powz(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b /= 2;
	}
	return res;
}

bool chk(int n) {
	int k = n, res = 1, cnt;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			res *= ((powz(i, cnt + 1) - 1) / (i - 1));
		}
	}
	if (n > 1) res *= ((powz(n, 2) - 1) / (n - 1));
	return (res == 2 * k);
}

int main() {
	int n;
	cin >> n;
	for (int i = n; i > 1; --i) {
		if (chk(i)) {
			cout << i;
			return 0;
		}
	}
}