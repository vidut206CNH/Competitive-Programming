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
const int MAXN1 = 1e6;
const int MAXN2 = 1e6;
//const int inf = 1e18;

int n;
int a[MAXN1 + 5];
int lp[MAXN1 + 5];
int cnt[MAXN1 + 5];

int res = 0;

void f(int x) {
	if(x == 1) return;
	
	int d = lp[x];
	cnt[d]++;
	res = max(res, cnt[d]);
	while(x%d == 0) {
		x /= d;
	}
	
	f(x);
}


void rf(int x) {
	if(x == 1) return;
	
	int d = lp[x];
	cnt[d]--;
	while(x%d == 0) {
		x /= d;
	}
	
	rf(x);
}

signed main() {
	fast_cin();
	
	int t;
	cin >> t;
	for(int i = 1; i <= MAXN1; ++i) lp[i] = i;
	
	for(int i = 2; i*i <= MAXN1; ++i) {
		if(lp[i] != i) continue;
		
		for(int j = i*i; j <= MAXN1; j += i) {
			lp[j] = min(lp[j], i);
		}
	}
	

	
	
	while(t--) {
		
		res = 0;
		cin >> n;
		int d = 0;
		
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			a[i] = abs(a[i]);
			if(a[i] == 0) {
				d++;
			}
			else f(a[i]);
		}
		
		for(int i = 1; i <= n; ++i) {
			if(a[i] != 0) rf(a[i]);
		}
		
		cout << res + d << "\n";
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}