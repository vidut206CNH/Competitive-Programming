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

int q;
int f[MAXN1];
int cnt[MAXN1];
bool isp[MAXN1];

signed main() {
	fast_cin();
	memset(isp, true, sizeof isp);
	for(int i = 2; i*i < MAXN1; ++i) {
		if(isp[i] == false) continue;
		for(int j = i*i; j < MAXN1; j += i) isp[j] = false; 
	}	
	
	
	for(int i = 2; i < MAXN1; ++i) {
		f[i] = f[i - 1];
		cnt[i] = cnt[i - 1];
		if(isp[i]) {
			cnt[i]++;
			f[i] += i;
		}
	}
	
	cin >> q;
	while(q--) {
		int l, r, val;
		cin >> l >> r >> val;
		int res = 0;
		if(val <= r) {
			if(val <= l) {
				res += ((f[r] - f[l - 1]) - (cnt[r] - cnt[l - 1])*val);
			}
			
			else {
				res += (val*(cnt[val] - cnt[l - 1]) - (f[val] - f[l - 1]));
				res += (f[r] - f[val] - val*(cnt[r] - cnt[val]));
			}
			
		}
		
		else {
			res += (val*(cnt[r] - cnt[l - 1]) - (f[r] - f[l - 1]));
		}
		
		cout << res << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}