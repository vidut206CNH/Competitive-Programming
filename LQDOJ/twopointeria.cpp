#include<bits/stdc++.h>

using namespace std;

#define Fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
	Fastio
	int n, m;
	cin >> n >> m;
	int a[n], b[m], c[m + n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	int i = 0, j = 0, k = 0;
	while (i < n || j < m) {
		if (i == n) {
			c[k] = b[j];
			j++;
		}
		else if (j == m) {
			c[k] = a[i];
			i++;
		}
		else {
			if (a[i] < b[j]) {
				c[k] = a[i];
				i++;
			}
			else {
				c[k] = b[j];
				j++;
			}
		}
		k++;
	}
	for (int i = 0; i < m + n; ++i) cout << c[i] << ' ';
}