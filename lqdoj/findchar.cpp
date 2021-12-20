#include<bits/stdc++.h>

using namespace std;

int main() {
	vector<int> a(150, 0);
	char c, res;
	int ans = 0;
	while (cin >> c) {
		a[c]++;
		if (a[c] == ans) res = min(c, res);
		if (a[c] > ans) {
			res = c;
			ans = a[c];
		}
	}
	cout << res;
}