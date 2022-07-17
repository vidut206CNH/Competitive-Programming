/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
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
const int MAXN1 = 6e5+5;
const int MAXN2 = 1e6+5;

int n;
long long C;
int a[MAXN1];
long long p[MAXN1];
int ans[MAXN1];
pair<long long, int> g[MAXN1];

bool solve(int X) {
	for(int i = 1; i <= n; ++i) {
		if(a[i] >= X) {
			g[i].fi = 0;
		}
		else {
			g[i].fi = (C/p[i] < (X - a[i]) ? C + 1 : 1LL*p[i]*(X - a[i]));
		}
		
		g[i].se = i;
	}
	
	long long tmp = C;
	sort(g + 1, g + n + 1);
	
	memset(ans, 0, sizeof ans);
	
	for(int i = 1; i <= X; ++i) {
		tmp -= g[i].fi;
		if(tmp < 0) return false;
		
		int id = g[i].se;
		ans[id] = max(0, X - a[id]);
	}
	
	return true;
}

int main() {
	fast_cin();
	
/*	freopen("hindex.inp", "r", stdin);
	freopen("hindex.out", "w", stdout);*/
	
	cin >> n >> C;
	for(int i = 1;i <= n; ++i) cin >> a[i];
	for(int i = 1;i <= n; ++i) cin >> p[i];
	
	
	int low = 0, high = n, res = 0;
	
	while(low <= high) {
		
		int mid = (low + high) >> 1;
		bool ok = solve(mid);
		if(ok) {
			res = mid;
			low = mid + 1;
		}	
		
		else high = mid - 1;
	}
	
	solve(res);
	
	cout << res << "\n";
	
	for(int i = 1; i <= n; ++i) cout << ans[i] << " ";
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}