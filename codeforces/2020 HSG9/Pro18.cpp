#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n, x, cnt1 = 0, cnt2 = 0, res;
	cin >> n;
	while (n) {
		cin >> x;
		if (x % 2 == 0) cnt2 += 1;
		else cnt1 += 1;
		--n;
	}
	if (cnt1 % 2 == 0) res = ((cnt1 - 1) * cnt1 / 2 + (cnt2 - 1) * cnt2 / 2);
	else res = cnt1 * cnt2;
	cout << res;
}
