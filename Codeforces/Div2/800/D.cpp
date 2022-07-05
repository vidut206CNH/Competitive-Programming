/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
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

int t;
int n;
vector<int> child[MAXN1];
long long L[MAXN1],  R[MAXN1];
long long dp[MAXN1], res = 0;

void dfs(int u) {
	
	if(sz(child[u]) == 0) {
		dp[u] = R[u];
		res++;
		return;
	}
	
	long long sum = 0;
	for(int v : child[u]) {
		dfs(v);
		
		sum += dp[v];
	}
	
	if(sum > R[u]) {
		dp[u] = R[u];
	}	
	else if(sum < L[u]) {
		res++;
		dp[u] = R[u];
	}
	
	else {
		dp[u] = sum;
	}
	
}

int main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) child[i].clear();
		for(int i = 2; i <= n; ++i) {
			int x;
			cin >> x;
			child[x].push_back(i);
		}
		for(int i = 1; i <= n; ++i) cin >> L[i] >> R[i];
		res = 0;
		dfs(1);
		
		cout << res << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}