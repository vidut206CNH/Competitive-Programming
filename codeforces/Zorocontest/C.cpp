#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll conv(string a, ll c) {
	ll res = 0;
	for (int i = 0; i < a.size(); ++i) {
		res = (res * 10 + a[i] - '0') % c;
	}
	return res;
}

ll powz(ll a, ll b, ll c) {
	ll res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % c;
		}
		a = (a * a) % c;
		b /= 2;
	}
	return res;
}

int main() {
	string a, b;
	ll c;
	cin >> a >> b >> c;
	ll ai = conv(a, c), ans = 1;
	for (int i = b.size() - 1; i >= 0; --i) {
		ans = (ans * powz(ai, b[i] - '0', c)) % c;
		ai = powz(ai, 10, c);
	}
	cout << ans;
}