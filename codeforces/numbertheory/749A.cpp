#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	cout << n / 2 << '\n';
	for (int i = 0; i < (n - 2) / 2; ++i) {
		cout << 2 << ' ';
	}
	if (n % 2 == 0) cout << 2;
	else cout << 3;
}