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
typedef vector<vector<int> > matrix;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,K;

matrix mul(matrix a, matrix b) {
	matrix res = vector< vector<int> > (n, vector<int>(n, 0));
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			for(int k = 0; k < n; ++k) {
				res[i][j] = res[i][j] + a[i][k]*b[k][j]; 
			}
		}
	}
	
	return res;
}


matrix pow(matrix a, int p) {
	matrix res = vector<vector<int> > (n, vector<int>(n));
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(i == j) res[i][j] = 1;
			else res[i][j] = 0;
		}
	}
	
	while(p) {
		if(p&1) res = mul(res, a);
		a = mul(a, a);
		p /= 2;
	}
	
	return res;
}

signed main() {
	fast_cin();
	
	cin >> n >> K;
	
	matrix a = vector<vector<int> > (n, vector<int>(n));
	for(int r = 0; r < n; ++ r) {
		for(int c = 0; c < n; ++c) {
			cin >> a[r][c];
		}
	}
	
	
	matr
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}