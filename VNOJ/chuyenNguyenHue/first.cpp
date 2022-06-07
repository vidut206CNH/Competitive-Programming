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
int L[MAXN1][20];
int R[MAXN1][20];
int a[MAXN1];



int main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	memset(L, 0x3f, sizeof L);
	memset(R, 0x3f, sizeof R);
	
	for(int i = 1; i <= n; ++i) {
		L[i][0] = a[i];
		R[i][0] = a[i];
	}
	
	for(int j = 1; (1 << j) < MAXN1; ++j) {
		for(int i = 1; i <= n; ++i) {
			if(i + (1 << j) - 1 > n) break;
			R[i][j] = max(R[i][j - 1], R[i + (1 << (j - 1))][j - 1]);
		}
	}
	
	for(int j = 1; (1 << j) < MAXN1; ++j) {
		for(int i = n; i >= 1; --i) {
			if(i - (1 << j) + 1 < 0) break;
			
			L[i][j] = max(L[i][j - 1], L[i - (1 << (j - 1))][j - 1]);
		}
	}
	
	
	for(int i = 1; i <= n; ++i) {
		int pl = i - 1, pr = i + 1;
		int l =  20, r = 20;
		
		while(l >= 0 && pl >= 1) {
			
			if(pl - (1 << l) + 1 < 1) {
				--l;
				continue;
			}
			
			if(L[pl][l] <= a[i]) {
				pl = pl - (1 << l);
			}
			
			--l;
		}
		
		while(r >= 0 && pr <= n) {
			if(pr + (1 << r) - 1 > n) {
				--r;
			}
			
			if(R[pr][r] <= a[i]) {
				pr = pr + (1 << r);
			}
			--r;
		}
		
		int res1 = -1, res2 = -1;
		res1 = (pl >= 1 ? pl : res1);
		res2 = (pr <= n ? pr : res2);
		
		cout << res1 << " " << res2 << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}