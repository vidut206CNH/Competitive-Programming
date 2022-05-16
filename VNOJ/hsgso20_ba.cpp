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
		while(n > 0) {
			--n;
			C[n][n] = 1;
		}
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


int power(int A, int B) {
	int res = 1;
	while(B) {
		if(B&1) res = res*A%MOD;
		A = A*A%MOD;
		B /= 2; 
	}
	
	return res;
}

int C(int k, int n) {
	
	int res = 1;
	for(int i = n; i > n - k; --i) {
		res = res*i%MOD;
	}
	
	int d = 1;
	for(int i = 1; i <= k; ++i) {
		d = d*i%MOD;
	}
	return res*power(d, MOD - 2)%MOD;
}

int n, k, X;

signed main() {
	fast_cin();
	
	cin >> n >> k >> X;
	
	if(k == n) {
		cout << ((k*X)%3 == 0 ? 1 : 0);
		return 0;
	}
	
	int g = (3*3 - (k*X%3))%3;
	
	int num0 = 4 - (X%3 == 0);
	int num1 = 3 - (X%3 == 1);
	int num2 = 3 - (X%3 == 2);
	
	Matrix base({
		{num0, num2, num1},
		{num1, num0, num2},
		{num2, num1, num0}
	});
	
	Matrix a(3, 1);
	
	a[0][0] = 1; 
	
	Matrix ans(3, 1), pre(3, 1);
	Matrix base1(base.pow(n - k));
	
	ans = base.pow(n - k) * a;
	int res;
	
	if(X == 0) {
		pre = base.pow(n - k) * a;
		res = (ans[g][0]*C(k, n)%MOD - pre[g][0]*C(k - 1, n - 1)%MOD + MOD*MOD)%MOD;
		
	}
	
	else {
		pre = base.pow(n - k - 1) * a;
		res = (ans[g][0]*C(k,n)%MOD - pre[g][0]*C(k, n - 1)%MOD + MOD*MOD)%MOD;
	}
	
	//cout << ans[g][0]*C(k, n)%MOD;
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}