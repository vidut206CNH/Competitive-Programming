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
const int MAXN1 = 1 << 22;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m,k;
bool bad[105][105];
int res[105],cnt = 0;
bool visited[105];
int f[105];

void func(int cur, int pre) {
/*	db(cur);
	db(pre);
	cerr << "\n";*/
	if(cur == n + 1) {
		cnt++;
		if(cnt == k) {
			for(int i=1;i<=n;++i) cout << res[i] << " ";
			exit(0);
		}
		return;
	}
	for(int i=1;i<=n;++i) {
		if(!visited[i] && !bad[i][pre]) {
			visited[i] = 1;
			res[cur] = i;
			func(cur+1, i);
			visited[i] = false;
		}
	}
}

void sub1() {
	func(1,0);
}


signed main() {
	fast_cin();
	
	cin >> n >> m >> k;
	for(int i=1;i<=m;++i) {
		int u,v;
		cin >> u >> v;
		bad[u][v] = true;
		bad[v][u] = true;
	}
	sub1();
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}