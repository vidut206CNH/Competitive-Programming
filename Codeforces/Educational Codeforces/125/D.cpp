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
const int MAXN1 = 3e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;



int n, cost;
int dp[MAXN2];
int best[MAXN2];

signed main() {
	fast_cin();
	
	
	cin >> n >> cost;
	memset(dp, -1, sizeof dp);
	for(int i = 1; i <= n; ++i) {
		int c,d,h;
		cin >> c >> d >> h;
		best[c] = (best[c] == 0 ? d*h : max(best[c], d*h));
	}
	
	for(int c = 1; c <= cost; ++c) {
		if(best[c] == 0) continue;
		
		for(int i = 1; c*i <= cost; ++i) {
			dp[c*i] = (dp[c*i] == -1 ? best[c]*i : max(best[c]*i, dp[c*i]));
		}
	}
	
	for(int i = 1; i <= cost; ++i) {
		dp[i] = (dp[i] == -1 ? (dp[i - 1]) : max(dp[i], dp[i - 1]));
	}
	
	int q;
	cin >> q;
	vector<pii > queries;
	vector<int> res(q + 2);
	for(int i = 1; i <= q; ++i) {
		int D, H;
		cin >> D >> H;
		queries.push_back({D*H, i});
	}
	
	sort(queries.begin(), queries.end());
	
	int id = 1;
	for(auto x : queries) {
		int val = x.fi;
		int pos = x.se;
		while(id <= cost && val >= dp[id]) ++id;
		res[pos] = (id == cost + 1 ? -1 : id);
	}
	
	for(int i = 1; i <= q; ++i) cout << res[i] << " ";
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}