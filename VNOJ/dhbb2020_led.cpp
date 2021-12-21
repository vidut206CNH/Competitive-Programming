/*
	link problem:
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
const ll nMax = 1e6 + 1;
ll a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
ll b[10] = {2, 6, 2, 3, 3, 4, 2, 3, 1, 1};
void sol1() {
	string s;
	cin >> s;
	ll ans = 0;
	for (int i = 0; i < s.length(); ++i) {
		ans += a[s[i] - '0'];
	}
	cout << ans;
}

void sol2() {
	string s;
	cin >> s;
	ll ans = 1;
	for (int i = 0; i < s.length(); ++i) {
		ans *= b[s[i] - '0'];
	}
	cout << ans - 1;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	if (t == 1) {
		sol1();
	}
	else sol2();
	return 0;
}