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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;





int n;
//vector<state> dp;
multiset<vector<int>> dp;
int trace[MAXN1];

signed main() {
	fast_cin();
	memset(trace, -1, sizeof trace);
		
	int res = 0, ed = 0;
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		auto pos = dp.upper_bound({x, 0, 0});
		
		if(pos == dp.begin()) {
			dp.insert({x, 1, i});
			continue;
		}
		
		--pos;
		if((*pos)[0] != x - 1) dp.insert({x, 1, i});
		
		
		else {
			
			trace[i] = (*pos)[2];
			vector<int> cur = {x,  (*pos)[1] + 1, i};
			
			if(res < cur[1]) {
				res = cur[1];
				ed = i;
			}
			
			dp.erase(pos);
			dp.insert(cur);
		}
	}
	
	if(res == 0) {
		cout << 1 << "\n" << 1;
		exit(0);
	}
	
	vector<int> p;
	
	while(ed != -1) {
		p.push_back(ed);
		ed = trace[ed];
	}
	reverse(p.begin(), p.end());
	cout << res << "\n";
	for(auto x : p) cout << x << " ";
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}