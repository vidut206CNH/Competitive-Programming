#include<bits/stdc++.h>

using namespace std;

int main() {
	long long n, res1 = 0, res2 = 0, a, b;
	cin >> n;
	for (long long i = 0; i < n; ++i) {
		cin >> a >> b;
		res1 += min(a, b);
		res2 = max(res2, max(a, b));
	}
	cout << max(res1, res2);

}