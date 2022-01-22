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

int t;


signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		string s,d;
		cin >> s >> d;
		vector<int> p[30];
		
		for(int i=0;i < sz(s);++i) {
			int m = s[i] - 'a';
			p[m].push_back(i);	
		}
		int res = 1,lastpos = -1;
		bool bad = 0;
		
		for(int i=0;i < sz(d);++i) {
			int cur = d[i] - 'a';
			if(sz(p[cur]) == 0) {
				bad = 1;
				break;
			}
			int pos = lower_bound(p[cur].begin(), p[cur].end(), lastpos + 1) - p[cur].begin();
			if(pos == sz(p[cur])) {
				res++;
				lastpos = p[cur][0];
			} else {
				lastpos = p[cur][pos];
			}
		}
		
		if(bad) cout << "-1\n";
		else cout << res << "\n";
		
	}	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}