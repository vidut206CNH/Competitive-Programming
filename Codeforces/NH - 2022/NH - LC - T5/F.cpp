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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
//const int inf = 1e18;

struct data{
	int l, r, z;
};

int n,m;

data a[MAXN1];
int f[20][MAXN1];
int d[MAXN1];
int rmq[25][MAXN1];

int get(int l, int r) {
	int k = log2(r - l + 1);
	return gcd(rmq[k][l], rmq[k][r - (1 << k) + 1]);
}

signed main() {
	fast_cin();
	
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> a[i].l >> a[i].r >> a[i].z;
		
		f[a[i].z][a[i].l]++;
		f[a[i].z][a[i].r + 1]--;
		
	}
	
	for(int pos = 1; pos <= n; ++pos) {
		int mul = 1;
		
		for(int i = 2; i <= 16; ++i) {
			f[i][pos] += f[i][pos - 1];
			if(f[i][pos]) {
				
				mul = lcm(mul, i);
				
			}
		}
		
		d[pos] = mul;
	}
	
	for(int i = 1; i <= n; ++i) {
		rmq[0][i] = d[i];
	}
	
	for(int pos = n; pos >= 1; --pos) {
		for(int i = 1; pos + (1 << i) - 1 <= n; ++i) {
			rmq[i][pos] = gcd(rmq[i - 1][pos], rmq[i - 1][pos + (1 << (i - 1))]);
		}
	}
	
	bool ok = true;
	for(int i = 1; i <= m; ++i) {
		int l = a[i].l;
		int r = a[i].r;
		int z = a[i].z;
		
		ok &= (get(l, r) == z);
	}
	
	if(!ok) cout << "Impossible";
	else {
		for(int i = 1; i <= n; ++i) cout << d[i] << " ";
	}
	
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}