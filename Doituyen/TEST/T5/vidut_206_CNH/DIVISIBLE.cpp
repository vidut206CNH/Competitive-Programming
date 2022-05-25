/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
//const int inf = 1e18;

int t;
int m,n;
int lf[MAXN2];
int cnt[MAXN2];

void calc(int val, int g) {
	if(val == 1) return;
	int d = lf[val];
	
	while(val%d == 0) {
		val /= d;
		cnt[d] += g;
	}
	
	calc(val, g);
}



signed main() {
	fast_cin();
	
	
	freopen("DIVISIBLE.INP", "r", stdin);
	freopen("DIVISIBLE.OUT", "w", stdout);
	
	for(int i = 1; i < MAXN2; ++i) lf[i] = i;
	
	for(int i = 2; i*i < MAXN2; ++i) {
		if(lf[i] != i) continue;
		for(int j = i*i; j < MAXN2; j += i) lf[j] = min(lf[j], i);
	
	}
	
	cin >> t;
	while(t--) {
		cin >> m >> n;
		memset(cnt, 0, sizeof cnt);
		bool zero0 = 0, zero1 = 0;
		
		for(int i = 1; i <= m; ++i) {
			int x;
			cin >> x;
			if(x == 0) zero0 = true;
			else calc(x, +1);
		}
		
		for(int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			if(x == 0) zero1 = true;
			else calc(x, -1);
		}
		
		if(zero1) {
			cout << "NO\n";
			continue;
		}
		
		if(zero0) {
			cout << "YES\n";
			continue;
		}
		
		bool ok = true;
		for(int i = 1; i < MAXN2; ++i) {
			ok &= (cnt[i] >= 0);
		}
		
		cout << (ok ? "YES\n" : "NO\n");
		
		
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}