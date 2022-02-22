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
const int MAXN1 = 1e7+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int dp[MAXN1][10];
vector<int> a(10);
int x;
int n;


int solve(int val,int pos) {
	if(val < 0) return 0;
	if(val == 0) return 1;
	if(dp[val][pos] != -1) return dp[val][pos];
	
	int sum = 0;
	
	for(int d = pos; d <= n; ++d) {
		sum += solve(val - a[d], d);
	}
	
	return dp[val][pos] = sum;
	
}

signed main() {
	fast_cin();
	cin >> x >> n;
	set<int> st;
	for(int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		st.insert(val);
	}
	n = -1;
	for(auto val : st) {
		a[++n] = val;
	}
	memset(dp, -1, sizeof dp);
	cout << solve(x, 0);
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}