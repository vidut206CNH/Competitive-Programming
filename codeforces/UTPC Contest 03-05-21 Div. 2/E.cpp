#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

typedef long long ll;

const ll nMax = 5e6 + 1;

vector<ll> pref(nMax, 0);





int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	pref[2] = 1;
	while (t) {
		solve();
		--t;
	}
}