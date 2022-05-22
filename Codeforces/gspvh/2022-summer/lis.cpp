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
const int MAXN1 = 222222;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int a[MAXN1];
vector<int> vals;
int bit[3][2*MAXN1];
int dp[3][MAXN1];

int get(int state, int pos) {
	int res = 0;
	for(;pos > 0; pos -= (pos&-pos)) res = max(res, bit[state][pos]);
	return res; 
}

void update(int state, int pos, int val) {
	
	for(;pos <= sz(vals); pos += (pos & -pos)) bit[state][pos] = max(bit[state][pos], val);
	
}

signed main() {
	fast_cin();
	
/*	freopen("lis.inp", "r", stdin);
	freopen("lis.out", "w", stdout);*/
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		vals.push_back(-a[i]);
		vals.push_back(a[i]);
	}
	
	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
	
	int res = 0;
	for(int pos = 1; pos <= n; ++pos) {
		for(int state = 0; state < 3; ++state) {
			
			dp[state][pos] = 1;
			int t = lower_bound(vals.begin(), vals.end(), (state == 1 ? -a[pos] : a[pos])) - vals.begin() + 1;
			
			for(int pre = 0; pre <= state; ++pre) {
				dp[state][pos] = max(dp[state][pos], get(pre, t - 1) + 1);			
			}
			
			res = max(res, dp[state][pos]);
		}
		
		
		for(int state = 0; state < 3; ++state) {
			int t = lower_bound(vals.begin(), vals.end(), (state == 1 ? -a[pos] : a[pos])) - vals.begin() + 1;
			update(state, t, dp[state][pos]);
		}
		
		
	}
	
	cout << res;
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}