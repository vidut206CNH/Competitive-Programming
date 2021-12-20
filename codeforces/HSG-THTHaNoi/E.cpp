/*
	link problem: https://codeforces.com/gym/339918/problem/E
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/gcd(a,b))*b

const ll MOD = 1000000007;
const int nMax = 1e5 + 1;
bool pri[nMax];

int powz(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b /= 2;
	}
	return res;
}

void sieve() {
	memset(pri, 0, sizeof(pri));
	pri[1] = 1;
	for (int i = 2; i * i <= nMax; ++i) {
		if (!pri[i]) {
			for (int j = i * i; j <= nMax; j += i) pri[j] = 1;
		}
	}
}

int sum(int n) {
	int ans = 0;
	while (n) {
		ans += powz((n % 10), 2);
		n /= 10;
	}
	return ans;
}


void solve() {
	int n;
	cin >> n;
	++n;
	while (1) {
		int t = sum(n);
		if (!pri[t]) {
			cout << n;
			return;
		}
		n++;
	}
}


int main() {
	fast_cin();
	ll t = 1;
	//cin >> t;
	sieve();
	while (t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}