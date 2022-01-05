/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define gcd(a,b) (__gcd(a,b))
#define lcm(a,b) (a/gcd(a,b)*b)
#define sz(x) (int)(x.size())
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

string a[MAXN1];
int b[MAXN1];
int n;

int calc(char c) {
	for(int i=1;i <= n;++i) {
		b[i] = -sz(a[i]);
		for(auto x : a[i]) {
			b[i] += 2*(x == c);
		}
	}
	
	sort(b + 1, b + n + 1, greater<int>());
	int id = 1;
	int sum = b[id];
	while(id <= n && sum > 0) {
		sum += b[++id];
	}
	return id - 1;
}

signed main() {
	fast_cin();
	
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=1;i<=n;++i) {
			cin >> a[i];
		}
		int ans = 0;
		ans = max(ans, calc('a'));
		ans = max(ans, calc('b'));
		ans = max(ans, calc('c'));
		ans = max(ans, calc('d'));
		ans = max(ans, calc('e'));
		cout << ans << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}