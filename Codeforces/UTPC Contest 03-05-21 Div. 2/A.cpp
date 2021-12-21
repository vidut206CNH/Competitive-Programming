#include<bits/stdc++.h>

using namespace std;

int main() {
	string res1, res2, y;
	long long Max = -1e9 - 1, Min = 1e9 + 1;
	long long n, x;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> y >> x;
		if (x < Min) {
			Min = x;
			res1 = y;
		}
		if (x > Max) {
			Max = x;
			res2 = y;
		}
	}
	cout << res1 << ' ' << res2;
}