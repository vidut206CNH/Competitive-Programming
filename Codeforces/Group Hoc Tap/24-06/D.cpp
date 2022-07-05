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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

int n;
long long a[405][405];
long long R[405], C[405];
long long B[405];

int main() {
	fast_cin();
	
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			R[i] += a[i][j];
			C[j] += a[i][j];
		}
	}
	long long res = -1e18;
	
	for(int r1 = 1; r1 <= n; ++r1) {
		long long sum = 0;
		
		for(int c = 1; c <= n; ++c) B[c] = C[c];
		
		long long best0 = 0;
		for(int c = 1; c <= n; ++c) {
			best0 = max({0LL, B[c] + best0});
			res = max(res, sum + best0);	
		}
		
		for(int r2 = 1; r2 <= n; ++r2) {
			sum += R[r2];
			
			for(int c = 1; c <= n; ++c) B[c] -= a[r2][c];
			
			long long best = 0;
			for(int c = 1; c <= n; ++c) {
				best = max({B[c], B[c] + best, 0LL});
				res = max(res, sum + best);
				
			}
		}
	}
	
	if(res == 0) {
		res = -1e18;
		for(int i = 1; i <= n; ++i) res = max({res, R[i], C[i]}); 
	}
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}