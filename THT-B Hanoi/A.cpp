#include<bits/stdc++.h>

using namespace std;

int main() {
	int l, r, ans = 0;
	cin >> l >> r;
	vector<int> a(r - l + 1);
	for (int i = 0; i < r - l + 1; ++i) {
		a[i] = l + i;
	}
	for (int i = 1; i <= r / 2; ++i) {
		int st = max(2, (l - 1) / i + 1);
		int ed = r / i;
		while (st <= ed) {
			a[st * i - l] -= i;
			st++;
		}
	}
	for (int i = 0; i < r - l + 1; ++i) ans += abs(a[i]);
	cout << ans;
}