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

int n,k;
int p[MAXN1];
vector<int> child[MAXN1];
int dp[MAXN1];
int res = 0;

void dfs(int x) {
	for(auto v : child[x]) {
		dfs(v);
		if(x != 1 && dp[v] == k - 1) {
			res++;
		} 
		
		else if(x == 1 && dp[v] == k) {
			res++;
		}
		
		else {
			dp[x] = max(dp[v] + 1, dp[x]);
		}
	}
}

signed main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	res += (p[1] != 1);
	for(int i = 2; i <= n; ++i) {
		child[p[i]].push_back(i);
	}
	
	dfs(1);
	
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}