// http://acm.hdu.edu.cn/showproblem.php?pid=4135

#include <bits/stdc++.h>

using namespace std;

long long solve(long long a, long long b, const vector <int> &prime_div) {
	// [1, x] non-coprime with n
	int n = prime_div.size();
	long long res = b - a + 1; // Inclusion–exclusion principle
	for (int mask = 1; mask < (1 << n); ++ mask) {
		int prod = 1, cnt = 0;
		for (int i = 0; i < n; ++ i)
			if ((mask >> i) & 1)
				prod *= prime_div[i],
				        ++ cnt;
		long long tmp = b / prod - (a - 1) / prod;
		if (cnt & 1)
			res -= tmp;
		else
			res += tmp;
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int ntest;
	cin >> ntest;
	for (int i = 1, n; i <= ntest; ++ i) {
		long long a, b;
		cin >> a >> b >> n;

		// factorize n into prime factor
		vector <int> prime_div;
		for (int i = 2; i * i <= n; ++ i)
			if (n % i == 0) {
				while (n % i == 0)
					n /= i;
				prime_div.push_back(i);
			}
		if (n > 1)
			prime_div.push_back(n);

		// calculate the result
		cout << "Case #" << i << ": " << solve(a, b, prime_div) << "\n";
	}
	return 0;
}