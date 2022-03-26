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

int n;
int dp[MAXN2];
int nex[MAXN2];
vector<int> ans;
int num[10];


int calc(int val) {
	if(val == 0) return 0;
	if(dp[val] != -1) return dp[val];
	
	int res = -1, choose = -1;
	for(int i = 9; i >= 1; --i) {
		if(val - num[i] >= 0) {
			int g = calc(val - num[i]);
			if(g > res) {
				res = g;
				choose = i;
			}
		}
	}
	nex[val] = choose;
	return dp[val] = res + 1;
}

void f(int val) {
	if(val == 0) return;
	if(nex[val] == -1) return;
	
	int d = nex[val];
	ans.push_back(d);
	f(val - num[d]);
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= 9; ++i) cin >> num[i];
	memset(dp, -1, sizeof dp);
	memset(nex, -1, sizeof nex);
	calc(n);
	f(n);
	
	if(sz(ans)) {
		for(auto x : ans) cout << x;
	}
	else cout << -1;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}