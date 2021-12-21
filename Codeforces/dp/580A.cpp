#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, cnt = 1, res = 1;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i > 0 && a[i] >= a[i - 1]) cnt++;
		else {
			res = max(res, cnt);
			cnt = 1;
		}
		if (i == n - 1) res = max(res, cnt);
	}
	cout << res;
}