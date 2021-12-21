#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

bool cmp(vector<ll> a, vector<ll> b) {
	if (a[0] == b[0]) return (a[1] < b[1]);
	return (a[0] < b[0]);
}

int main() {
	int n, st, ed, resa = 0, ra, rb, Max = 0;
	cin >> n;
	vector< vector<ll> > a(n, vector<ll>(2, 0));
	for (int i = 0; i < n; ++i) {
		cin >> a[i][0];
		a[i][1] = i;
	}
	sort(a.begin(), a.end(), cmp);
	st = a[0][1];
	ed = st - 1;
	for (int i = 1; i < n; ++i) {
		if (a[i][0] == a[i - 1][0]) {
			ed = a[i][1];
		}
		else {
			if (ed - st + 1 > Max) {
				resa = a[i - 1][0];
				ra = st;
				rb = ed;
				Max = rb - ra + 1;
			}
			if (ed - st + 1 == Max && a[i][1] < ra) {
				ra = st;
				rb = ed;
				resa = a[i - 1][0];
			}
			st = a[i][1];
		}
	}
	cout <<  resa << '\n' << rb - ra + 1;
}