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
#define db(x) cerr << "[" << "Line " << __LINE__ << " : " << (#x) << " = " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

int n,m;
int s[MAXN1];
int a[MAXN1];
int p[11];
map<int,int> mp;

signed main() {
	fast_cin();
	
	cin >> n >> m;
	for(int i = 1; i < n; ++i) {
		cin >> s[i];
	}
	for(int i = 1; i <= m; ++i) cin >> p[i];
	
	a[1] = 0;
	for(int i = 2; i <= n; ++i) {
		a[i] = s[i - 1] - a[i - 1];
	}
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(i&1) mp[a[i] - p[j]]++;
			else mp[p[j] - a[i]]++;
		}
	}
	
	int res = 0;
	for(auto x : mp) {
		res = max(res, x.se);
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}