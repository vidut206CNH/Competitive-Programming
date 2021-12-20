#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll cnt(ll n) {
	ll res = 0;
	while (n) {
		res++;
		n /= 2;
	}
	return res;
}


int main() {
	ll n, res, t;
	cin >> n;
	res = n / 2;
	t = cnt(n);
	for (ll i = 2; i <= t; ++i) {
		res += n / (1LL * pow(2, i)) ;
	}
	cout << res;
}