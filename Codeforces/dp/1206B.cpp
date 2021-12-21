#include<bits/stdc++.h>

using namespace std;

int main() {
	long long n, x, c1 = 0, ans = 0;
	bool chk = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		if (x < 0) {
			c1++;
			ans = ans - x - 1;
		}
		else if (x == 0) {
			ans += 1;
			chk = 1;
		}
		else {
			ans += x - 1;
		}
	}
	if (c1 % 2 != 0) {
		if (!chk) ans += 2;
	}
	cout << ans;
}