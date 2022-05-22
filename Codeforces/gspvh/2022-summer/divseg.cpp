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
const int inf = 1e17;

int n;
int a[MAXN2];

int f[MAXN2], minf[MAXN2];
int s[MAXN2], mins[MAXN2];

signed main() {
	fast_cin();
	
/*	freopen("divseq.inp", "r", stdin);
	freopen("divseq.out", "w", stdout);*/
	
	cin >> n;
	
	for(int i = 1; i <= n; ++i) cin >> a[i];
	int sum = 0;
	for(int i = n; i >= 1; --i) {
		sum += a[i];
		s[i] = min({s[i + 1] + a[i], a[i], 0LL});
		mins[i] = min(mins[i + 1], s[i]);
	}
	
	int res = inf;
	
	for(int i = 1; i <= n; ++i) {
		f[i] = min({f[i - 1] + a[i], a[i], 0LL});
		minf[i] = min(minf[i - 1], f[i]);
		
		res = min(res, minf[i] + mins[i + 1]);
	}
	
	
	cout << sum - 2*res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}