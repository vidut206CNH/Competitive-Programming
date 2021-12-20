#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll nMax = 1e6 + 1;



bool cmp(vector<ll> a, vector<ll> b) {
	return (a[0] < b[0]);
}




int main() {
	ll n, m, s, x, Max = 0, ra = 0, rb = 0;
	bool chk = 0;
	cin >> n >> m >> s;
	vector< vector<ll> > a(n, vector<ll>(2, 0)), b(m, vector<ll>(2, 0));
	for (int i = 0; i < n; ++i) {
		cin >> a[i][0];
		a[i][1] = i + 1;
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i][0];
		b[i][1] = i + 1;
	}
	sort(a.begin(), a.end(), cmp);
	sort(b.begin(), b.end(), cmp);
	int l = 0, k = m - 1;
	while (l < n && k >= 0) {
		if (a[l][0] + b[k][0] <= s) {
			if (a[l][0] + b[k][0] == s) {
				cout << a[l][1] << ' ' << b[k][1];
				return 0;
			}
			if (a[l][0] + b[k][0] > Max) {
				ra = a[l][1];
				rb = b[k][1];
				Max = a[l][0] + b[k][0];
			}
			++l;
		}
		if (a[l][0] + b[k][0] > s && l < n) {
			--k;
		}
	}
	cout << ra << ' ' << rb;


}