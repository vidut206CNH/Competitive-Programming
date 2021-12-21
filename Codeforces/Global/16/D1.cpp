#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
	if (a.first == b.first) return (a.second > b.second);
	return (a.first < b.first);
}
/*
2-1 1-2 5-3 3-4 3-5
1-2 2-1 3-5 3-4 5-3
 */
void solve() {
	ll n, m, x, cnt = 0;
	cin >> n >> m;
	vector<pair<ll, ll> > a;
	vector<ll> ar(m)
	;	for (ll i = 1; i <= m; ++i) {
		cin >> x;
		a.push_back({x, i});
	}
	sort(a.begin(), a.end(), cmp);
	ll j = m - 1;
	while (j > 0) {
		for (ll i = 0; i < j; ++i) {
			if (a[j].second > a[i].second) {
				cnt++;
			}
		}
		j--;
	}
	cout << cnt << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t) {
		solve();
		--t;
	}
}