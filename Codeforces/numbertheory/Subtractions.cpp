#include<bits/stdc++.h>

using namespace std;

int cal(int a, int b) {
	if (b == 0) return 0;
	return a / b + cal(b, a % b);
}

void solve() {
	int a, b, res = 0;
	cin >> a >> b;
	if (a < b) swap(a, b);
	cout << cal(a, b) << '\n';
}


int main() {
	int t;
	cin >> t;
	while (t) {
		solve();
		--t;
	}
}