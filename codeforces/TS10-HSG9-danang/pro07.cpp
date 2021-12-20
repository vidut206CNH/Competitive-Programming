#include<bits/stdc++.h>

using namespace std;


const int nmax = 3 * 1e6 + 3;


void sieve(vector<bool> &chk) {
	chk[0] = chk[1] = 0;
	for (int i = 2; i * i <= nmax; ++i) {
		if (chk[i]) {
			for (int j = i * i; j <= nmax; j += i) {
				chk[j] = 0;
			}
		}
	}
}

bool sume(int a) {
	int ans = 0;
	while (a) {
		ans = (ans + a % 10) % 5;
		a /= 10;
	}
	return (ans % 5 == 0);
}


void solve(vector<bool> chk) {
	int l, r, cnt = 0;
	cin >> l >> r;
	for (int i = l; i <= r; ++i) {
		if (chk[i] && sume(i)) cnt++;
	}
	cout << cnt << '\n';

}

int main() {
	int n;
	cin >> n;
	vector<bool> chk(nmax, 1);
	sieve(chk);
	while (n) {
		solve(chk);
		--n;
	}
}