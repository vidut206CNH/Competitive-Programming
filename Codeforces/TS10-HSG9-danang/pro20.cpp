#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll n, m, k, p, r;
	cin >> n >> m >> k;
	p = n / m;
	r = n % m;
	if (k <= p) {
		cout << k*m;
		return 0;
	}
	k -= p;
	if (k <= (p + 1)*r) {
		cout << (k - 1) / (p + 1) + 1 + m*((k - 1) % (p + 1));
		return 0;
	}
	k -= (p + 1) * r;
	cout << r + 1 + (k - 1) / p + m*((k - 1) % p);

}