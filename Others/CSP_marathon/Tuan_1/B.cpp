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

const long long MOD = 1e9 + 7;
const int MAXN1 = 1e6+5;
const int MAXN2 = 1e6+5;

int n,m;
int pre[MAXN1];
int p[MAXN1];
int dep[MAXN1];
long long P[MAXN1];
long long f[MAXN1];


long long power(long long X, long long Y) {
	long long res = 1;
	while(Y) {
		if(Y&1) res = res*X%MOD;
		X = X*X%MOD;
		Y /= 2;
	}
	
	return res;
}

int main() {
	fast_cin();
	
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> p[i];
	
	// calc f[]
	
	P[0] = 1;
	P[1] = m - 1;
	for(int i = 2; i <= n; ++i) P[i] = P[i - 1]*(m - 1)%MOD;
	
	f[1] = 0;
	f[2] = m*P[1]%MOD;
	
	for(int i = 3; i <= n; ++i) {
		f[i] = (m*P[i - 1]%MOD - f[i - 1] + MOD*MOD)%MOD;
	}
	
	long long res = 1, cnt = 0;
	
	for(int i = 1; i <= n; ++i) {
		
		if(!pre[i]) {
			pre[i] = i;
			int u = i;
			dep[i] = 1;
			
			while(true) {
				
				if(pre[p[u]] == 0) {
					pre[p[u]] = i;
					dep[p[u]] = dep[u] + 1;
					u = p[u];
					
				}
				else if(pre[p[u]] == i) {
					res = res*f[dep[u] - dep[p[u]] + 1]%MOD;
					cnt += (dep[u] - dep[p[u]] + 1);
					break;
				}
				
				else {
					break;
				}
			}
		}
		
	}
	
	cout << res*P[n - cnt]%MOD;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}