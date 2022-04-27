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

int t;
string s;

int f[MAXN1];

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		cin >> s;
		int n = sz(s);
		for(int i = 0; i <= sz(s); ++i) f[i] = 0;
		s = '0' + s;
		
		for(int i = 1; i <= n; ++i) {
			if(s[i] == '1') f[i] = 0;
			else f[i] = f[i - 1] + 1;
		}
		int res = 0;
		for(int i = 1; i <= n; ++i) {
			int val = 0;
			for(int j = i; j > max(i - 20, 0LL); --j) {
				val = val + ((s[j] - '0') << (i - j));
				if(s[j] == '1' && i - j + 1 <= val && i - j + 1 + f[j - 1] >= val) res++;
			}
		}
		
		cout << res << '\n';
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}