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
long long w[MAXN1];
long long sum[2][MAXN1];
pii M[MAXN1];


void maximize(long long &res, long long X) {res = max(res, X); }

int main() {
	fast_cin();
	
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> sum[1][i];
	for(int i = 1; i < n; ++i) {
		cin >> M[i].fi >> M[i].se;
	}
	
	for(int i = n - 1; i >= 1; --i) {
		int p = M[i].fi;
		pii cur = {sum[0][p], sum[1][p]};
		if(M[i].se == 0) {
			sum[0][p] = cur.fi + max(sum[0][i], sum[1][i]);
			sum[1][p] = cur.se + sum[0][i];
		}
		
		if(M[i].se == 1) {
			
			
			maximize(sum[1][p], cur.se + max(sum[0][i], sum[1][i]));
			maximize(sum[1][p], sum[1][i] + cur.fi);
			
			maximize(sum[0][p], cur.fi + sum[0][i]);
		}
		
		
		if(M[i].se == 2) {
			
			maximize(sum[1][p], cur.se + sum[0][i]);
			maximize(sum[1][p], cur.fi + sum[1][i]);
			
			maximize(sum[0][p], cur.fi + sum[0][i]);
			
		}
	}
	
	cout << max(sum[1][0], sum[0][0]);
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}