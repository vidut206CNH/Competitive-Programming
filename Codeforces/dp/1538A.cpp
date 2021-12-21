#include<bits/stdc++.h>

using namespace std;
const int nMax = 100;

int a[nMax];
void solve() {
	int n, in, ax, Min = 101, Max = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] < Min) {
			Min = a[i];
			in = i;
		}
		if (a[i] > Max) {
			Max = a[i];
			ax = i;
		}
	}
	cout << min(n - abs(in - ax) + 1, min(max(in, ax) + 1, n - min(in, ax))) << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t) {
		solve();
		--t;
	}
}