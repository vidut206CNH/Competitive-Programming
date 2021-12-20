#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 2e18;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k, ans = 1e9 + 1;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	for (int i = 0; i < k; ++i) {
		ans = min(ans, a[n - k + i] - a[i]);
	}
	cout << ans;
}