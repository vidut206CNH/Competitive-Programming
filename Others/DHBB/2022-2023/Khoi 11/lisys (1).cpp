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
const long long MAXN1 = 5e6+5;
const int MAXN2 = 1e6+5;

int n;
int a[MAXN1];
long long P[MAXN1];


long long power(long long X, long long Y) {
	long long res = 1;
	
	while(Y) {
		if(Y&1) res = res*X%MOD;
		X = X*X%MOD;
		Y /= 2;
	}
	
	return res;
}

long long C(long long k, long long p) {
	if(k > p) return 0;
	if(k < 0 || p < 0) return 0;
	return P[p]*power(P[k], MOD - 2)%MOD*power(P[p - k], MOD - 2)%MOD;
}

int main() {
	fast_cin();
	
	
	P[0] = 1;
	for(int i = 1; i < MAXN1; ++i) P[i] = P[i - 1]*i%MOD;
	
	
	cin >> n;
	long long sum = 0, cnt = 0;
	
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(a[i] != -1) sum += a[i];
		else cnt++;
	}
	
	sum = 2LL*(n - 1) - sum;
	long long res = 0;
	
	for(int i = 0; i <= cnt; ++i) {
		
		long long s = sum - 1LL*i*(n - 1);
		long long tmp = 0;
		
		tmp = C(i, cnt)*C(cnt - 1, s - 1)%MOD;
		if(i&1) res = (res - tmp + MOD)%MOD;
		else res = (res + tmp)%MOD;
		
	}
	
	cout << res;
	
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}