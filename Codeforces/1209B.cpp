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
const int MAXN1 = 105;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
bool state[MAXN1];
pii a[MAXN1];
int f[10*MAXN1];

signed main() {
	fast_cin();
	cin >> n;
	cin.ignore();
	for(int i=1;i<=n;++i) {
		char c;
		cin >> c;
		state[i] = (c - '0');
		//db(state[i]);
	}
	
	for(int i=1;i<=n;++i) {
		cin >> a[i].se >> a[i].fi;
	}
	int ans = 0;
	for(int i=1;i <= n;++i) {
		bool d = state[i];
		for(int pos = 0;pos < 10*MAXN1;++pos) {
			if(pos >= a[i].fi && (pos - a[i].fi)%a[i].se == 0) d = (d^1);
			f[pos] += d;
			ans = max(ans, f[pos]);
		}
	}
	
	//for(int i=0;i < MAXN1;++i) cout << f[i] << "\n";

	
	cout << ans;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}