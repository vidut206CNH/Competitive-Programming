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
const int MAXN1 = 5e5+5;
const int MAXN2 = 1e6+5;

int n;
long long X,Y;
long long a[MAXN1];
long long f[MAXN1];
int minnf[MAXN1][24], minna[MAXN1][24];


int getf(int l, int r) {
	int k = log2(r - l + 1);
	int u = minnf[l + (1 << k) - 1][k];
	int v = minnf[r][k];
	if(f[u] < f[v]) return u;
	return v; 
}

int geta(int l, int r) {
	int k = log2(r - l + 1);
	int u = minna[l + (1 << k) - 1][k];
	int v = minna[r][k];
	if(a[u] < a[v]) return u;
	return v;
}

int main() {
	fast_cin();
/*	freopen("minimum.inp", "r", stdin);
	freopen("minimum.out", "w", stdout);*/
	cin >> n >> X >> Y;	
	
	
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[i] = a[i] + f[i - 1];
		minna[i][0] = minnf[i][0] = i;
	}
	
	a[0] = MOD;
	minna[0][0] = minnf[0][0] = 0;
	
	for(int j = 1; j <= 20; ++j) {
		for(int i = n; i >= 0; --i) {
			if(i - (1 << j) + 1 < 0) break;
			
			int u = minna[i][j - 1];
			int v = minna[i - (1 << (j - 1))][j - 1];
			
			if(a[u] < a[v]) {
				minna[i][j] = u;
			}
			
			else minna[i][j] = v;
			
			
			
			u = minnf[i][j - 1];
			v = minnf[i - (1 << (j - 1))][j - 1];
			
			if(f[u] < f[v]) {
				minnf[i][j] = u;
			}
			
			else minnf[i][j] = v;
		}
		
	}
	
	int resl = -1, resr = -1;
	long long best = -1e18;
	int L = 0, R = 0;
	
	for(int i = 1; i <= n; ++i) {
		while(L < i && a[geta(L + 1, i)] < X) ++L;
		while(R < i && a[geta(R + 1, i)] <= Y) ++R;
		--R;
		
/*		db(L);
		db(R);
		cerr << "\n";*/
		
		if(L < i) {
			int fl = getf(L, R);
			long long sum = f[i] - f[fl];
			
			if(sum > best) {
				best = sum;
				resl = fl + 1;
				resr = i;
			}
			
		}
	}
	
	cout << best << "\n" << resl << " " << resr;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}