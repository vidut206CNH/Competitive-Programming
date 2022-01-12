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
const int MAXN1 = 1e3+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,q;
char a[MAXN1][MAXN1];
int bit[MAXN1][MAXN1];

void update(int x,int y, int val = -1) {
	if(val==-1) {
		if(a[x][y] == '*') {
			a[x][y] = '.';
			val = -1;
		} else {
			a[x][y] = '*';
			val = +1;
		}
	}	
	for(int i=x;i <= n; i += i&-i) {
		for(int j=y;j <= n; j += j&-j) {
			bit[i][j] += val;
		}
	}
}

int get(int x,int y) {
	int res = 0;
	if(x == 0 || y == 0) return res;
	
	for(int i=x;i > 0; i -= i&-i) {
		for(int j=y;j > 0; j -= j&-j) {
			res += bit[i][j];
		}
	}
	return res;
}

signed main() {
	fast_cin();
	
	cin >> n >> q;
	cin.ignore();
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			cin >> a[i][j];
			update(i, j, (int)(a[i][j] == '*'));
		}
		cin.ignore();
	}
	
	for(int i=1;i<=q;++i) {
		int t;
		cin >> t;
		if(t == 1) {
			int x,y;
			cin >> x >> y;
			update(x,y);
			continue;
		}
		int x,y,u,v;
		cin >> x >> y >> u >> v;
		//db(get(x-1,v));
		cout << get(u,v) - get(x-1,v) - get(u, y-1) + get(x-1, y-1) << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}