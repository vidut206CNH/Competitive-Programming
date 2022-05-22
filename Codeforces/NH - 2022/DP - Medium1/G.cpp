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

int n, lim, q;
int cnt[35];
int a[MAXN1];
int xo[MAXN1];


void update1(int pos, int val) {
	for(;pos > 0; pos -= (pos & -pos)) xo[pos] ^= val; 
}

int get1(int pos) {
	int res = 0;
	for(;pos < MAXN1; pos += (pos & -pos)) res ^= xo[pos];
	return res;
}




signed main() {
	fast_cin();
	
	cin >> n >> q;
	lim = n;
	int num = n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		
		for(int j = 0; (1LL << j) <= a[i]; ++j) {
			if(a[i] >> j & 1) cnt[j]++;
		}
	}
	
	
	while(q--) {
		int type;
		cin >> type;
		if(type == 1) {
			++num;
			cin >> a[++lim];
			
			for(int i = 0; (1LL << i) <= a[lim]; ++i) {
				if(a[lim] >> i & 1) {
					cnt[i]++;
				}
			}
			
			// sum
			int res = 0;
			for(int i = 0; i < 33; ++i) {
				
				res += 1LL*cnt[i]*(1LL << i);
				
			}
			
			cout << res << "\n";
		}
		
		if(type == 2) {
			--num;
			int pos;
			cin >> pos;
			
			int val = a[pos]^get1(pos);
			
			for(int i = 0; (1LL << i) <= val; ++i) {
				if(val >> i & 1) {
					cnt[i]--;
				}
			}
			
			// sum
			int res = 0;
			for(int i = 0; i < 33; ++i) {
				res += 1LL*cnt[i]*(1LL << i);
			}
			
			cout << res << "\n";
		}
		
		if(type == 3) {
			int val;
			cin >> val;
			
			update1(lim, val);
			
			for(int i = 0; (1LL << i) <= val; ++i) {
				if(val >> i & 1) {
					cnt[i] = num - cnt[i];
				}
			}
			
			// sum
			long long res = 0;
			for(int i = 0; i < 33; ++i) {
				res += 1LL*cnt[i]*(1LL << i);
			}
			
			cout << res << "\n";
		}
	}
	
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}