#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, x;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x;
		n -= x;
		if (n < 0) {
			cout << i;
			return 0;
		}
	}
	cout << m;
}