#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end(), greater<int>());
	int q = a[0], cnt = 1, i = 1;
	while (cnt < n - k && i < n) {
		if (q > a[i] / 2) {
			cnt++;
			q = a[i];
		}
		i++;
	}
	cout << cnt  << ' ' << (n - cnt) / k;

}