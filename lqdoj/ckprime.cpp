#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool chk(ll n) {
	if (n % 2 == 0) return 0;
	for (ll i = 3; i * i <= n; i += 2) {
		if (n % i == 0) return 0;
	}
	return 1;

}


int main() {
	long long a, b;
	cin >> a >> b;
	if (a - b > 1) {
		cout << "NO";
		return 0;
	}
	if (chk(a + b)) {
		cout << "YES";
		return 0;
	}
	cout << "NO";
}