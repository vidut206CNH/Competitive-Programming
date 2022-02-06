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
const int MAXN1 = 2e5+15;
const int MAXN2 = 1e6+5;
const int inf = 1e18;
const int base = 1e5 + 1;

int n,k;
int bit[MAXN1];
int a[MAXN1];

int get(int pos) {
	int res = 0;
	for(;pos > 0; pos -= (pos & -pos)) res += bit[pos];
	return res;
}

void update(int pos) {
	
	for(;pos < MAXN1; pos += (pos & -pos)) bit[pos]++;
	
	
}

signed main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
		a[i] = (a[i] >= k ? 1 : -1) + a[i-1];
	}
	
	int res = 0;
	update(base);
	for(int i=1;i<=n;++i) {
		res += get(a[i] + base);
		//db(res);
		update(a[i] + base);
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}