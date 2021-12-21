#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n % 2 == 1) {
		cout << 1LL * (n / 2)*(n - n / 2);
	}
	else {
		n /= 2;
		if (n % 4 == 0) cout << 1LL * (n - 1)*(n + 1);
		else cout << 1LL * (n - 2)*(n + 2);
	}
}
