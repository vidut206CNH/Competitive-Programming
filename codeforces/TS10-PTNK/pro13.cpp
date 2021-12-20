#include<bits/stdc++.h>

using namespace std;

int main() {
	long long n, res;
	cin >> n;
	res = n;
	if (n % 2 == 0) res -= res / 2;
	while (n % 2 == 0) {
		n /= 2;
	}
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}
			res -= res / i;
		}
	}
	if (n > 1) res -= res / n;
	cout << res;

}