#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	int j = 0, res = 0, cnt = 1;
	while (j < n) {
		while (a[j] == a[j + 1] && j < n) {
			cnt++;
			j = j + 1;
		}
		if (a[j] == a[j + 2]) {
			int k = j + 2, cnt1 = 1;
			while (a[k] == a[k + 1] && k < n) {
				cnt1++;
				k = k + 1;
			}
			cnt += cnt1 + 1;
			if (cnt1 > 1) j = k;
		}
		else cnt++;
		res = max(res, cnt);
		cnt = 1;
		j++;
	}
	cout << res;
}