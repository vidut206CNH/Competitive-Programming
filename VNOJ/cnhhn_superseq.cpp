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

const int MOD = 666013;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

struct Matrix {
	vector<vector<int> > data;
	
	int row() const {return data.size(); }
	int col() const {return data[0].size(); }
	
	auto & operator [] (int i) {return data[i]; }
	const auto & operator [] (int i) const { return data[i]; }
	
	Matrix() = default;
	
	Matrix(int r, int c) : data(r, vector<int> (c, 0)) { }
	
	
	
    Matrix(const vector <vector <int> > &d): data(d) { }
    
	
	static Matrix identity(int n) {
		Matrix C = Matrix(n, n);
		while(n--) C[n][n] = 1;
		return C;
	}
	
	Matrix operator *(const Matrix& B) {
		Matrix A = *this;
		
		
		assert(A.col() == B.row());
		
		
		Matrix C = Matrix(A.row(), B.col());
		
		for(int i = 0; i < A.row(); ++i) {
			for(int j = 0; j < B.col(); ++j) {
				for(int k = 0; k < A.col(); ++k) {
					C[i][j] = (C[i][j] + A[i][k]*B[k][j]%MOD)%MOD;
				}
			}
		}
		
		return C;
	}
	
	Matrix pow(int exp) {
		assert(row() == col());
		
		Matrix base = *this, ans = identity(row());
		
		for(; exp > 0; exp >>= 1, base = base * base) {
			if(exp & 1) ans = ans * base;
		}
		
		return ans;
	}
	
};


int n,H,K;

signed main() {
	fast_cin();
	
	cin >> n >> H >> K;
	
	Matrix base(H + 1, H + 1);
	
	for(int i = 0; i <= H; ++i) {
		
		for(int j = i; j <= min(H, i + K); ++j) {
			base[i][j] = 1;
		}
		
		for(int j = i; j >= max(0LL, i - K); --j) {
			base[i][j] = 1;
		}
		
	}
	
	Matrix res(H + 1, 1);
	res[0][0] = 1;
	
	
	res = base.pow(n - 1) * res;
	cout << res[H][0];
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}