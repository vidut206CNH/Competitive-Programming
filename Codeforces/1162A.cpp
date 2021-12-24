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
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "


typedef pair<int,int> pii;


const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

int n,h,m;
int a[55];
pair<pii, int> p[55];

bool comp(const pair<pii, int>& A, pair<pii, int>& B) {
	return A.se < B.se;
}

signed main() {
	fast_cin();
	cin >> n >> h >> m;
	memset(a,-1,sizeof a);
	for(int i=1;i<=m;++i) {
		cin >> p[i].fi.fi >> p[i].fi.se >> p[i].se;
	}
	sort(p + 1, p + m + 1, comp);
	for(int i=1;i<=m;++i) {
		for(int pos = p[i].fi.fi; pos <= p[i].fi.se; pos++) {
			if(a[pos] == -1) a[pos] = p[i].se;
		}
	}
	int res = 0;
	for(int i=1;i<=n;++i) {
		if(a[i] == -1) a[i] = h;
		res += a[i]*a[i];
		//cout << a[i] << " ";
	}
	cout << res;
	
	
	
	

	#ifndef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock_t() / CLOCKS_PER_SEC << " s.\n ";
	#endif
	
	return 0;
}
