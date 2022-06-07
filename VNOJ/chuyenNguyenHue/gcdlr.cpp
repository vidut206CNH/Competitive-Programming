/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
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
const int MAXN1 = 3e5+5;
const int MAXN2 = 1e6+5;

int n,q;
int M[MAXN1][20];
int minn[MAXN1][20];
int maxx[MAXN1][20];
int a[MAXN1];
int b[MAXN1];


int main() {
	fast_cin();
	
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i < n; ++i) b[i] = abs(a[i + 1] - a[i]);
	
	for(int i = 1; i <= n; ++i) {
		M[i][0] = b[i];
		minn[i][0] = a[i];
		maxx[i][0] = a[i];
	}
	
	for(int j = 1; (1 << j) <= n; ++j) {
		for(int i = 1; i <= n; ++i) {
			if(i + (1 << j) - 1 > n) break;
			
			minn[i][j] = min(minn[i][j - 1], minn[i + (1 << (j - 1))][j - 1]);
			maxx[i][j] = max(maxx[i][j - 1], maxx[i + (1 << (j - 1))][j - 1]);
			
			if(M[i][j - 1] == 0) M[i][j] = M[i + (1 << (j - 1))][j - 1];
			else if(M[i + (1 << (j - 1))][j - 1] == 0) M[i][j] = M[i][j - 1];
			else M[i][j] = gcd(M[i][j - 1], M[i + (1 << (j - 1))][j - 1]);
		}
	}
	
	while(q--) {
		int l, r;
		cin >> l >> r;
		int k = log2(r - l + 1);
		int mi = min(minn[l][k], minn[r - (1 << k) + 1][k]);
		int ma = max(maxx[l][k], maxx[r - (1 << k) + 1][k]);
		--r;
		k = log2(r - l + 1);
		if(mi == ma) {
			cout << -1 << "\n";
		}
		else cout << gcd(M[l][k], M[r - (1 << k) + 1][k]) << "\n";
	}
	
	

	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}