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
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

pii a[MAXN1];
int last[MAXN1];

signed main() {
	fast_cin();
	
	int t;
	cin >> t;
	while(t--) {
		int n,m;
		cin >> n >> m;
		memset(last, 0, sizeof(last[0])*(n+1));
		
		vector< vector<int> > res(n + 1, vector<int>(m + 1));
		vector<int> E[n*m + 5];
		
		for(int i=1;i<=n*m;++i) {
			int x;
			cin >> x;
			E[x].push_back(i);
		}
		
		sort(a + 1, a + n*m + 1, [&] (pii A, pii B) {
			if(A.fi == B.fi) return A.se < B.se;
			return A.fi > B.fi;
		});	
		int k = 1;
		for(int )
		
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}

