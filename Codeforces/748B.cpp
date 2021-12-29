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
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

string s,t;

int a[205];

signed main() {
	fast_cin();
	
	cin >> s >> t;
	
	bool bad = 0;
	vector<pair<char,char> > p;
	
	for(int i=0;i<sz(s);++i) {
		
		if(a[(int)s[i]] == (int)t[i]) continue;
		if(a[(int)s[i]] == 0 && a[(int)t[i]] == 0) {
			a[(int)s[i]] = (int)t[i];
			a[(int)t[i]] = (int)s[i];
			if(s[i] != t[i]) {
				p.push_back({s[i], t[i]});
			}
		}
		else {
			bad = 1;
		}
	}
	
	if(bad) cout << -1;
	else {
		cout << sz(p) << "\n";
		for(auto x : p) cout << x.fi << " " << x.se << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}