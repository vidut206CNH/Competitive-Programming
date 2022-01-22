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
const int inf = 1e9 + 5;

int n,x;
vector<pii > p[MAXN1];
vector<int> dp[MAXN1];

bool comp(const pii &A, const pii& B) {
	if(A.fi == B.fi) return A.se < B.se;
	else return A.fi < B.fi;
}

signed main() {
	fast_cin();
	
	cin >> n >> x;
	
	vector<int> q;
	
	for(int i=1;i<=n;++i) {
		int l,r,c;
		
		cin >> l >> r >> c;
		p[r - l + 1].push_back({l,c});
		
	}	
	
	for(int i=1;i<=x;++i) {
		sort(p[i].begin(), p[i].end(), comp);
		int lim = sz(p[i]);		
		dp[i].assign(lim + 5, inf);
		
		for(int pos = lim - 1; pos >= 0; --pos) {
			dp[i][pos] = min(dp[i][pos + 1], p[i][pos].se);
		}
		
	}
	
	int res = 2e9 + 5;
	
	for(int i=1;i<=x;++i) {
		for(auto m : p[i]) {
			int right = m.fi + i;
			int cost = m.se;
			
			int l=0,r = sz(p[x - i]) - 1,best = -1;
			
			while(l <= r) {
				int mid = (l+r) >> 1;
				if(p[x - i][mid].fi < right) {
					l = mid + 1;
				} else {
					best = dp[x - i][mid];
					r = mid - 1;
				}
			}
			
			if(best != -1) res = min(res, best + cost);
		}
	}
	
	if(res == (int)(2e9 + 5)) cout << -1;
	else cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}