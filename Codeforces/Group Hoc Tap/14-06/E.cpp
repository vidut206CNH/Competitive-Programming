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
const int MAXN1 = 5005;
const int MAXN2 = 1e6+5;
const long long inf = 1e18;
int n,C;
int cost[MAXN1];
int d[MAXN1];
vector<int> child[MAXN1];
long long dp[MAXN1][MAXN1][2];
int subsz[MAXN1];

void minimize(long long &A, long long B) {A = min(A, B);}

void dfs(int u) {
	dp[u][0][0] = 0;
	dp[u][1][0] = cost[u];
	dp[u][1][1] = d[u];
	
	subsz[u] = 1;	
	for(int v : child[u]) {
		dfs(v);
		for(int x = subsz[u]; x >= 0; --x) {
			for(int y = subsz[v]; y >= 0; --y) {
				minimize(dp[u][x + y][1], dp[u][x][1] + min(dp[v][y][0], dp[v][y][1]));
				minimize(dp[u][x + y][0], dp[u][x][0] + dp[v][y][0]);
			}
		}
		
		subsz[u] += subsz[v];
	}
}


int main() {
	fast_cin();
	
	cin >> n >> C;
	for(int i = 1; i <= n; ++i) {
		
		cin >> cost[i] >> d[i];
		d[i] = cost[i] - d[i];
		
		if(i >= 2) {
			int x;
			cin >> x;
			child[x].push_back(i);
		}
		
	}
	memset(dp, 0x3f, sizeof dp);
	
	dfs(1);
	
	for(int k = n; k >= 0; --k) {
		if(dp[1][k][0] <= C || dp[1][k][1] <= C) {
			cout << k;
			return 0;
		}
	}
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}