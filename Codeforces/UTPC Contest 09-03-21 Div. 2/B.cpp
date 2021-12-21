#include<bits/stdc++.h>

using namespace std;

int main() {
	char c;
	long long res = 1, mod = 1e9 + 7;
	while (cin >> c) {
		res = (res * (c - 'a' + 1)) % mod;
	}
	cout << res;
}