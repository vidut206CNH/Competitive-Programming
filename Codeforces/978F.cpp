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

int n,k;
pii a[MAXN1];
int b[MAXN1];
int res[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].fi;
		b[i] = a[i].fi;
		a[i].se = i;
	}

	
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) {
		int id = a[i].se;
		if(i == 1 || a[i].fi != a[i - 1].fi) {
			res[id] += (i - 1);
		}
		else res[id] = res[a[i - 1].se];
	}
	while(k--) {
		int u,v;
		cin >> u >> v;
		if(b[u] > b[v]) res[u]--;
		if(b[v] > b[u]) res[v]--;
	}
	
	for(int i = 1; i <= n; ++i) cout << res[i] << " ";	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}