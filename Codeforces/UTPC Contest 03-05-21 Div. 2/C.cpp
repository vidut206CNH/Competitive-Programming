#include<bits/stdc++.h>

using namespace std;

int main() {
	long long m, n, s, t, Gcd, ans;
	cin >> m >> n >> s >> t;
	Gcd = __gcd(s, t);
	s /= Gcd;
	t /= Gcd;
	ans = min(m / s, n / t);
	cout << ans*s << ' ' << ans*t;
}