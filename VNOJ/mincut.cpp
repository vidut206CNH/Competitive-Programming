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
#define INF 2e15
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

int m,n,q;


int get_sum(const vector< vector<int> >& f, const int& x, const int& y, const int&u, const int& v) {
	return f[u][v] - f[x-1][v] - f[u][y-1] + f[x-1][y-1];
}

int find_row(int x, int y, int u, int v, const vector< vector<int> >& f) {
	int l = x, r = u;
	int ans = INF;
	int sum = get_sum(f, x, y, u, v);
	while(l <= r) {
		int mid = (l+r) >> 1;
		int tmp = get_sum(f, x, y, mid, v);
		ans = min(ans, abs(sum - 2*tmp));
		
		if(2*tmp < sum) l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}

int find_col(int x, int y, int u, int v, const vector< vector<int> >& f) {
	int l = y, r = v;
	int ans = INF;
	int sum = get_sum(f, x, y, u, v);
	while(l <= r) {
		int mid = (l+r) >> 1;
		int tmp = get_sum(f, x, y, u, mid);
		
		ans = min(ans, abs(sum - 2*tmp));
		
		if(2*tmp < sum) l = mid + 1;
		else r = mid - 1; 
	}
	return ans;
}


signed main() {
	fast_cin();
	
	cin >> m >> n >> q;
	vector< vector<int> > f(m+5, vector<int>(n+5, 0)), a(m+5, vector<int>(n+5, 0));
	
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) {
			cin >> a[i][j];
			f[i][j] = f[i-1][j] + f[i][j-1] + a[i][j] - f[i-1][j-1];
		}
	}
	
	for(int i=1;i<=q;++i) {
		int x,y,u,v;
		cin >> x >> y >> u >> v;
		int ans = INF;
		ans = min(ans, find_row(x, y, u, v, f));
		//db(ans);
		ans = min(ans, find_col(x, y, u, v, f));
		cout << ans << "\n";	
	}
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}