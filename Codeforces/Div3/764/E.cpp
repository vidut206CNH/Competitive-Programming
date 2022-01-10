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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e3+5;
const int inf = 1e18;
const int base = 17;
int t;
bool ok[MAXN1];
pii p[MAXN1];

char a[MAXN2][MAXN2];
char b[MAXN2];

signed main() {
	fast_cin();
	
	cin >> t;
	
	while(t--) {
		
		int n,m;
		cin >> n >> m;
		vector< pair<pii, int> > res;
		bool good = 1;
		cin.ignore();
		
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=m;++j) {
				cin >> a[i][j];
				a[i][j] = a[i][j] - '0' + 2;
				if(j > 1) {
					ok[a[i][j-1]*base + a[i][j]] = 1;
					p[a[i][j-1]*base + a[i][j]] = {j-1, i};
				}
				if(j > 2) {
					ok[a[i][j-2]*base*base + a[i][j-1]*base + a[i][j]] = 1;
					p[a[i][j-2]*base*base + a[i][j-1]*base + a[i][j]] = {j-2, i};
				}
/*				db((int)a[i][j]);
				cerr << "\n";*/
			}
			cin.ignore();
		}
		for(int i=1;i<=m;++i) {
			cin >> b[i];
			b[i] = b[i] - '0' + 2;
		}
		cin.ignore();
		
		if(m%2==0) {
			for(int i=1;i < m; i += 2) {
				int d = b[i]*base + b[i+1];
/*				db(d);
				db(ok[d]);
				cerr << "\n";*/
				good &= ok[d];
				res.push_back({{p[d].fi, p[d].fi + 1}, p[d].se});
			}
			
			if(!good) {
				bool pre = 1,find = 0;
				for(int i=1;i <=m-2;i += 2) {
					if(!pre) break;
					bool tmp = 1;
					int d = b[i]*base*base + b[i+1]*base + b[i+2];
					tmp &= ok[d];
					if(tmp) {
						bool pre1 = 1;
						for(int j=i+3;j <= m-2;j += 2) {
							int g = b[j]*base*base + b[j+1]*base + b[j+2];
							tmp &=  
						}
					}
					if(find) break;
					
					
				}
			}
		}
		
		else {
			bool pre = 1, find = 0;
			for(int i=1; i <= m-2; i+=2) {
				if(!pre) break;
				bool tmp = 1;
				int d = b[i]*base*base + b[i+1]*base + b[i+2];
				tmp &= ok[d];
				for(int j=i + 3;j <= m;j += 2) {
					tmp &= (ok[b[j]*base + b[j+1]]);
				}
				if(tmp) {
					res.push_back({{p[d].fi, p[d].fi+2}, p[d].se});
					db(d);
					for(int j=i+3;j<=m;j += 2) {
						int g = b[j]*base + b[j+1];
						res.push_back({{p[g].fi, p[g].fi + 1}, p[g].se});
					}
					find = 1;
					break;
				}
				//db(tmp);
				d = b[i]*base + b[i+1];
				pre &= ok[d];
				res.push_back({{p[d].fi, p[d].fi + 1}, p[d].se});
			}
			
			good &= find;
		}
		
		//memset
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=m;++j) {
				if(j > 1) {
					ok[a[i][j-1]*base + a[i][j]] = 0;
				}
				if(j > 2) {
					ok[a[i][j-2]*base*base + a[i][j-1]*base + a[i][j]] = 0;
				}
			}
		}
		
		//db(good);
		
		//cerr << "\n\n";
		if(good) {
			cout << sz(res) << "\n";
			for(auto x : res) cout << x.fi.fi << " " << x.fi.se << " " << x.se << "\n";
		}
		
		else cout << "-1\n";
	}	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}