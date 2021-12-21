#include<bits/stdc++.h>

using namespace std;
typedef  long long ll;
int main() {
	ll n, res = 0, cnt = 0;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cout << max(max(1LL * a[n - 1]*a[n - 2], 1LL * a[n - 1]*a[n - 2]*a[n - 3]), max(1LL * a[0]*a[1], 1LL * a[0]*a[1]*a[n - 1]));

}