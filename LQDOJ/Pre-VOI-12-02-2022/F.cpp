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
const int MAXN1 = 1e6+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,l;

int a[20];
int f[MAXN1][20];
bool can[20];

signed main() {
	fast_cin();
	
	cin >> l >> n;
	
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	
	for(int i = 1; i <= l; ++i) {
		for(int pos = 1; pos <= n; ++pos) {
			f[i][pos] = (f[i - 1][pos]*10 + 1)%a[pos];
		}
	}
		
	for(int d = l; d >= 1; --d) {
		for(int val = 9; val >= 1; --val) {
			memset(can, false, sizeof can);
			int cnt = 0;
			for(int pos = 1; pos <= n; ++pos) {
				can[pos] = (val*f[d][pos]%a[pos] == 0);
				cnt += can[pos];
			}
			
			if(cnt >= 2) {
				cout << d << " " << val;
				exit(0);
			}
		}
	}
	
	cout << "1 0";
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}