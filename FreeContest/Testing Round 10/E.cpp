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
const int inf = 1e18;

int n,q;
string a[MAXN1];
bool mark[MAXN1];
bool mark2[32];
vector<int> f[32];

signed main() {
	fast_cin();
	
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		for(auto c : a[i]) {
			f[c - 'a'].push_back(i);
		}
	}
	
	int res = n;

	
	for(int i = 1; i <= q; ++i) {
		char c;
		cin >> c;
		if(mark2[c - 'a']) {
			cout << res << "\n";
			continue;
		}
		mark2[c - 'a'] = true;
		for(auto id : f[c - 'a']) {
			if(mark[id]) continue;
			mark[id] = true;
			res--;
		}
		
		cout << res << "\n";
	}
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}