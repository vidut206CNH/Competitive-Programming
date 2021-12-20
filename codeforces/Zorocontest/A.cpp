#include<bits/stdc++.h>

using namespace std;



int main() {
	long long l, r, cnt, ans = 0;
	cin >> l >> r;
	vector<long long> a(r + 1, 0);
	for (long long i = 2; i <= r; ++i) {
		cnt = r / i - (l - 1) / i;
		a[i] = 1LL * (cnt - 1) * cnt;
	}
	for (long long i = r / 2; i >= 2; --i) {
		for (long long j = 2 * i; j <= r; j += i) a[i] -= a[j];
		cnt = r / i - (l - 1) / i;
		if (i >= l && i <= r) ans -= (cnt - 1) * 2;
		ans += a[i];
	}
	cout << ans;
}