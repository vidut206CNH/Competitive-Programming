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
const int MAXN1 = 1005;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int m,n,q;
int a[MAXN1][MAXN1];
int f[MAXN1][MAXN1];


int posx = 1, posy = 1;

int get1(int u, int v) {
	u = u + posx - 1;
	v = v + posy - 1;
/*	db(u);
	db(v);
	db(a[u][v]);
	cerr << "\n";*/
	return f[u][v] - f[posx - 1][v] - f[u][posy - 1] + f[posx - 1][posy - 1];
}

int get2(int u, int v, int s, int t) {
	return get1(s,t) - get1(u - 1, t) - get1(s, v - 1) + get1(u - 1, v - 1);
}

signed main() {
	fast_cin();
	
	cin >> m >> n;
		
	for(int i=1; i <= m; ++i) {
		for(int j=1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	
	for(int i = 1; i <= 2*m; ++i) {
		for(int j = 1; j <= 2*n;++j) {
			int u = i%m;
			int v = j%n;
			if(u == 0) u = m;
			if(v == 0) v = n;
			
			a[i][j] = a[u][v];
		}
	}
	
	
	for(int i = 1; i <= 2*m; ++i) {
		for(int j = 1; j <= 2*n; ++j) {
			f[i][j] = f[i-1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
		}
	}
	
	
	cin >> q;
	
	
	while(q--) {
		int type;
		cin >> type;
		if(type == 0) {
			int x,y;
			cin >> y >> x;
			posx += x;
			posy += y;
			posx %= m;
			posy %= n;
			if(posx == 0) posx = m;
			if(posy == 0) posy = n;
		}
		
		else {
			int u,v,s,t;
			cin >> u >> v >> s >> t;
			cout << get2(u, v, s, t) << "\n";
		}
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}