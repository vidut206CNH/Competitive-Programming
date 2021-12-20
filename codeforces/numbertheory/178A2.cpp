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

int cal(int n) {
	int ans = 0;
	n /= 2;
	while (n) {
		n /= 2;
		ans++;
	}
	return powz(2, ans);
}


int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	int res = 0;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n - 1; ++i) {
		res += a[i];
		cout << res << '\n';
		a[i + cal(n - 1 - i)] += a[i];
	}
}