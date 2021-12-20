#include<bits/stdc++.h>

using namespace std;

int main() {
	int l, w, h, v;
	cin >> l >> w >> h >> v;
	vector<int> ho(h), ve(v);

	for (int i = 0; i < h; ++i) cin >> ho[i];
	for (int i = 0; i < v; ++i) cin >> ve[i];

	sort(ho.begin(), ho.end());
	sort(ve.begin(), ve.end());
	int Maxv, Maxh;
	pair<int, int> res1, res2;
	if (w - ve[v - 1] > ve[0]) {
		Maxv = w - ve[v - 1];
		res1 = {ve[v - 1], w};
	}
	else {
		Maxv = ve[0];
		res1 = {0, ve[0]};
	}
	if (l - ho[h - 1] > ho[0]) {
		Maxh = l - ho[h - 1];
		res2 = {ho[h - 1], l};
	}
	else {
		Maxh = ho[0];
		res2 = {0, ho[0]};
	}
	for (int i = 1; i < h; ++i) {
		int j = i - 1;
		if (ho[i] - ho[j] > Maxh  || (ho[i] - ho[j] == Maxh && ho[j] < res2.first)) {
			Maxh = ho[i] - ho[j];
			res2.first = ho[j];
			res2.second = ho[i];
		}
	}
	for (int i = 1; i < v; ++i) {
		int j = i - 1;
		if (ve[i] - ve[j] > Maxv || (ve[i] - ve[j] == Maxv && ve[j] < res1.first)) {
			Maxv = ve[i] - ve[j];
			res1.first = ve[j];
			res1.second = ve[i];
		}
	}
	cout << res1.first << ' ' << res2.first << ' ' << res1.second << ' ' << res2.second;
}