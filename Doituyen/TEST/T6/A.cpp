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

long long ans = 0;
int a[3];

int C(int val) {
	int res = 0;
	if(val == 0) return 1;
	while(val) {
		res++;
		val /= 10;
	}
	
	return res;
}


long long power(long long A, long long B) {
	int res = 1;
	while(B) {
		if(B&1) res = res*A%MOD;
		A = A*A%MOD;
		B /= 2;
	}
	
	return res;
}

int main() {
	freopen("TSQ.INP", "r", stdin);
	freopen("TSQ.OUT", "w", stdout);
	fast_cin();
	
	for(int i = 0; i < 3; ++i) cin >> a[i];
	for(int i = 0; i < 3; ++i) {
		ans = ans*power(10, (C(a[i]))) + a[i];
	}
	
	long long d = sqrt(ans);
	cout << (d*d == ans ? "YES" : "NO");
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}