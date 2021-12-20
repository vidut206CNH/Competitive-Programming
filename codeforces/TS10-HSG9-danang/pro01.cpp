#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sum(ll n) {
	ll res = 1;
	int cnt = 0;
	while (n % 2 == 0) {
		cnt++;
		n /= 2;
	}
	res *= 1LL * (pow(2, cnt + 1) - 1);
	cnt = 1;
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			res *= 1LL * (pow(i, cnt) - 1) / (i - 1);
			cnt = 1;
		}
	}
	if (n > 1) res *= 1LL * (pow(n, 2) - 1) / (n - 1);
	return res;
}

int main() {
	ll n, Max = 0, ans;
	cin >> n;
	for (ll i = 1; i <= n; ++i) {
		if (sum(i) > Max) {
			ans = i;
			Max = sum(i);
		}
	}
	cout << ans;
}