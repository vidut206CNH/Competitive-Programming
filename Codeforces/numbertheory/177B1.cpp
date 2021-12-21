#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll n;
	cin >> n;
	ll res = n;
	while (n % 2 == 0) {
		n /= 2;
		res += n;
	}
	for (ll i = 3; i * i <= n; i += 2) {
		while (n % i == 0) {
			n /= i;
			res += n;
		}
	}
	if (n > 1) res++;
	cout << res;

}