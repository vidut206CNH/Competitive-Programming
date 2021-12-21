#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, k, x, cnt = 0;
	cin >> n >> k;
	while (n) {
		cin >> x;
		if (x > k) cnt++;
		--n;
	}
	cout << cnt;
}