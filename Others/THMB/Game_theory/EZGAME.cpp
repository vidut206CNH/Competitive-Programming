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
const int MAXN1 = 5e3+5;
const int MAXN2 = 1e6+5;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r) {
	return l + rng() * 1LL * rng()%(r - l + 1);
}

int f[MAXN1][MAXN1];
int dist[MAXN1][MAXN1];
vector<int> E[2][MAXN1];

int dp(int W, int B) {
	
	if(f[W][B] != -1) return f[W][B];
	
	f[W][B] = 0;
	int MX = 0, MN = MOD;
	
	for(int v : E[0][W]) {
		
		if(dp(v, B) == false) {
			
			f[W][B] = true;
			MN = min(MN, dist[v][B] + 1);
					
		}
		
		else MX = max(MX, dist[v][B] + 1);
	}
	
	for(int v : E[1][B]) {
		
		if(dp(W, v) == false) {
			
			f[W][B] = true;
			MN = min(MN, dist[W][v] + 1);
				
		}
		
		else MX = max(MX, dist[W][v] + 1);
	}
	
	dist[W][B] = (f[W][B] == 0 ? MX : MN);
	
/*	db(W);
	db(B);
	db(f[W][B]);
	db(dist[W][B]);
	cerr << "\n";*/
	
	return f[W][B];
}

int n,m,w,b;

int main() {
	fast_cin();
	
	
	cin >> n >> m >> w >> b;
	for(int i = 1; i <= m; ++i) {
		int u,v;
		cin >> u >> v;
		E[0][u].push_back(v);
		E[1][v].push_back(u);
	}
	memset(f, -1, sizeof f);
	dp(w, b);
	
	cout << dist[w][b];

	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}