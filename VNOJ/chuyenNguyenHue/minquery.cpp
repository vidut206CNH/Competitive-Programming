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
int M[MAXN1][30];
int a[MAXN1];



int main() {
	fast_cin();
	
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) M[i][0] = a[i];
	for(int j = 1; (1 << j) < MAXN1; ++j) {
		for(int i = 1; i <= n; ++i) {
			if(i + (1 << j) - 1 > n) break;
			M[i][j] = min(M[i][j - 1], M[i + (1 << (j - 1))][j - 1]);
		}
	}
	
	while(q--) {
		int l, r;
		cin >> l >> r;
		int k = log2(r - l + 1);
		cout << min(M[l][k], M[r - (1 << k) + 1][k]) << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}