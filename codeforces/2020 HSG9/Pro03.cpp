#include<bits/stdc++.h>

using namespace std;

void solve() {
	long long n;
	cin >> n;
	double sum = 0;
	for (long long i = 2; i <= n; ++i) {
		if (i % 2 == 0) sum += 1.0 / i;
		else sum -= 1.0 / i;
	}
	cout << fixed << setprecision(5) << sum;

}
int main() {
	solve();

}
