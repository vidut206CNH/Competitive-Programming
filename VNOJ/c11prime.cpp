#include<bits/stdc++.h>

using namespace std;

long long chk1(long long n) {
	long long q = sqrt(n);
	if (q * q == n) {
		if (q % 2 == 0) return 0;
		for (long long i = 3; i * i <= q; i += 2) {
			if (q % i == 0) {
				return 0;
			}
		}
		return q;
	}
	return 0;
}


long long powz(long long a, long long b) {
	long long res = 1;
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b /= 2;
	}
	return res;
}


int main() {
	long long n, q = 0;
	cin >> n;
	if (chk1(n) > 1) {
		cout << chk1(n) << ' ' << 2;
		return 0;
	}
	if (n % 2 == 0) {
		while (n % 2 == 0) {
			q++;
			n /= 2;
		}
		if (n == 1 && q > 1) {
			cout << 2 << ' ' << q;
		}
		else cout << 0;
		return 0;
	}
	for (long long i = 3; i * i * i <= n; i += 2) {
		if (n % i == 0) {
			while (n % i == 0) {
				q++;
				n /= i;
			}
			if (n == 1 && q > 1) {
				cout << i << ' ' << q;
			}
			else cout << 0;
			return 0;
		}
	}
	cout << 0;
}