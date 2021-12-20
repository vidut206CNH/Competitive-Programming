#include<bits/stdc++.h>

using namespace std;

bool sortc(vector<int> a, vector<int> b) {
	return (a[1] > b[1]);
}

int main() {

	int n, m;
	cin >> n >> m;
	vector< vector<int> > ve(m);
	for (int i = 0; i < m; ++i) {
		ve[i].resize(2);
		cin >> ve[i][0] >> ve[i][1];
	}
	sort(ve.begin(), ve.end(), sortc);
	int i = 0, res = 0;
	while (n > 0 && i < m) {
		if (n > ve[i][0]) {
			n -= ve[i][0];
			res += (ve[i][0] * ve[i][1]);
		}
		else {
			res += (n * ve[i][1]);
			n = 0;
		}
		++i;
	}
	cout << res;
}