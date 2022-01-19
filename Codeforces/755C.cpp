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
const int MAXN1 = 1e4+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
vector<int> E[MAXN1];
int d = 0;

int p[MAXN1];

void dfs(int cur, int par) {
	
	for(auto v : E[cur]) {
		if(v == par) continue;
		p[v] = p[cur];
		dfs(v, cur);
	}
}

signed main() {
	fast_cin();
	
	cin >> n;
	
	for(int i=1;i<=n;++i) {
		int v;
		cin >> v;
		
		E[i].push_back(v);
		E[v].push_back(i);
	}
	
	for(int i=1;i<=n;++i) {
		if(p[i] == 0) {
			p[i] = ++d;
			dfs(i,0);
		}
	}
	
	cout << d;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}