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

int m,n;
int a[MAXN1][MAXN1];

vector<int> col[MAXN1], row[MAXN1];


signed main() {
	fast_cin();
	
	cin >> m >> n;
	
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) {
			cin >> a[i][j];
		}
	}
	
	for(int i=1;i<=m;++i) {
		set<int> s;
		for(int j=1;j<=n;++j) {
			s.insert(a[i][j]);
		}
		for(auto x : s) {
			row[i].push_back(x);
		}
	}
	
	for(int c=1;c <= n;++c) {
		set<int> s;
		for(int r=1;r <= m;++r) {
			s.insert(a[r][c]);
		}
		for(auto x : s) {
			col[c].push_back(x);
		}
	}
	
	for(int r=1;r <= m;++r)  {
		for(int c=1;c <= n;++c) {
			int val = a[r][c];
			
			int posc = lower_bound(col[c].begin(), col[c].end(), val) - col[c].begin();
			int posr = lower_bound(row[r].begin(), row[r].end(), val) - row[r].begin();
			int pos = max(posr,posc);
			int res = max(pos + sz(col[c]) - posc, pos + sz(row[r]) - posr);
			
			cout << res << " ";
		}
		
		cout << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}