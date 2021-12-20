#include<bits/stdc++.h>

using namespace std;

int main() {
	long long x, k, cnt = 0;
	cin >> x >> k;
	for (long long i = 1; i <= k; ++i) {
		if (__gcd(x, i) == 1) cnt++;
	}
	cout << cnt;
}