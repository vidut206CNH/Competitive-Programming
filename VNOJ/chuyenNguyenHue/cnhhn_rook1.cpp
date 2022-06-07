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

const int MOD = 1000001;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

int t;
int m,n,k;
int lf[105];
int cnt[105];


void calc(int x, int val) {
	if(x == 1) return;
	int d = lf[x];
	while(x%d == 0) {
		cnt[d] += val;
		x /= d;
	}
	
	calc(x, val);
	
}

long long power(long long a, long long b) {
	long long res = 1;
	while(b) {
		if(b&1) res = res*a%MOD;
		a = a*a%MOD;
		b /= 2;
	}
	
	return res;
}

int main() {
	fast_cin();
	
	
	for(int i = 2; i <= 100; ++i) lf[i] = i;
	for(int i = 2; i*i <= 100; ++i) {
		if(lf[i] != i) continue;
		
		for(int j = i*i; j <= 100; j += i) lf[j] = min(lf[j], i);
	}
	
	
	
	cin >> t;
	while(t--) {
		memset(cnt, 0, sizeof cnt);
		cin >> m >> n >>  k;
		if(k > min(m,n)) {
			cout << 0 << "\n";
			continue;
		}
		
		long long res = 1;
		for(int i = m - k + 1; i <= m; ++i) res = 1LL*res*i%MOD;
		for(int i = 1; i <= n; ++i) {
			calc(i, +1);
		}
		
		for(int i = 1; i <= k; ++i) {
			calc(i, -1);
		}
		for(int i = 1; i <= n - k; ++i) {
			calc(i, -1);
		}
		
		for(int i = 1; i <= 100; ++i) {
			res = res*power(i + 0LL, cnt[i] + 0LL)%MOD;
		}
		
		cout << res << "\n";
	}
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}