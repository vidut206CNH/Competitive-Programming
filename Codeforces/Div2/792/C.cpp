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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;
int m,n;
vector<int> col[MAXN1];


signed main() {
	fast_cin();
	
	
	cin >> t;
	while(t--) {
		cin >> m >> n;
		vector<vector<int> > a(m + 1, vector<int>(n + 1, 0));
		
		for(int i = 0; i < n; ++i) {
			col[i].clear();
		}
		
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				cin >> a[i][j];
			}
		}
		bool bad = false;
		int res1 = 1, res2 = 1;
		
		for(int r = 0; r < m; ++r) {
			vector<pii> p;
			for(int c = 0; c < n; ++c) {
				p.push_back({a[r][c], c});
			}
			
			sort(p.begin(), p.end());
			int cnt = 0;
			int id1 = -1, id2 = -1;
			for(int i = 0; i < n; ++i) {
				int id = p[i].se;
				cnt += (id != i);
				if(id1 == -1 && id != i) id1 = i;
				else if (id != i) id2 = i;
			}
			
			if(cnt > 2) {
				bad = true;
				break;
			}
			
			if(cnt == 2) {
				
				for(int i = 0; i < m; ++i) {
					swap(a[i][id1], a[i][id2]);
				}
				
				bool ok = true;
				for(int i = 0; i < m; ++i) {
					for(int j = 0; j < n; ++j) {
						ok &= (j == 0 || a[i][j] >= a[i][j - 1]);
					}
				}
				
				if(!ok) {
					bad = true;
					break;
				}
				
				res1 = id1 + 1;
				res2 = id2 + 1;
				
			}
		}
		
		
		if(bad) cout << -1 << "\n";
		else cout << res1 << " " << res2 << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}