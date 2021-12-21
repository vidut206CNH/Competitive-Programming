#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, k, cnt = 0;
	cin >> n >> k;
	while (n && k) {
		n -= n / 2 + (n % 2 != 0);
		cnt++;
		k--;
	}
	cout << cnt;

}