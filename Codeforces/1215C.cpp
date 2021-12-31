/*
	Author : vidut_206_CNH
	Link problem: 
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
//#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "


typedef pair<int,int> pii;


const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;


string s,t;

signed main() {
	fast_cin();
	int n;
	cin >> n;
	cin >> s >> t;
	
	vector<int> da,db;
	
	for(int i=0;i<n;++i) {
		if(s[i] != t[i]) {
			if(s[i] == 'a') da.push_back(i + 1);
			else db.push_back(i+1);
		}
	}
	vector<pii > res;
	if(sz(da) > 1) for(int i=0;i < sz(da) - 1; i += 2) res.push_back({da[i], da[i+1]});
	if(sz(da)%2) {
		res.push_back({da.back(),da.back()});
		db.push_back(da.back());
	}
	if(sz(db) > 1) for(int i=0;i < sz(db) - 1; i += 2) res.push_back({db[i], db[i+1]});
	
	if(sz(db)%2) {
		cout << -1;
	} else {
		cout << sz(res) << "\n";
		for(auto &x : res) cout << x.fi << " " << x.se << "\n";
	}
	
	
	
	

	#ifndef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
	#endif
	
	return 0;
}
