#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ll n, k, res, temp, tmp;
	cin >> n >> k;
	res = n;
	for (ll i = 2; i <= k; ++i) {
		temp = res;
		res = 0;
		while (temp) {
			if (temp % 10 != 0)tmp *= temp % 10;
			res += temp % 10;
			temp /= 10;
		}
		res += tmp;
	}
	cout << res;
}