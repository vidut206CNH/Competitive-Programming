#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll base = 17;
const ll nMax = 1e4 + 1;
vector<ll> hashs(nMax, 0), powz(nMax, 1), hashsr(nMax, 0);

ll getHashs(ll i, ll j) {
	return (hashs[j] - hashs[i - 1] * powz[j - i + 1] + MOD * MOD) % MOD;
}
ll getHashsr(ll i, ll j) {
	return (hashsr[j] - hashsr[i - 1] * powz[j - i + 1] + MOD * MOD) % MOD;
}

bool chk(ll i, ll j, ll len) {
	if (i == j) return 1;
	ll mid = (i + j) / 2;
	if ((i + j) % 2 != 0) {
		return (getHashs(i, mid) == getHashsr(len - j + 1, len - mid));
	}
	else return (getHashs(i, mid) == getHashsr(len - j + 1, len - mid + 1));

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s, sr;
	cin >> s;
	sr = s;
	reverse(sr.begin(), sr.end());
	int lens = s.size();
	for (int i = 1; i <= lens; ++i) {
		powz[i] = (powz[i - 1] * base) % MOD;
	}
	for (int i = 1; i <= lens; ++i) {
		hashs[i] = (hashs[i - 1] * base + s[i - 1] - '0' + 1) % MOD;
	}
	for (int i = 1; i <= lens; ++i) {
		hashsr[i] = (hashsr[i - 1] * base + sr[i - 1] - '0' + 1) % MOD;
	}
	ll resi = 0, ress = 1;
	for (int i = 1; i <= lens; i++) {
		ll Max = '0';
		for (int j = 1; j + i - 1 <= lens; ++j) {
			if (chk(j, j + i - 1, lens)) {
				if (s[j - 1] > Max) {
					Max = s[j - 1];
					resi = j - 1;
					ress = i;
				}
				else if (s[j - 1] == Max && Max != '0') {
					if (getHashs(j, j + i - 1) > getHashs(resi + 1, resi + i)) resi = j - 1;
				}
			}
		}
	}
	cout << ress << '\n';
	for (int j = resi; j <= resi + ress - 1; ++j) {
		cout << s[j];
	}
}