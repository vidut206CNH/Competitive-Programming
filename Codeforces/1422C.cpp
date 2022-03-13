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

int n;
string s;
int f[MAXN1], suf[MAXN1];
int pf[MAXN1], psuf[MAXN1];
int p[MAXN1];

int power(int a, int b) {
	int res = 1;
	while(b) {
		if(b&1) res = (res * a)%MOD;
		a = (a*a)%MOD;
		b /= 2;
	}
	return res;
}

signed main() {
	fast_cin();
	
	cin >> s;
	n = sz(s);
	s = ' ' + s;
	
	for(int i = 1; i <= n; ++i) {
		int x = s[i] - '0';
		f[i] = (f[i - 1]*10 + x)%MOD;
	}
	suf[n] = psuf[n] = (s.back() - '0')%MOD;
	

	
	p[0] = 1;
	int mul = 1;
	for(int i = 1; i <= n; ++i) {
		p[i] = (p[i - 1] + (mul = (mul*10)%MOD))%MOD;
	}
	
	for(int i = n; i >= 1; --i) {
		int x = s[i] - '0';
		suf[i] = (x*power(10, n - i)%MOD + suf[i + 1])%MOD;
		psuf[i] = (suf[i] + psuf[i + 1])%MOD;

	}
	
	int sum1 = 0, res = 0;
	for(int i = 1; i <= n; ++i) {
		sum1 = (f[i - 1]%MOD*p[n - i]%MOD)%MOD;
		int sum2 = psuf[i + 1]%MOD;
		int sum = (sum1 + sum2)%MOD;
		res = (res + sum)%MOD;
	}
	
	cout << res;
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}