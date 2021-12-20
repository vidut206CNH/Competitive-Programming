#include<bits/stdc++.h>

using namespace std;


int main() {
	int n, k, x;
	cin >> n >> k;
	vector< vector<int> > a(n, vector<int>(n, 100001));
	vector< int > res;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			res.push_back(min(a[i][j], a[i][j]));
		}
	}
	sort(res.begin(), res.end());
	int i = 0;
	while (k)
	}