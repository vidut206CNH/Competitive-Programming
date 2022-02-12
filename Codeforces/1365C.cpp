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

int n;
int a[MAXN1];
int b[2*MAXN1];
int f[MAXN1];
vector<int> d[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
	for(int i=1;i<=2*n; ++i) {
		if(i <= n) cin >> b[i];
		else b[i] = b[i - n];
		
		d[b[i]].push_back(i);
	}
	
	for(int i=1;i<=n;++i) {
		for(auto x : d[a[i]]) {
			if(x < i) continue;
			f[x - i]++;
		}
	}
	
	int res = 0;
	
	for(int i=0;i<=n;++i) {
		res = max(res, f[i]);
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}