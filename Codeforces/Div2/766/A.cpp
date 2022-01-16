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
const int MAXN2 = 1e6+5;
const int inf = 1e18;

char a[55][55];
int n,m,r,c;

signed main() {
	fast_cin();
	
	int t=1;
	cin >> t;
	
	while(t--) {
		cin >> m >> n >> r >> c;
		cin.ignore();
		bool good = 0;
		for(int i=1;i<=m;++i) {
			for(int j=1;j<=n;++j) {
				cin >> a[i][j];
				good |= (a[i][j] == 'B');
			}
		}
		
		if(!good) {
			cout << "-1\n";
			continue;
		}
		if(a[r][c] == 'B') {
			cout << "0\n";
			continue;
		}
		bool oc = 0;
		for(int i=1;i<=n;++i) {
			oc |= (a[r][i]  == 'B');
		}
		for(int i=1;i<=m;++i) {
			oc |= (a[i][c] == 'B');
		}
		if(oc) cout << "1\n";
		else cout << "2\n";
		
	}	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}