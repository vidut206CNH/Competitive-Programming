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

const int MOD = 998244353;
const int MAXN1 = 1e4+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

struct Matrix{
	vector<vector<int> > data;
	
	int row() const {return data.size(); }
	int col() const {return data[0].size(); }
	
	auto & operator[] (int i) {return data[i]; }
	const auto & operator[] (int i) const {return data[i]; }	
	
	Matrix(int r, int c) : data(r, vector<int> (c, 0)) {}
	
	Matrix(const vector<vector<int> > d) : data(d) {}
	
	
	static Matrix identity(int n) {
		Matrix c(n,n);
		while(n--) {
			c[n][n] = 1;
		}
		
		return c;
	}
	
	Matrix operator * (const Matrix& b) {
		Matrix a = *this;
		assert(a.col() == b.row());
		Matrix c(a.row(), b.col());
		
		
		for(int i = 0; i < a.row(); ++i) {
			for(int j = 0; j < b.col(); ++j) {
				for(int k = 0; k < a.col(); ++k) {
					c[i][j] = (a[i][k]*b[k][j] + c[i][j])%MOD;
				}
			}
		}
		
		return c;
		
	}
	
	
	Matrix pow(int exp) {
		Matrix base = *this;
		Matrix c = identity(base.row());
		
		for(; exp > 0; exp >>= 1, base = base * base) {
			if(exp & 1) c = c * base;
		}
		
		return c;
	}
};


int n,m;
int a[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) cin >> a[i];
	
	sort(a + 1, a + m + 1);
	
	Matrix res(4, 1);
	res[2][0] = 1;
	res[3][0] = 1;
	
	Matrix base({
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1},
		{0, 1, 1, 0}
	});
	
	int id = 1;
	while(id <= m && a[id] <= 3) {
		res[a[id]][0] = 0;
		++id;
	}
	
	int last = 3;
	
	for(;id <= m; ++id) {
/*		for(int i = 0; i < 4; ++i) db(res[i][0]);
		cerr << "\n";*/
		res = base.pow(a[id] - last) * res;
/*		for(int i = 0; i < 4; ++i) db(res[i][0]);
		cerr << "\n";*/
		res[3][0] = 0;
		last = a[id];	
	}
	
	//for(int i = 0; i < 4; ++i) db(res[i][0]);
	
	res = base.pow(n - last) * res;
	
	cout << res[3][0];
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}