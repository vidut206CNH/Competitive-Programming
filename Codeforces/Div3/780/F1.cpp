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
const int MAXN1 = 3e3+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;
int n;

char a[MAXN1];
int f[MAXN1];

signed main() {
	fast_cin();
	
	
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		int ans = 0;
		for(int l = 1; l <= n; ++l) {
			int cntplus = 0, cntminus = 0;
			f[0] = 0;
			for(int r = l; r <= n; ++r) {
				if(a[r] == '+') cntplus++;
				if(a[r] == '-') cntminus++;
				
				if(r > l && a[r] == '-' && a[r - 1] == '-') f[r - l + 1] = f[r - l - 1] + 1;
				else f[r - l + 1] = f[r - l];
				if(cntminus < cntplus) continue;
				if((cntminus - cntplus)%3 == 0 && f[r] >= (cntminus - cntplus)/3) ans++;
			}
			
			//db(ans);
		}
		//cerr << "\n";
		cout << ans << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}